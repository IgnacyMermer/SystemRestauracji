#ifndef PROJEKTPROI2_ORDER_H
#define PROJEKTPROI2_ORDER_H

#include <iostream>
#include "../meals/Meal.h"
#include <vector>
#include "../client/Client.h"

class Order {
    std::string id;
    double orderTotalPrice;
    std::vector<Meal> orderMealsIds;
    string orderClientId;
    bool orderCompletion;
    time_t orderTime;
    int estimatedTime;
    time_t CopletionTime;
    string clientName;
    string status;
public:
    Order(){}
    Order(std::vector<Meal> mealsIds, string clientId, double totalPrice, string clientName, string status);
    Order(std::vector<Meal> mealsIds, string clientId, double totalPrice);
    double totalPrice();
    int getNumberOfMeals();
    void addMeal(Meal mealId);
    void removeMeal(Meal mealId);
    void removeLastMeal();
    bool isMealEmpty();
    void setClientId(int clientId);
    void setOrderComplete();
    bool isOrderComplete();
    string getStatus();
    void setDiscount(int discount);
    string getClientName();
    std::vector<Meal> mealsIds();
    string clientId();
    time_t getTime();
    int getEstimatedTime();
    time_t getCompletionTime();
    void setId(std::string newId);
    std::string getId();
    void saveToDB(); // zapis do DB
private:
};


#endif //PROJEKTPROI2_ORDER_H
