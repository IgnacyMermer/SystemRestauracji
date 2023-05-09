#include "Order.h"
#include <vector>
#include "../client/Client.h"

Order::Order(int id, std::vector<int> mealsIds, int clientId, double totalPrice) {
    orderId = id;
    orderMealsIds = mealsIds;
    orderClientId = clientId;
    orderTotalPrice = totalPrice;
}

int Order::id() {return orderId;};

double Order::totalPrice() {return orderTotalPrice;};

std::vector<int> Order::mealsIds() {return orderMealsIds;};

int Order::clientId() {return orderClientId;};

void Order::saveToDB() {
    // blok try catch
};

