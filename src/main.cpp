#include <pybind11/pybind11.h>

#define STRINGIFY(x) #x

#define MACRO_STRINGIFY(x) STRINGIFY(x) 
namespace py = pybind11;
void add(int i, int j) {
	throw py::value_error("some exception");
    i + j*2;
}


PYBIND11_MODULE(python_example, m) {
    m.doc() = R"pbdoc(
        Pybind11 example plugin
        -----------------------

        .. currentmodule:: python_example

        .. autosummary::  
           :toctree: _generate

           add
           subtract
    )pbdoc";    
       
    m.def("add", &add, R"pbdoc(
        Add two numbers

        Some other explanation about the add function.
    )pbdoc");

    m.def("subtract", [](int i, int j) { return i - j; }, R"pbdoc(
        Subtract two numbers

        Some other explanation about the subtract function.
    )pbdoc");

#ifdef VERSION_INFO
    m.attr("__version__") = MACRO_STRINGIFY(VERSION_INFO);
#else
    m.attr("__version__") = "dev";
#endif
}
