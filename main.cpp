#include <QApplication>
#include <QPushButton>
#include "ui/mainwindow.h"
#include "UserData.h"

std::string UserData::name = "";
std::string UserData::address = "";
std::string UserData::email = "";
std::string UserData::login = "";

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    mainwindow w;
    w.show();
    return QApplication::exec();
}
