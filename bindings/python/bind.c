#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include <stdio.h>

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

static PyMethodDef psled_machine_methods[] = {
    {
        "add_mem",
        (PyCFunction)psled_machine_add_mem,
        METH_VARARGS,
        "Add memory to machine"
    },
    { NULL }  /* Sentinel */
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

// static PyObject * psled_machine_create(PyObject *self, PyObject *args) {
//     // int err = 0;
//     // machine_t *m = NULL;
//     // if ((err = machine_create(&m))) {
//     //     PyErr_SetString(PyExc_TypeError, st_err(err));
//     //     return NULL;
//     // }
//     // return PyCapsule_New(m, "machine_t", psled_machine_destroy);
// }

// static PyMethodDef psled_methods[] = {
//     { "machine_create",  psled_machine_create, METH_VARARGS, "Create a machine." },
//     { NULL, NULL, 0, NULL }        // end
// };

static struct PyModuleDef psledmodule = {
    PyModuleDef_HEAD_INIT,
    .m_name = "sled", // name of module
    .m_doc = NULL,   // module documentation, may be NULL
    .m_size = -1,     // size of per-interpreter state of the module, or -1 if the module keeps state in global variables.
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
