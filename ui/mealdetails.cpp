#include "mealdetails.h"
#include "ui_mealdetails.h"
#include "../meals/Meal.h"
#include <typeinfo>

MealDetails::MealDetails(Meal meal, QWidget *parent) :
    QDialog(parent),
    meal(meal),
    ui(new Ui::MealDetails)
{
    ui->setupUi(this);
    ui->label_shortName->setText(QString::fromStdString(meal.getShortName()));
    ui->label_name->setText(QString::fromStdString(meal.getName()));
    ui->label_description->setText(QString::fromStdString(meal.getDescription()));
    ui->label_availability->setText(QString::fromStdString(to_string(meal.getAvailability())));
    //ui->label_productsCount->setText(QString::fromStdString(meal.get()));
    for(int i=0; i<meal.getIngredients().size(); i++){
        ui->listWidget_ingredients->addItem(QString::fromStdString(meal.getIngredients()[i].getName()));
    }
}

MealDetails::~MealDetails()
{
    delete ui;
}

void MealDetails::on_pushButton_clicked()
{
    this->hide();
}

