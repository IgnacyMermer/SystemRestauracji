#include "yourorderdetails.h"
#include "ui_yourorderdetails.h"

YourOrderDetails::YourOrderDetails(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::YourOrderDetails)
{
    ui->setupUi(this);
}

YourOrderDetails::~YourOrderDetails()
{
    delete ui;
}

void YourOrderDetails::on_pushButton_goBack_clicked()
{
    this->hide();
}

