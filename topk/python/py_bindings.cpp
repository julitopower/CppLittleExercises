#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include "topk.hpp"

////////////////////////////////////////////////////////////////////////////////
// Python functions that are getting wrapped
////////////////////////////////////////////////////////////////////////////////

/**
 * Topk functionality in Pythonland
 */
static PyObject *
topk_fn(PyObject *, PyObject *args) {
  // Parse the arguments
  // Args are a list and the K number of elements to retrieve
  PyObject *pList;
  std::size_t k;
  if (!PyArg_ParseTuple(args, "O!l", &PyList_Type, &pList, &k)) {
    PyErr_SetString(PyExc_TypeError, "parameter must be a list.");
    return NULL;
  }

  // Get the values from a list into a std::vector
  PyObject *pItem;
  Py_ssize_t n = PyList_Size(pList);
  std::vector<int> data(n,0);
  for (auto i = 0U;  i < n ; i++) {
    pItem = PyList_GetItem(pList, i);
    if(!PyLong_Check(pItem)) {
      PyErr_SetString(PyExc_TypeError, "list items must be integers.");
      return NULL;
    }
    data.push_back(PyLong_AsLong(pItem));
  }

  // Initialize the TopK class and obtain topk elements
  auto topk_provider = topk::buildTopK(data.begin(), data.end(), [](auto a) { return -a; });
  auto topk_result = topk_provider.topkmem(k);

  // Build return list
  auto pTopKList = PyList_New(0);
  for (auto elem : topk_result) {
    auto pElem = PyLong_FromLong(elem);
    PyList_Append(pTopKList, pElem);
    Py_DecRef(pElem);
  }

  // Return list
  return pTopKList;
}
////////////////////////////////////////////////////////////////////////////////

PyMethodDef method_table[] = {
  {"topk", reinterpret_cast<PyCFunction>(topk_fn), METH_VARARGS, "Function documentation"},
  {NULL, NULL, 0, NULL} // Sentinel value ending the table
};

PyModuleDef py_module =
    {
        PyModuleDef_HEAD_INIT,
        "topk",
        "Module docstring",
        -1, // Optional size of module state memory
        method_table,
        NULL, // Optional slot definitions
        NULL, // Optional traversal function
        NULL, // Optional clear function
        NULL  // Optional module deallocation function
    };

PyMODINIT_FUNC
PyInit_topk(void) {
  return PyModule_Create(&py_module);
}
