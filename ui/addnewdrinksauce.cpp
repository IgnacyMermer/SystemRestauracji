#include "addnewdrinksauce.h"
#include "ui_addnewdrinksauce.h"

AddNewDrinkSauce::AddNewDrinkSauce(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddNewDrinkSauce)
{
    ui->setupUi(this);
}

AddNewDrinkSauce::~AddNewDrinkSauce()
{
    delete ui;
}

void AddNewDrinkSauce::on_pushButton_confirm_clicked()
{

}

