#include "Order.h"
#include <vector>
#include <algorithm>
#include "../client/Client.h"
#include <ctime>


Order::Order(std::vector<int> mealsIds, int clientId, double totalPrice) {
    orderMealsIds = mealsIds;
    orderClientId = clientId;
    orderTotalPrice = totalPrice;
    orderCompletion = false;
    orderTime = time(0);
    estimatedTime = 0;

}

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

void Order::setDiscount(int discount) {
    orderTotalPrice = orderTotalPrice * (100 - discount)/10;
};

time_t Order::getTime() {return orderTime;};

int Order::getEstimatedTime() {return estimatedTime;};

time_t Order::getCompletionTime() {
    tm *localTime = localtime(&orderTime);
    int newMinute = localTime->tm_min + estimatedTime;
    int newHour = localTime->tm_hour + (newMinute / 60);
    localTime->tm_min = newMinute;
    localTime->tm_hour = newHour;
    time_t completionTime = mktime(localTime);
    return completionTime;
    };

std::vector<int> Order::mealsIds() {return orderMealsIds;};

int Order::clientId() {return orderClientId;};

void Order::saveToDB() {
    // blok try catch
};

