cmake_minimum_required(VERSION 3.4...3.18)
project(py_cpp LANGUAGES CXX)

set(py_interp_path  ~/.conda/envs/research/)
find_package(pybind11 REQUIRED PATHS ${py_interp_path}/lib/python3.8/site-packages/pybind11/share/cmake/pybind11)

message(${pybind11_FOUND})
include_directories(
    ${pybind11_INCLUDE_DIRS}
    ${py_interp_path}/include/python3.8/
    include/)

pybind11_add_module(cpp_to_python test/cpp_to_python.cpp)

add_executable(call_py test/call_py.cpp)
target_link_libraries(call_py PRIVATE pybind11::embed)