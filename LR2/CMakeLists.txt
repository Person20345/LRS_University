cmake_minimum_required(VERSION 3.8)
project(LR2)

add_executable(test.out main.cpp templates.cpp src/dynamicarray_sequence.cpp src/dynamicarray.cpp tests/dynamicarray_test.cpp tests/sequence_test.cpp src/linkedlist.cpp tests/linkedlist_test.cpp)

target_link_libraries(test.out)