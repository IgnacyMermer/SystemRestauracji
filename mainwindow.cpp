#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include "mainwindowloggedin.h"

mainwindow::mainwindow(QWidget *parent)
        : QMainWindow(parent)
        , ui(new Ui::mainwindow)
{
    ui->setupUi(this);
}

mainwindow::~mainwindow()
{
    delete ui;
}

void mainwindow::on_pushButton_Login_clicked(){
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();
    if(username=="test"&&password=="test"){
        //QMessageBox::information(this, "login", "Correct credentials");
        this->hide();
        mainwindowloggedin mainWindowLoggedIn;
        mainWindowLoggedIn.setModal(true);
        mainWindowLoggedIn.exec();
    }
    else{
        QMessageBox::information(this, "Login", "Wrong credentials");
    }
}
