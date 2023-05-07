#include "Order.h"
#include <vector>
#include "../client/Client.h"


using namespace std;

void Order::updateTotalPrice() {
    double totalPriceTemp = 0.0;
    for(int i=0; i<meals.size(); i++){
        totalPriceTemp+=meals[i].getPrice();
    }
    totalPrice = totalPriceTemp;
}

double Order::getTotalPrice() {
    return totalPrice;
}

void Order::setDone(bool done) {
    this->done = done;
}

Client Order::getClient() {
    return client;
}

bool Order::getDone() {
    return done;
}
