#include <QApplication>
#include <QPushButton>
#include "mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    /*QPushButton button("Hello world!", nullptr);
    button.setWindowTitle("System restauracji");
    button.resize(200, 100);
    button.show();*/
    mainwindow w;
    w.show();
    return QApplication::exec();
}
