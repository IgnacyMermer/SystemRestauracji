#include "Client.h"

// Opcjonalne:
// W klasie Client będzie metoda, która będzie tworzyła Order a następnie wzywała chef.searchForFreeCook();

Client::Client(int id, std::string email, std::string login) {
    clientId = id;
    clientEmail = email;
    clientLogin = login;
    clientPoints = 0;
}

int Client::id() {return clientId;}

void Client::addOrder() {
    // myOrder = Order(1, {6, 2, 5}, id(), 250);
    // myOrder.saveToDB();
}

void Client::addPoints(int points) {
    clientPoints += points;
}

std::string Client::email() {return clientEmail;}

std::string Client::login() {return clientLogin;}

int Client::myPoint() {return clientPoints;}
