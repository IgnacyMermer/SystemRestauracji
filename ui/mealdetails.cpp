#include "mealdetails.h"
#include "ui_mealdetails.h"

MealDetails::MealDetails(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MealDetails)
{
    ui->setupUi(this);
}

MealDetails::~MealDetails()
{
    delete ui;
}

void MealDetails::on_pushButton_clicked()
{

}

