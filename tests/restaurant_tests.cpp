#include "gtest/gtest.h"
#include "../Restaurant.h"
#include "../Restaurant.cpp"

TEST(RestaurantTest1, Constructor) {
    Restaurant restaurant;
    EXPECT_EQ(restaurant.name, "Restauracja ...");
    EXPECT_EQ(restaurant.open, true);
}

TEST(RestaurantTest2, setOpen) {
    Restaurant restaurant;
    restaurant.setOpen(false);
    EXPECT_EQ(restaurant.open, false);
}

TEST(RestaurantTest3, addEmployee) {
    Restaurant restaurant;
    Employee employee;
    restaurant.addEmployee(employee);
    EXPECT_EQ(restaurant.getEmployees().size(), 1);
}

TEST(RestaurantTest4, addOrder) {
    Restaurant restaurant;
    Order order;
    restaurant.addOrder(order);
    EXPECT_EQ(restaurant.getOrders().size(), 1);
}

TEST(RestaurantTest5, addMeal) {
    Restaurant restaurant;
    Meal meal;
    restaurant.addMeal(meal);
    EXPECT_EQ(restaurant.getMeals().size(), 1);
}

TEST(RestaurantTest6, addIngredient) {
    Restaurant restaurant;
    Ingredient ingredient("1", "Tomato", "T", true, 2);
    restaurant.addIngredient(ingredient);
    EXPECT_EQ(restaurant.getIngredients().size(), 1);
}

TEST(RestaurantTest7, getEmployees) {
    Restaurant restaurant;
    Employee employee;
    restaurant.addEmployee(employee);
    EXPECT_EQ(restaurant.getEmployees().size(), 1);
}

TEST(RestaurantTest8, getOrders) {
    Restaurant restaurant;
    Order order;
    restaurant.addOrder(order);
    EXPECT_EQ(restaurant.getOrders().size(), 1);
}

TEST(RestaurantTest9, getUndoneOrders) {
    Restaurant restaurant;
    Order order({}, "69", 420.0);
    EXPECT_EQ(restaurant.getUndoneOrders().size(), 0);
    restaurant.addOrder(order);
    EXPECT_EQ(restaurant.getUndoneOrders().size(), 1);
}

TEST(RestaurantTest10, getMeals) {
    Restaurant restaurant;
    Meal meal("1", "Burger", "Cheeseburger", true, 2, {"apple"}, 5.99);
    restaurant.addMeal(meal);
    EXPECT_EQ(restaurant.getMeals().size(), 1);
}

TEST(RestaurantTest11, getAvailableMeals) {
    Restaurant restaurant;
    Meal meal("1", "Burger", "Cheeseburger", true, 2, {"apple"}, 5.99);
    restaurant.addMeal(meal);
    EXPECT_EQ(restaurant.getAvailableMeals().size(), 1);
}

TEST(RestaurantTest12, getIngredients) {
    Restaurant restaurant;
    Ingredient ingredient("1", "Tomato", "T", true, 2);
    restaurant.addIngredient(ingredient);
    EXPECT_EQ(restaurant.getIngredients().size(), 1);
}

TEST(RestaurantTest13, getAvailableIngredients) {
    Restaurant restaurant;
    Ingredient ingredient("1", "Tomato", "T", true, 2);
    restaurant.addIngredient(ingredient);
    EXPECT_EQ(restaurant.getAvailableIngredients().size(), 1);
}
