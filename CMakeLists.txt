cmake_minimum_required(VERSION 3.5)
project(Hopfield)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ")

set(SOURCE_FILES main.c Neuron.h Neuron.c Network.h Network.c)
add_executable(Hopfield ${SOURCE_FILES})