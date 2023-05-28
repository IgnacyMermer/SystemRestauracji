project(tests)
add_subdirectory(lib)

add_executable(tests_run tests.cpp)
add_executable(tests_run1 meal_tests.cpp)
add_executable(tests_run2 order_tests.cpp)
enable_testing()

target_link_libraries(tests_run projektPROI2_data curlpp)
target_link_libraries(tests_run gtest gtest_main)

target_link_libraries(tests_run1 projektPROI2_meal curlpp)
target_link_libraries(tests_run1 gtest gtest_main)

target_link_libraries(tests_run2 projektPROI2_order projektPROI2_meal curlpp)
target_link_libraries(tests_run2 gtest gtest_main)

add_test( LoginTest, tests_run)

add_test( MealTest1, tests_run1 ) 
add_test( MealTest2, tests_run1 )
add_test( MealTest3, tests_run1 )
add_test( MealTest4, tests_run1 )
add_test( MealTest5, tests_run1 )
add_test( MealTest6, tests_run1 )
add_test( MealTest7, tests_run1 )

add_test ( IngredientTest1, tests_run1 )
add_test ( IngredientTest2, tests_run1 )
add_test ( IngredientTest3, tests_run1 )
add_test ( IngredientTest4, tests_run1 )
add_test ( IngredientTest5, tests_run1 )
add_test ( IngredientTest6, tests_run1 )

add_test ( OrderTest1, tests_run2 )
add_test ( OrderTest2, tests_run2 )
add_test ( OrderTest3, tests_run2 )
add_test ( OrderTest4, tests_run2 )
add_test ( OrderTest5, tests_run2 )
add_test ( OrderTest6, tests_run2 )
