#include "mainwindowloggedinclient.h"
#include "ui_mainwindowloggedinclient.h"

MainWindowLoggedInClient::MainWindowLoggedInClient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainWindowLoggedInClient)
{
    ui->setupUi(this);
}

MainWindowLoggedInClient::~MainWindowLoggedInClient()
{
    delete ui;
}

void MainWindowLoggedInClient::on_pushButton_yourData_clicked()
{

}


void MainWindowLoggedInClient::on_pushButton_yourOrders_clicked()
{

}


void MainWindowLoggedInClient::on_pushButton_logOut_clicked()
{

}


void MainWindowLoggedInClient::on_pushButton_addToOrder_clicked()
{

}


void MainWindowLoggedInClient::on_pushButton_removeFromOrder_clicked()
{

}


void MainWindowLoggedInClient::on_pushButton_removeOrder_clicked()
{

}


void MainWindowLoggedInClient::on_pushButton_confirmOrder_clicked()
{

}

