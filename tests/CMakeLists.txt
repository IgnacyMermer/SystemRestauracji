project(tests)
add_subdirectory(lib)

add_executable(tests_run tests.cpp)

target_link_libraries(tests_run projektPROI2_meal)
target_link_libraries(tests_run gtest gtest_main)