cmake_minimum_required(VERSION 3.9)
project(AbstractVM)

set(CMAKE_CXX_STANDARD 11)

add_executable(AbstractVM
        inc/IOperand.hpp
        inc/Operand.hpp
        inc/OperandFactory.hpp
        inc/Parser.hpp
        inc/VM.hpp
        src/main.cpp
        src/OperandFactory.cpp
        src/Parser.cpp
        src/VM.cpp)
