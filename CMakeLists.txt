cmake_minimum_required(VERSION 3.27)
project(Aizo_1)

set(CMAKE_CXX_STANDARD 17)

add_executable(Aizo_1 main.cpp
        Menu.cpp
        Menu.h
        IntSorting.cpp
        IntSorting.h
        badania.cpp
        badania.h
        Generator.cpp
        Generator.h
        FloatSorting.cpp
        FloatSorting.h
        DoubleSorting.cpp
        DoubleSorting.h
)
