#include "UserData.h"
#include "./ui/mainwindow.h"
using namespace std;

string UserData::id = "";
mainwindow* UserData::mainwindowScreen = nullptr;

void UserData::setId(string newId) {
    id = newId;
}


