#include "addnewmeal.h"
#include "ui_addnewmeal.h"

AddNewMeal::AddNewMeal(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddNewMeal)
{
    ui->setupUi(this);
}

AddNewMeal::~AddNewMeal()
{
    delete ui;
}

void AddNewMeal::on_pushButton_addIngredient_clicked()
{

}


void AddNewMeal::on_pushButton_removeIngredient_clicked()
{

}


void AddNewMeal::on_pushButton_confirm_clicked()
{

}

