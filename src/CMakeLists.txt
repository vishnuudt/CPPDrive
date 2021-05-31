
# Find all source and header files (note: we are using .cc for cpp source).
file(GLOB_RECURSE SOURCES *.cpp *.cc)
file(GLOB_RECURSE HEADERS *.h)

set(${PROJECT_NAME}_SOURCES
    ${HEADERS} ${SOURCES})

add_library(${LIBRARY_NAME} SHARED
        ${${PROJECT_NAME}_SOURCES})

message(STATUS "Sqlite ${SQLITE3_LIBRARIES} at ${SQLITE3_INCLUDE_DIRS}")
message(STATUS "Boost TnS ${Boost_INCLUDE_DIRS} ${Boost_LIBRARIES}")

target_include_directories(${LIBRARY_NAME}
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${Boost_INCLUDE_DIRS}
        )

target_link_libraries(${LIBRARY_NAME}
		${Boost_LIBRARIES})

install(DIRECTORY include DESTINATION . FILES_MATCHING PATTERN "*.h")
install(TARGETS ${LIBRARY_NAME} DESTINATION lib)