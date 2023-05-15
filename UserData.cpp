#include "UserData.h"
#include "./ui/mainwindow.h"
using namespace std;

string UserData::id = "";
string UserData::login = "";
string UserData::name = "";
string UserData::role = "";
string UserData::email = "";
mainwindow* UserData::mainwindowScreen = nullptr;

void UserData::setId(string newId) {
    id = newId;
}


