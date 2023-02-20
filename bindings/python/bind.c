#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include <stdio.h>

#include <sled/elf.h>
#include <sled/error.h>
#include <sled/machine.h>

typedef struct {
    PyObject_HEAD
    machine_t *m;
} MachineObject;

static PyObject *psled_machine_new(PyTypeObject *type, PyObject *args, PyObject *kwds) {
    MachineObject *self;
    self = (MachineObject *)type->tp_alloc(type, 0);
    if (self == NULL) return NULL;

    int err = machine_create(&self->m);
    if (err) {
        PyErr_SetString(PyExc_TypeError, st_err(err));
        Py_TYPE(self)->tp_free((PyObject *)self);
        return NULL;
    }
    return (PyObject *)self;
}

static void psled_machine_dealloc(MachineObject *self) {
    machine_destroy(self->m);
    Py_TYPE(self)->tp_free((PyObject *)self);
}

static PyObject *psled_machine_add_mem(MachineObject *self, PyObject *args) {
    uint64_t base, size;

    if (!PyArg_ParseTuple(args, "LL", &base, &size)) {
        PyErr_SetString(PyExc_TypeError, "base and size arguments required");
        return NULL;
    }
    int err = machine_add_mem(self->m, base, size);
    if (err) {
        PyErr_SetString(PyExc_TypeError, st_err(err));
        return NULL;
    }
    Py_RETURN_NONE;
}

static PyObject *psled_machine_add_device(MachineObject *self, PyObject *args) {
    uint32_t type;
    uint64_t base;
    char *name;

    if (!PyArg_ParseTuple(args, "ILs", &type, &base, &name)) {
        PyErr_SetString(PyExc_TypeError, "type, base, and name arguments required");
        return NULL;
    }

    int err = machine_add_device(self->m, type, base, name);
    if (err) {
        PyErr_SetString(PyExc_TypeError, st_err(err));
        return NULL;
    }
    Py_RETURN_NONE;
}

static PyObject *psled_machine_add_core(MachineObject *self, PyObject *args) {
    core_params_t params = {};
    if (!PyArg_ParseTuple(args, "bbI", &params.arch, &params.subarch, &params.options, &params.arch_options)) {
        PyErr_SetString(PyExc_TypeError, "arch, subarch, options, and arch_options arguments required");
        return NULL;
    }

    int err = machine_add_core(self->m, &params);
    if (err) {
        PyErr_SetString(PyExc_TypeError, st_err(err));
        return NULL;
    }

    return PyLong_FromUnsignedLong(params.id);
}

static PyObject *psled_machine_load_core(MachineObject *self, PyObject *args) {
    uint32_t id;
    char *filename;

    if (!PyArg_ParseTuple(args, "Is", &id, &filename)) {
        PyErr_SetString(PyExc_TypeError, "core_id and filename arguments required");
        return NULL;
    }

    int err;
    elf_object_t *eo = NULL;
    if ((err = elf_open(filename, &eo))) {
        PyErr_SetString(PyExc_TypeError, "failed to open file");
        return NULL;
    }

    err = machine_load_core(self->m, id, eo, true);
    elf_close(eo);
    if (err) {
        PyErr_SetString(PyExc_TypeError, st_err(err));
        return NULL;
    }

    Py_RETURN_NONE;
}


static PyMethodDef psled_machine_methods[] = {
    {
        "add_mem",
        (PyCFunction)psled_machine_add_mem,
        METH_VARARGS,
        "Add memory to machine"
    },
    {
        "add_dev",
        (PyCFunction)psled_machine_add_device,
        METH_VARARGS,
        "Add device to machine"
    },
    {
        "add_core",
        (PyCFunction)psled_machine_add_core,
        METH_VARARGS,
        "Add core to machine"
    },
    {
        "load_core",
        (PyCFunction)psled_machine_load_core,
        METH_VARARGS,
        "Load a file into core memory"
    },
    { NULL }  // Sentinel
};

static PyTypeObject MachineType = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "psled.machine",
    .tp_doc = PyDoc_STR("Sled Machine"),
    .tp_basicsize = sizeof(MachineObject),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,
    .tp_new = psled_machine_new,
    .tp_dealloc = (destructor)psled_machine_dealloc,
    .tp_methods = psled_machine_methods,
};

static struct PyModuleDef psledmodule = {
    PyModuleDef_HEAD_INIT,
    .m_name = "psled", // name of module
    .m_doc = NULL,     // module documentation, may be NULL
    .m_size = -1,      // size of per-interpreter state of the module, or -1 if the module keeps state in global variables.
};

PyMODINIT_FUNC PyInit_psled(void) {
    PyObject *m;
    if (PyType_Ready(&MachineType) < 0)
        return NULL;

    m = PyModule_Create(&psledmodule);
    if (m == NULL) return NULL;

    Py_INCREF(&MachineType);
    if (PyModule_AddObject(m, "machine", (PyObject *) &MachineType) < 0) {
        Py_DECREF(&MachineType);
        Py_DECREF(m);
        return NULL;
    }

    return m;
}
