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
    bool orderCompletion;
public:
    Order(int id, std::vector<int> mealsIds, int clientId, double totalPrice);
    int id();
    double totalPrice();
    int getNumberOfMeals();
    void addMeal(int mealId);
    void removeMeal(int mealId);
    void removeLastMeal();
    bool isMealEmpty();
    void setClientId(int clientId);
    void setOrderComplete();
    bool isOrderComplete();
    std::vector<int> mealsIds();
    int clientId();
    void saveToDB(); // zapis do DB
private:
};


#endif //PROJEKTPROI2_ORDER_H
