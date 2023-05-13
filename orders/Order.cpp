#include "Order.h"
#include <vector>
#include <algorithm>
#include "../client/Client.h"


Order::Order(int id, std::vector<int> mealsIds, int clientId, double totalPrice) {
    orderId = id;
    orderMealsIds = mealsIds;
    orderClientId = clientId;
    orderTotalPrice = totalPrice;
    orderCompletion = false;
}

int Order::id() {return orderId;};

double Order::totalPrice() {return orderTotalPrice;};

void Order::addMeal(int mealId) {
    orderMealsIds.push_back(mealId);
};

int Order::getNumberOfMeals() {
    return orderMealsIds.size();
};

void Order::removeMeal(int mealId) {
    auto it = std::find(orderMealsIds.begin(), orderMealsIds.end(), mealId);
    orderMealsIds.erase(it);
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

std::vector<int> Order::mealsIds() {return orderMealsIds;};

int Order::clientId() {return orderClientId;};

void Order::saveToDB() {
    // blok try catch
};

