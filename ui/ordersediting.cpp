#include "ordersediting.h"
#include "ui_ordersediting.h"

ordersEditing::ordersEditing(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ordersEditing)
{
    ui->setupUi(this);
}

ordersEditing::~ordersEditing()
{
    delete ui;
}

void ordersEditing::on_pushButton_comeback_clicked()
{

}


void ordersEditing::on_pushButton_orderDone_clicked()
{

}


void ordersEditing::on_pushButton_showDetails_clicked()
{

}

