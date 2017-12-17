cmake_minimum_required(VERSION 3.8)
project (CppExamples)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_OSX_ARCHITECTURES "x86_64")

add_subdirectory(1.HelloWorld)
add_subdirectory(2.OOP)
add_subdirectory(3.Building)
#add_subdirectory(4.DynStructures)
