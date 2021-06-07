cmake_minimum_required(VERSION 3.8)
project(LR2)

add_executable(test.out main.cpp templates.cpp src/complex.cpp src/vector.cpp src/sequence.cpp src/dynamicarray_sequence.cpp src/dynamicarray.cpp tests/matrix_test.cpp tests/vector_time_test.cpp tests/vector_test.cpp tests/dynamicarray_test.cpp tests/sequence_test.cpp src/linkedlist.cpp tests/linkedlist_test.cpp)

target_link_libraries(test.out)