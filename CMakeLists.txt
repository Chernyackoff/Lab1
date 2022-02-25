cmake_minimum_required(VERSION 3.21)
project(Lab1)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lab1 main.cpp Queue.cpp Queue.hpp PublicQueue.cpp PublicQueue.hpp ProtectedQueue.cpp ProtectedQueue.hpp
        PrivateQueue.cpp PrivateQueue.hpp)
