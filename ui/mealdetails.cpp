#include "mealdetails.h"
#include "ui_mealdetails.h"
#include "../meals/Meal.h"

MealDetails::MealDetails(Meal meal, QWidget *parent) :
    QDialog(parent),
    meal(meal),
    ui(new Ui::MealDetails)
{
    ui->setupUi(this);
    ui->label_shortName->setText(QString::fromStdString(meal.getShortName()));
    ui->label_name->setText(QString::fromStdString(meal.getName()));
    ui->label_description->setText(QString::fromStdString(meal.getDescription()));

}

MealDetails::~MealDetails()
{
    delete ui;
}

void MealDetails::on_pushButton_clicked()
{
    this->hide();
}

