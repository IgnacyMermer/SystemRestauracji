#include "mainwindowloggedin.h"
#include "ui_mainwindowloggedin.h"

mainwindowloggedin::mainwindowloggedin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mainwindowloggedin)
{
    ui->setupUi(this);
}

mainwindowloggedin::~mainwindowloggedin()
{
    delete ui;
}
