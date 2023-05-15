#ifndef PROJEKTPROI2_USERDATA_H
#define PROJEKTPROI2_USERDATA_H
#include <iostream>
#include "./ui/mainwindow.h"

using namespace std;

class UserData {
public:
    static mainwindow* mainwindowScreen;
    static string id;
    static string role;
    static int bonusPoints;
    static string login;
    static string name;
    static string address;
    static string email;
    static string getId(){
        return UserData::id;
    };
    static void setId(string newId);
    static string getLogin(){
        return UserData::login;
    };
    static string getName(){
        return name;
    };
    static string getAddress(){
        return UserData::address;
    };
    static string getEmail(){
        return UserData::email;
    };
private:

};


#endif //PROJEKTPROI2_USERDATA_H
