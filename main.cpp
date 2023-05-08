#include <QApplication>
#include <QPushButton>
#include "ui/mainwindow.h"
#include "client/Client.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    /*QPushButton button("Hello world!", nullptr);
    button.setWindowTitle("System restauracji");
    button.resize(200, 100);
    button.show();*/
    mainwindow w;
    w.show();
    Client c;
    c.id = 2;
    return QApplication::exec();
}
