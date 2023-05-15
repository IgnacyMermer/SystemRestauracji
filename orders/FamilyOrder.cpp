
#include "FamilyOrder.h"
#include <vector>
#include <algorithm>

FamilyOrder::FamilyOrder(std::vector<int> mealsIds, std::vector<int> clientIds, double totalPrice) : Order(mealsIds, clientIds[0], totalPrice) {
    orderClientIds = clientIds;
}

void FamilyOrder::addClient(int clientId) {
    orderClientIds.push_back(clientId);
}

void FamilyOrder::removeClient(int clientId) {
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

std::vector<int> FamilyOrder::clientIds() {
    return orderClientIds;
}

void FamilyOrder::saveToDB() {
    // blok try catch
}