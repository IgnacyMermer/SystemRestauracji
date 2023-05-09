#ifndef PROJEKTPROI2_ORDER_H
#define PROJEKTPROI2_ORDER_H

#include <iostream>
#include "../meals/Meal.h"
#include <vector>
#include "../client/Client.h"

class Order {
    int orderId;
    double orderTotalPrice;
    std::vector<int> orderMealsIds;
    int orderClientId;
public:
    Order(int id, std::vector<int> mealsIds, int clientId, double totalPrice);
    int id();
    double totalPrice();
    std::vector<int> mealsIds();
    int clientId();
    void saveToDB(); // zapis do DB
private:
};


#endif //PROJEKTPROI2_ORDER_H
