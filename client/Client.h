#ifndef PROJEKTPROI2_CLIENT_H
#define PROJEKTPROI2_CLIENT_H

#include <iostream>

class Client {
    std::string clientId;
    std::string clientName;
    std::string clientLogin;
    int clientPoints;
public:
    Client(std::string id, std::string name, std::string login);
    std::string id();
    void addOrder();
    void addPoints(int points);
    std::string name();
    std::string login();
protected:
    int myPoint();
};


#endif //PROJEKTPROI2_CLIENT_H
