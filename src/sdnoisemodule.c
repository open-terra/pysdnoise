#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include "sdnoise1234.h"

static PyObject* sdnoise_snoise1(PyObject *self, PyObject *args)
{
    float x;

    if (!PyArg_ParseTuple(args, "f", &x))
        return NULL;

    float dx;
    float n = sdnoise1(x, &dx);

    return Py_BuildValue("ff", n, dx);
}

static PyObject* sdnoise_snoise2(PyObject *self, PyObject *args)
{
    float x, y;

    if (!PyArg_ParseTuple(args, "ff", &x, &y))
        return NULL;

    float dx, dy;
    float n = sdnoise2(x, y, &dx, &dy);

    return Py_BuildValue("fff", n, dx, dy);
}

static PyObject* sdnoise_snoise3(PyObject *self, PyObject *args)
{
    float x, y, z;

    if (!PyArg_ParseTuple(args, "fff", &x, &y, &z))
        return NULL;

    float dx, dy, dz;
    float n = sdnoise3(x, y, z, &dx, &dy, &dz);

    return Py_BuildValue("ffff", n, dx, dy, dz);
}

static PyObject* sdnoise_snoise4(PyObject *self, PyObject *args)
{
    float x, y, z, w;

    if (!PyArg_ParseTuple(args, "ffff", &x, &y, &z, &w))
        return NULL;

    float dx, dy, dz, dw;
    float n = sdnoise4(x, y, z, w, &dx, &dy, &dz, &dw);

    return Py_BuildValue("fffff", n, dx, dy, dz, dw);
}

static PyMethodDef sdnoise_methods[] = {
    {"snoise1", sdnoise_snoise1, METH_VARARGS, "Calculate Simplex 1D noise with gradients."},
    {"snoise2", sdnoise_snoise2, METH_VARARGS, "Calculate Simplex 2D noise with gradients."},
    {"snoise3", sdnoise_snoise3, METH_VARARGS, "Calculate Simplex 3D noise with gradients."},
    {"snoise4", sdnoise_snoise4, METH_VARARGS, "Calculate Simplex 4D noise with gradients."},
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
