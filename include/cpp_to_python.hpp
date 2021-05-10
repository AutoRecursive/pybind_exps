#pragma once

#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>

#include <vector>

namespace py = pybind11;

namespace cpp_to_python{
    
    void callback(std::vector<double>& cpp_array, std::vector<int>& dimensions) {
        std::vector<double> data = {1, 2, 3, 4, 5};

        for (auto d : data) {
            cpp_array.push_back(d);
        }
        dimensions.push_back(data.size());
    }

    template<class Type>
    class Loader
    {
    public:
        Loader(){
            callback(data, dims);
        }
        ~Loader() {}

        py::object get() {
            return py::array_t<Type, py::array::c_style>(dims, data.data());

    }
    private:
        std::vector<Type> data;
        std::vector<int> dims;
    };

}
