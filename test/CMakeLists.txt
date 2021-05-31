find_package(Threads REQUIRED)

file(GLOB_RECURSE TESTS *.cpp *.cc *.h)

include_directories(
        SYSTEM
        ${GMOCK_INCLUDE_DIRS})

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}../src
        ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(${TEST_SUITE}
        ${TESTS})

target_link_libraries(${TEST_SUITE}
        ${LIBRARY_NAME}
        ${GMOCK_BOTH_LIBRARIES}
        ${CMAKE_THREAD_LIBS_INIT})

install(TARGETS ${TEST_SUITE} DESTINATION bin)