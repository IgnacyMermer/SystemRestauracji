#ifndef PROJEKTPROI2_CLIENT_H
#define PROJEKTPROI2_CLIENT_H

#include <iostream>

class Client {
    int clientId;
    std::string clientEmail;
    std::string clientLogin;
    int clientPoints;
public:
    Client(int id, std::string email, std::string login);
    int id();
    void addOrder();
    void addPoints(int points);
protected:
    std::string email();
    std::string login();
    int myPoint();
};


#endif //PROJEKTPROI2_CLIENT_H
