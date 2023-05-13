#ifndef PROJEKTPROI2_CLIENT_H
#define PROJEKTPROI2_CLIENT_H

#include <iostream>

class Client {
    int clientId;
    std::string clientEmail;
    std::string clientLogin;
    int clientPoints;
public:
    int id;
    Client(int id, std::string email, std::string login);
    void addOrder();
private:
    std::string email();
    std::string login();
    int bonusPoints;
};


#endif //PROJEKTPROI2_CLIENT_H
