#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include "sdnoise1234.h"

static PyObject* sdnoise_sdnoise2(PyObject *self, PyObject *args)
{
    float x, y;

    if (!PyArg_ParseTuple(args, "ff", &x, &y))
        return NULL;

    float dx, dy;
    float n = sdnoise2(x, y, &dx, &dy);

    return Py_BuildValue("fff", n, dx, dy);
}

static PyMethodDef sdnoise_methods[] = {
    {"sdnoise2", sdnoise_sdnoise2, METH_VARARGS, "Calculate Simplex noise with gradients."},
    {NULL, NULL, 0, NULL}        /* Sentinel */
};

static struct PyModuleDef sdnoise_module = {
    PyModuleDef_HEAD_INIT,
    "sdnoise",   /* name of module */
    NULL, /* module documentation, may be NULL */
    -1,       /* size of per-interpreter state of the module,
                 or -1 if the module keeps state in global variables. */
    sdnoise_methods
};

PyMODINIT_FUNC PyInit_sdnoise(void)
{
    return PyModule_Create(&sdnoise_module);
}
