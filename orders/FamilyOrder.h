#include <iostream>
#include "Order.h"

class FamilyOrder : public Order {
    std::vector<int> orderClientIds;
public:
    FamilyOrder(std::vector<int> mealsIds, std::vector<int> clientIds, double totalPrice);
    void addClient(int clientId);
    void removeClient(int clientId);
    void removeLastClient();
    double totalPrice();
    int getNumberOfClients();
    double splitTotalPrice();
    std::vector<int> clientIds();
    void saveToDB();
};