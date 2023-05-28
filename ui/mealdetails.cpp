#include "mealdetails.h"
#include "ui_mealdetails.h"
#include "../meals/Meal.h"

MealDetails::MealDetails(Meal meal, QWidget *parent) :
    QDialog(parent),
    meal(meal),
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

