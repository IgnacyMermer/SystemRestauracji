#ifndef PROJEKTPROI2_USERDATA_H
#define PROJEKTPROI2_USERDATA_H
#include <iostream>

using namespace std;

class UserData {
public:
    static int id;
    static string role;
    static int bonusPoints;
    static string login;
    static string name;
    static string address;
    static string email;
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
