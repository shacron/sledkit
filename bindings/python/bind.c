// SPDX-License-Identifier: MIT License
// Copyright (c) 2022-2023 Shac Ron and The Sled Project

#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include <stdio.h>

#include <sled/elf.h>
#include <sled/error.h>
#include <sled/machine.h>

#define MAX_CORES 16

typedef struct {
    PyObject_HEAD
    uint32_t id;
    core_t *c;
} CoreObject;

typedef struct {
    PyObject_HEAD
    sl_machine_t *m;
    CoreObject *core[MAX_CORES];
} MachineObject;

CoreObject * psled_core_new_internal(core_t *c, uint32_t id);

static PyObject *psled_core_step(CoreObject *self, PyObject *args) {
    uint32_t steps = 1;

    if (!PyArg_ParseTuple(args, "L", &steps)) {
        PyErr_SetString(PyExc_TypeError, "invalid step count");
        return NULL;
    }
    int err = sl_core_step(self->c, steps);
    if (err) {
        PyErr_SetString(PyExc_TypeError, st_err(err));
        return NULL;
    }
    Py_RETURN_NONE;
}

static PyObject *psled_sl_machine_new(PyTypeObject *type, PyObject *args, PyObject *kwds) {
    MachineObject *self;
    self = (MachineObject *)type->tp_alloc(type, 0);
    if (self == NULL) return NULL;

    int err = sl_machine_create(&self->m);
    if (err) {
        PyErr_SetString(PyExc_TypeError, st_err(err));
        Py_TYPE(self)->tp_free((PyObject *)self);
        return NULL;
    }
    for (int i = 0; i < MAX_CORES; i++) self->core[i] = NULL;
    return (PyObject *)self;
}

static void psled_sl_machine_dealloc(MachineObject *self) {
    for (int i = 0; i < MAX_CORES; i++) {
        CoreObject *c = self->core[i];
        if (c == NULL) continue;
        Py_DECREF(c);
    }
    sl_machine_destroy(self->m);
    Py_TYPE(self)->tp_free((PyObject *)self);
}

static PyObject *psled_sl_machine_add_mem(MachineObject *self, PyObject *args) {
    uint64_t base, size;

    if (!PyArg_ParseTuple(args, "LL", &base, &size)) {
        PyErr_SetString(PyExc_TypeError, "base and size arguments required");
        return NULL;
    }
    int err = sl_machine_add_mem(self->m, base, size);
    if (err) {
        PyErr_SetString(PyExc_TypeError, st_err(err));
        return NULL;
    }
    Py_RETURN_NONE;
}

static PyObject *psled_sl_machine_add_device(MachineObject *self, PyObject *args) {
    uint32_t type;
    uint64_t base;
    char *name;

    if (!PyArg_ParseTuple(args, "ILs", &type, &base, &name)) {
        PyErr_SetString(PyExc_TypeError, "type, base, and name arguments required");
        return NULL;
    }

    int err = sl_machine_add_device(self->m, type, base, name);
    if (err) {
        PyErr_SetString(PyExc_TypeError, st_err(err));
        return NULL;
    }
    Py_RETURN_NONE;
}

static PyObject *psled_sl_machine_add_core(MachineObject *self, PyObject *args) {
    sl_core_params_t params = {};
    if (!PyArg_ParseTuple(args, "bbII", &params.arch, &params.subarch, &params.options, &params.arch_options)) {
        PyErr_SetString(PyExc_TypeError, "arch, subarch, options, and arch_options arguments required");
        return NULL;
    }

    int err = sl_machine_add_core(self->m, &params);
    if (err) {
        PyErr_SetString(PyExc_TypeError, st_err(err));
        return NULL;
    }

    return PyLong_FromUnsignedLong(params.id);
}

static PyObject *psled_sl_machine_load_core(MachineObject *self, PyObject *args) {
    uint32_t id;
    char *filename;

    if (!PyArg_ParseTuple(args, "Is", &id, &filename)) {
        PyErr_SetString(PyExc_TypeError, "core_id and filename arguments required");
        return NULL;
    }

    int err;
    sl_elf_obj_t *eo = NULL;
    if ((err = sl_elf_open(filename, &eo))) {
        PyErr_SetString(PyExc_TypeError, "failed to open file");
        return NULL;
    }

    err = sl_machine_load_core(self->m, id, eo, true);
    sl_elf_close(eo);
    if (err) {
        PyErr_SetString(PyExc_TypeError, st_err(err));
        return NULL;
    }

    Py_RETURN_NONE;
}

