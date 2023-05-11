#include "mealsediting.h"
#include "ui_mealsediting.h"
#include "addnewmeal.h"
#include "addnewdrinksauce.h"

MealsEditing::MealsEditing(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MealsEditing)
{
    ui->setupUi(this);
}

MealsEditing::~MealsEditing()
{
    delete ui;
}

void MealsEditing::on_pushButton_addNewMeal_clicked()
{
    AddNewMeal addNewMeal;
    addNewMeal.setModal(true);
    addNewMeal.exec();
}

void MealsEditing::on_pushButton_addNewDrinkSauce_clicked()
{
    AddNewDrinkSauce addNewDrinkSauce;
    addNewDrinkSauce.setModal(true);
    addNewDrinkSauce.exec();
}


void MealsEditing::on_pushButton_editMeal_clicked()
{

}


void MealsEditing::on_pushButton_changeAvailabilityMeal_clicked()
{

}


void MealsEditing::on_pushButton_removeMeal_clicked()
{

}

