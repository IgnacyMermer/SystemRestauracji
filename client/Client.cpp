#include "Client.h"
#include "../orders/Order.h"


Client::Client(std::string id, std::string name, std::string login) {
    clientId = id;
    clientName = name;
    clientLogin = login;
    clientPoints = 0;
}

std::string Client::id() {return clientId;}

void Client::addOrder() {
    // myOrder = Order({6, 2, 5}, id(), 250);
    // myOrder.saveToDB();
}

void Client::addPoints(int points) {
    clientPoints += points;
}

std::string Client::name() {return clientName;}

std::string Client::login() {return clientLogin;}

int Client::myPoint() {return clientPoints;}
