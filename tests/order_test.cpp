#include "gtest/gtest.h"
#include "../orders/Order.h"
#include "../meals/Meal.h"

TEST(OrderTest1, TotalPrice) {
    string ingredient1 = "Tomato";
    std :: vector<string> ingredients = {ingredient1};
    Meal meal1("1", "Burger", "Cheeseburger", true, 2, ingredients, 5.99);
    std::vector<Meal> meals = {meal1};
    Order order(meals, "123", 5.99);
    EXPECT_DOUBLE_EQ(order.totalPrice(), 5.99);
}

TEST(OrderTest2, GetNumberOfMeals) {
    string ingredient1 = "Tomato";
    std :: vector<string> ingredients = {ingredient1};
    Meal meal1("1", "Burger", "Cheeseburger", true, 2, ingredients, 5.99);
    Meal meal2("2", "Pizza", "Margherita", true, 1, ingredients, 8.99);

    std::vector<Meal> meals = {meal1, meal2};
    Order order(meals, "123", 14.98);
    EXPECT_EQ(order.getNumberOfMeals(), 2);
}

TEST(OrderTest3, AddMeal) {
    string ingredient1 = "Tomato";
    std :: vector<string> ingredients = {ingredient1};
    Meal meal1("1", "Burger", "Cheeseburger", true, 2, ingredients, 5.99);
    Meal meal2("2", "Pizza", "Margherita", true, 1, ingredients, 8.99);

    std::vector<Meal> meals = {meal1};
    Order order(meals, "123", 5.99);
    order.addMeal(meal2);
    EXPECT_EQ(order.getNumberOfMeals(), 2);
}

TEST(OrderTest5, RemoveLastMeal) {
    string ingredient1 = "Tomato";
    std :: vector<string> ingredients = {ingredient1};
    Meal meal1("1", "Burger", "Cheeseburger", true, 2, ingredients, 5.99);
    Meal meal2("2", "Pizza", "Margherita", true, 1, ingredients, 8.99);

    std::vector<Meal> meals = {meal1, meal2};
    Order order(meals, "123", 14.98);
    order.removeLastMeal();
    EXPECT_EQ(order.getNumberOfMeals(), 1);
}

TEST(OrderTest6, IsMealEmpty) {
    string ingredient1 = "Tomato";
    std :: vector<string> ingredients = {ingredient1};

    Order order({}, "123", 5.99);
    EXPECT_TRUE(order.isMealEmpty());

    Meal meal("1", "Burger", "Cheeseburger", true, 2, ingredients, 5.99);
    order.addMeal(meal);
    EXPECT_FALSE(order.isMealEmpty());
}