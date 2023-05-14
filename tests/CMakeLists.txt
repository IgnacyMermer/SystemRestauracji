project(tests)
add_subdirectory(lib)

add_executable(tests_run tests.cpp)
enable_testing()

target_link_libraries(tests_run projektPROI2_meal)
target_link_libraries(tests_run gtest gtest_main)
add_test( tests_run tests_run )