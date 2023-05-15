#include "Order.h"
#include <vector>
#include <algorithm>
#include "../client/Client.h"


Order::Order(std::vector<Meal> mealsIds, string clientId, double totalPrice) {
    orderMealsIds = mealsIds;
    orderClientId = clientId;
    orderTotalPrice = totalPrice;
    orderCompletion = false;
}

double Order::totalPrice() {return orderTotalPrice;};

void Order::addMeal(Meal mealId) {
    orderMealsIds.push_back(mealId);
};

int Order::getNumberOfMeals() {
    return orderMealsIds.size();
};

void Order::removeMeal(Meal mealId) {
    //auto it = std::find(orderMealsIds.begin(), orderMealsIds.end(), mealId);
    //orderMealsIds.erase(it);
};

void Order::removeLastMeal() {
    orderMealsIds.pop_back();
};

bool Order::isMealEmpty() {
    return orderMealsIds.empty();
};

void Order::setClientId(int clientId) {
    orderClientId = clientId;
};

void Order::setOrderComplete() {
    orderCompletion = true;
};

bool Order::isOrderComplete() {return orderCompletion;};

void Order::setDiscount(int discount) {
    orderTotalPrice = orderTotalPrice * (100 - discount)/10;
};


std::vector<Meal> Order::mealsIds() {return orderMealsIds;};

string Order::clientId() {return orderClientId;};

void Order::saveToDB() {
    // blok try catch
};

