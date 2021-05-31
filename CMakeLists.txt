cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(Datastructures)


set(LIBRARY_NAME "DSAndAlgo")
set(TEST_SUITE ${LIBRARY_NAME}_test_suite)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_subdirectory(src)
add_subdirectory(test)


