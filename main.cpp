#include <QApplication>
#include <QPushButton>
#include "ui/mainwindow.h"
#include "UserData.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    mainwindow w;
    w.show();
    return QApplication::exec();
}
