#ifndef PROJEKTPROI2_ORDER_H
#define PROJEKTPROI2_ORDER_H

#include <iostream>
#include "../meals/Meal.h"
#include <vector>
#include "../client/Client.h"

using namespace std;

class Order {
public:
    int id;
    Order(int clientId, vector<Meal> meals): clientId(clientId), meals(meals){
        double totalPriceTemp = 0.0;
        for(int i=0; i<meals.size(); i++){
            totalPriceTemp+=meals[i].getPrice();
        }
        totalPrice = totalPriceTemp;
    }
    double getTotalPrice();
    void updateTotalPrice();
    void setDone(bool done);
    Client getClient();
    bool getDone();
private:
    vector<Meal> meals;
    double totalPrice;
    Client client;
    bool done;

};


#endif //PROJEKTPROI2_ORDER_H
