#include "gtest/gtest.h"
#include "../meals/Meal.h"
#include "../meals/Ingredient.h"

TEST(MealTest1, GetName) {
    string ingredient1 = "Tomato";
    std::vector<string> ingredients = {ingredient1};
    Meal meal("1", "Burger", "Cheeseburger", "description", true, 2, ingredients, 5.99);
    EXPECT_EQ(meal.getName(), "Cheeseburger");
}

TEST(MealTest2, GetId) {
    string ingredient1 = "Tomato";
    std :: vector<string> ingredients = {ingredient1};
    Meal meal("1", "Burger", "Cheeseburger", "description", true, 2, ingredients, 5.99);
    EXPECT_EQ(meal.getId(), "1");
}

TEST(MealTest3, GetPrice) {
    string ingredient1 = "Tomato";
    std :: vector<string> ingredients = {ingredient1};
    Meal meal("1", "Burger", "Cheeseburger", "description", true, 2, ingredients, 5.99);
    EXPECT_DOUBLE_EQ(meal.getPrice(), 5.99);
}

TEST(MealTest4, GetAvailability) {
    string ingredient1 = "Tomato";
    std :: vector<string> ingredients = {ingredient1};
    Meal meal("1", "Burger", "Cheeseburger", "description", true, 2, ingredients, 5.99);
    EXPECT_TRUE(meal.getAvailability());
}

TEST(MealTest5, RefreshPrice) {
    string ingredient1 = "Tomato";
    std :: vector<string> ingredients = {ingredient1};
    Meal meal("1", "Burger", "Cheeseburger", "description", true, 2, ingredients, 5.99);
    meal.refreshPrice(6.99);
    EXPECT_DOUBLE_EQ(meal.getPrice(), 6.99);
}

TEST(MealTest6, RefreshAvailability) {
    string ingredient1 = "Tomato";
    std :: vector<string> ingredients = {ingredient1};
    Meal meal("1", "Burger", "Cheeseburger", "description", true, 2, ingredients, 5.99);
    meal.refreshAvailability();
    EXPECT_TRUE(meal.getAvailability());
}

TEST(IngredientTest1, GetName) {
    Ingredient ingredient("1", "Tomato", "T", true, 2);
    EXPECT_EQ(ingredient.getName(), "Tomato");
}

TEST(IngredientTest2, GetId) {
    Ingredient ingredient("1", "Tomato", "T", true, 2);
    EXPECT_EQ(ingredient.getId(), "1");
}

TEST(IngredientTest3, GetProductsCount) {
    Ingredient ingredient("1", "Tomato", "T", true, 2);
    EXPECT_EQ(ingredient.getProductsCount(), 2);
}

TEST(IngredientTest4, SetProductsCount) {
    Ingredient ingredient("1", "Tomato", "T", true, 2);
    ingredient.setProductsCount(5);
    EXPECT_EQ(ingredient.getProductsCount(), 5);
}

TEST(IngredientTest5, CheckAvailability) {
    Ingredient ingredient("1", "Tomato", "T", true, 2);
    EXPECT_TRUE(ingredient.checkAvailability());
}

TEST(IngredientTest6, GetAvailability) {
    Ingredient ingredient("1", "Tomato", "T", true, 2);
    EXPECT_TRUE(ingredient.getAvailability());
}