static PyObject *psled_sl_machine_get_core(MachineObject *self, PyObject *args) {
    uint32_t id;
    if (!PyArg_ParseTuple(args, "I", &id)) {
        PyErr_SetString(PyExc_TypeError, "core_id argument required");
        return NULL;
    }

    CoreObject *c = NULL;
    int i;
    for (i = 0; i < MAX_CORES; i++) {
        if (self->core[i] == NULL) break;
        if (self->core[i]->id == id) {
            c = self->core[i];
            break;
        }
    }

    if (i == MAX_CORES) {
        PyErr_SetString(PyExc_TypeError, "core limit exceeded");
        return NULL;
    }

    if (c == NULL) {
        core_t *core = sl_machine_get_core(self->m, id);
        if (core == NULL) {
            PyErr_SetString(PyExc_TypeError, "core not found");
            return NULL;
        }

        c = psled_core_new_internal(core, id);
        if (c == NULL) {
            PyErr_SetString(PyExc_TypeError, "failed to allocate core");
            return NULL;
        }
        Py_INCREF(c);
        for (i = 0; i < MAX_CORES; i++) {
            if (self->core[i] == NULL) {
                self->core[i] = c;
                break;
            }
        }
    }
    return (PyObject *)c;
}

static PyMethodDef psled_sl_machine_methods[] = {
    {
        "add_mem",
        (PyCFunction)psled_sl_machine_add_mem,
        METH_VARARGS,
        "Add memory to machine"
    },
    {
        "add_dev",
        (PyCFunction)psled_sl_machine_add_device,
        METH_VARARGS,
        "Add device to machine"
    },
    {
        "add_core",
        (PyCFunction)psled_sl_machine_add_core,
        METH_VARARGS,
        "Add core to machine"
    },
    {
        "get_core",
        (PyCFunction)psled_sl_machine_get_core,
        METH_VARARGS,
        "Get core by id"
    },
    {
        "load_core",
        (PyCFunction)psled_sl_machine_load_core,
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
    .tp_new = psled_sl_machine_new,
    .tp_dealloc = (destructor)psled_sl_machine_dealloc,
    .tp_methods = psled_sl_machine_methods,
};

static PyMethodDef psled_core_methods[] = {
    {
        "step",
        (PyCFunction)psled_core_step,
        METH_VARARGS,
        "Step one or more instructions"
    },
    { NULL }  // Sentinel
};

static PyTypeObject CoreType = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "psled.core",
    .tp_doc = PyDoc_STR("Sled Core"),
    .tp_basicsize = sizeof(CoreObject),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,
    .tp_methods = psled_core_methods,
};

CoreObject * psled_core_new_internal(core_t *c, uint32_t id) {
    CoreObject *self;
    self = (CoreObject *)CoreType.tp_alloc(&CoreType, 0);
    if (self == NULL) return NULL;
    self->id = id;
    self->c = c;
    return self;
}


static struct PyModuleDef psledmodule = {
    PyModuleDef_HEAD_INIT,
    .m_name = "psled", // name of module
    .m_doc = NULL,     // module documentation, may be NULL
    .m_size = -1,      // size of per-interpreter state of the module, or -1 if the module keeps state in global variables.
};

static int add_object(PyObject *module, PyTypeObject *obj_type, const char *name) {
    if (PyType_Ready(obj_type) < 0) return -1;
    Py_INCREF(obj_type);
    if (PyModule_AddObject(module, name, (PyObject *)obj_type) < 0) {
        Py_DECREF(obj_type);
        return -1;
    }
    return 0;
}

PyMODINIT_FUNC PyInit_psled(void) {
    PyObject *m = PyModule_Create(&psledmodule);
    if (m == NULL) return NULL;

    int err;
    if ((err = add_object(m, &MachineType, "machine"))) goto add_failure_0;
    if ((err = add_object(m, &CoreType, "core"))) goto add_failure_1;
    return m;

add_failure_1:
    Py_DECREF(&MachineType);
add_failure_0:
    Py_DECREF(m);
    return NULL;
}
