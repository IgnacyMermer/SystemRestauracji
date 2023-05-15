
#include "FamilyOrder.h"
#include <vector>
#include <algorithm>
#include "../meals/Meal.h"

using namespace std;

FamilyOrder::FamilyOrder(std::vector<Meal> mealsIds, std::vector<string> clientIds, double totalPrice) : Order(mealsIds, clientIds[0], totalPrice) {
    orderClientIds = clientIds;
}

void FamilyOrder::addClient(string clientId) {
    orderClientIds.push_back(clientId);
}

void FamilyOrder::removeClient(string clientId) {
    auto it = std::find(orderClientIds.begin(), orderClientIds.end(), clientId);
    orderClientIds.erase(it);
}

void FamilyOrder::removeLastClient() {
    orderClientIds.pop_back();
}

double FamilyOrder::totalPrice() {
    return Order::totalPrice();
}

int FamilyOrder::getNumberOfClients() {
    return orderClientIds.size();
}

double FamilyOrder::splitTotalPrice() {
    return Order::totalPrice() / orderClientIds.size();
}

std::vector<string> FamilyOrder::clientIds() {
    return orderClientIds;
}

void FamilyOrder::saveToDB() {
    // blok try catch
}