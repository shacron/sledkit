#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include <stdio.h>

#include <sled/error.h>
#include <sled/machine.h>

static void pysled_machine_destroy(PyObject *o) {
    machine_destroy(PyCapsule_GetPointer(o, "machine_t"));
}

static PyObject * pysled_machine_create(PyObject *self, PyObject *args) {
    int err = 0;
    machine_t *m = NULL;
    if ((err = machine_create(&m))) {
        PyErr_SetString(PyExc_TypeError, st_err(err));
        return NULL;
    }
    return PyCapsule_New(m, "machine_t", pysled_machine_destroy);
}

static PyMethodDef pysled_methods[] = {
    { "machine_create",  pysled_machine_create, METH_VARARGS, "Create a machine." },
    { NULL, NULL, 0, NULL }        // end
};

static struct PyModuleDef pysledmodule = {
    PyModuleDef_HEAD_INIT,
    "sled", // name of module
    NULL,   // module documentation, may be NULL
    -1,     // size of per-interpreter state of the module, or -1 if the module keeps state in global variables.
    pysled_methods
};

PyMODINIT_FUNC PyInit_pysled(void) {
    return PyModule_Create(&pysledmodule);
}
