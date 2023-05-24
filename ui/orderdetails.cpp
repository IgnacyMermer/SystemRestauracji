#include "orderdetails.h"
#include "ui_orderdetails.h"

OrderDetails::OrderDetails(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OrderDetails)
{
    ui->setupUi(this);
}

OrderDetails::~OrderDetails()
{
    delete ui;
}

void OrderDetails::on_pushButton_comeback_clicked()
{

}

