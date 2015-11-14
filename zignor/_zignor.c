#include <Python.h>
#include <numpy/arrayobject.h>
#include <math.h>
#include <stdlib.h>

#include "zigrandom.c"
#include "zignor.c"

#include "gauss.c"


static PyObject* _gauss_randn(PyObject *self, PyObject *args)
{
    PyArrayObject *py_mat;
    double *mat;
    npy_intp dims[1] = { 0 };
    int n, i;
    int piseed, cseed;
    if (!PyArg_ParseTuple(args, "iii", &n, &piseed, &cseed))
        return NULL;

    dims[0] = n;
    py_mat = (PyArrayObject *)PyArray_SimpleNew(1, dims, NPY_DOUBLE);
    mat = (double *)py_mat->data;

    xorshift128_set(piseed, cseed, 0, 0);
    for (i = 0; i < n; ++i)
        mat[i] = (double)gsl_ran_gaussian_ziggurat();

    return PyArray_Return(py_mat);
}

static PyObject* _zignor_randn(PyObject *self, PyObject *args)
{
    PyArrayObject *py_mat;
    double *mat;
    npy_intp dims[1] = { 0 };
    int n, i;
    int piseed, cseed;
    if (!PyArg_ParseTuple(args, "iii", &n, &piseed, &cseed))
        return NULL;

    dims[0] = n;
    py_mat = (PyArrayObject *)PyArray_SimpleNew(1, dims, NPY_DOUBLE);
    mat = (double *)py_mat->data;
    RanNormalSetSeedZig32(&piseed, cseed);
    for (i = 0; i < n; ++i)
        mat[i] = (double)DRanNormalZig32();

    return PyArray_Return(py_mat);
}

static PyMethodDef _zignor_methods[] =
{
    {
        "randn", _gauss_randn, METH_VARARGS
    },
    {
        "rnor", _gauss_randn, METH_VARARGS
    },
    {
        "zignor", _zignor_randn, METH_VARARGS
    },
    {
        NULL, NULL
    },
};

#if PY_MAJOR_VERSION >= 3
struct PyModuleDef module_def = {
    PyModuleDef_HEAD_INIT,
    "_zignor",
    NULL,
    -1,
    _zignor_methods,
    NULL, NULL, NULL, NULL
};
#endif

#if PY_MAJOR_VERSION >= 3
PyMODINIT_FUNC PyInit__zignor(void)
{
    import_array();
    return PyModule_Create(&module_def);
}
#else
PyMODINIT_FUNC init_zignor(void)
{
    import_array();
    (void)Py_InitModule("_zignor", _zignor_methods);
}
#endif

