#include "cpp_to_python.hpp"
#include <vector>

using namespace std;


PYBIND11_MODULE(cpp_to_python, m) {
    m.doc() = "A data converter assumed to carry any data array"; // optional module docstring
    py::class_<cpp_to_python::Loader<double>>(m, "Loader")
        .def(py::init<>())
        .def("get", &cpp_to_python::Loader<double>::get);
}
