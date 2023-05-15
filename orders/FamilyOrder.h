#include <iostream>
#include "Order.h"
#include "../meals/Meal.h"

class FamilyOrder : public Order {
    std::vector<string> orderClientIds;
public:
    FamilyOrder(std::vector<Meal> mealsIds, std::vector<string> clientIds, double totalPrice);
    void addClient(string clientId);
    void removeClient(string clientId);
    void removeLastClient();
    double totalPrice();
    int getNumberOfClients();
    double splitTotalPrice();
    std::vector<string> clientIds();
    void saveToDB();
};