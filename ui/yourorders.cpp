#include "yourorders.h"
#include "ui_yourorders.h"

YourOrders::YourOrders(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::YourOrders)
{
    ui->setupUi(this);
}

YourOrders::~YourOrders()
{
    delete ui;
}

void YourOrders::on_pushButton_clicked()
{

}

