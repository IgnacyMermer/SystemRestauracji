project(tests)
add_subdirectory(lib)

add_executable(tests_run data_tests.cpp)
add_executable(tests_run1 meal_tests.cpp)
add_executable(tests_run2 order_tests.cpp)
add_executable(tests_run3 client_tests.cpp)
add_executable(tests_run4 employee_tests.cpp)
add_executable(tests_run5 restaurant_tests.cpp)
enable_testing()

target_link_libraries(tests_run projektPROI2_data curlpp)
target_link_libraries(tests_run gtest gtest_main)

target_link_libraries(tests_run1 projektPROI2_meal curlpp)
target_link_libraries(tests_run1 gtest gtest_main)

target_link_libraries(tests_run2 projektPROI2_order projektPROI2_meal curlpp)
target_link_libraries(tests_run2 gtest gtest_main)

target_link_libraries(tests_run3 projektPROI2_client curlpp)
target_link_libraries(tests_run3 gtest gtest_main)

target_link_libraries(tests_run4 projektPROI2_employee projektPROI2_data curlpp)
target_link_libraries(tests_run4 gtest gtest_main)

target_link_libraries(tests_run5 projektPROI2_employee projektPROI2_client projektPROI2_order projektPROI2_meal curlpp)
target_link_libraries(tests_run5 gtest gtest_main)

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

add_test ( ClientTest1, tests_run3 )
add_test ( ClientTest2, tests_run3 )
add_test ( ClientTest3, tests_run3 )

add_test ( TaskTest1, tests_run4 )
add_test ( TaskTest2, tests_run4 )
add_test ( TaskTest3, tests_run4 )
add_test ( TaskTest4, tests_run4 )
add_test ( TaskTest5, tests_run4 )

add_test ( EmployeeTest1, tests_run4 )
add_test ( EmployeeTest2, tests_run4 )
add_test ( EmployeeTest3, tests_run4 )

add_test ( CookTest1, tests_run4 )
add_test ( CookTest2, tests_run4 )

add_test ( ChefTest1, tests_run4 )

add_test ( exceptionTest1, tests_run4 )
add_test ( exceptionTest2, tests_run4 )

add_test ( JanitorTest1, tests_run4 )
add_test ( JanitorTest2, tests_run4 )

add_test ( SupplierTest1, tests_run4 )
add_test ( SupplierTest2, tests_run4 )

add_test ( RestaurantTest1, tests_run5 )
add_test ( RestaurantTest2, tests_run5 )
add_test ( RestaurantTest3, tests_run5 )
add_test ( RestaurantTest4, tests_run5 )
add_test ( RestaurantTest5, tests_run5 )
add_test ( RestaurantTest6, tests_run5 )
add_test ( RestaurantTest7, tests_run5 )
add_test ( RestaurantTest8, tests_run5 )
add_test ( RestaurantTest9, tests_run5 )
add_test ( RestaurantTest10, tests_run5 )
add_test ( RestaurantTest11, tests_run5 )
add_test ( RestaurantTest12, tests_run5 )
add_test ( RestaurantTest13, tests_run5 )