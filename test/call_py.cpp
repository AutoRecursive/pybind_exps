#include <iostream>
#include <string>
#include <pybind11/embed.h>
#include <pybind11/stl.h>

#include <vector>
namespace py = pybind11;
using namespace std;
int main() {
    py::scoped_interpreter guard{};

    auto sys = py::module::import("sys");
    sys.attr("path").attr("insert")(1, "/home/linjun/Programs/research/Robotics/py_cpp/test");

    py::function p = py::module_::import("script").attr("p");

    vector<double> xs = {1, 2};
    vector<double> ys = {3, 4};
    py::list xsl = py::cast(xs);
    py::list ysl = py::cast(ys);
    p(xsl, ysl);
    return 0;
}