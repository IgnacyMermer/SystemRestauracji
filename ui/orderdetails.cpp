#include "orderdetails.h"
#include "ui_orderdetails.h"
#include "../orders/Order.h"
#include "../meals/Meal.h"

OrderDetails::OrderDetails(Order order, QWidget *parent) :
    QDialog(parent),
    order(order),
    ui(new Ui::OrderDetails)
{
    ui->setupUi(this);
    ui->label_clientName->setText(QString::fromStdString(order.getClientName()));
    ui->label_price->setText(QString::fromStdString(to_string(order.totalPrice())));
    ui->label_status->setText(QString::fromStdString(order.getStatus()));
    std::vector<Meal> orderMeals = order.mealsIds();
    for(int i=0; i<orderMeals.size(); i++){
        ui->listWidget->addItem(QString::fromStdString(orderMeals[i].getName()));
    }
}

OrderDetails::~OrderDetails()
{
    delete ui;
}

void OrderDetails::on_pushButton_comeback_clicked()
{
    this->hide();
}

