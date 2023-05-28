#include "addingredient.h"
#include "ui_addingredient.h"

AddIngredient::AddIngredient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddIngredient)
{
    ui->setupUi(this);
}

AddIngredient::~AddIngredient()
{
    delete ui;
}

void AddIngredient::on_pushButton_clicked()
{
    std::string name = ui->textEdit_name->toPlainText().toStdString();
    //std::string name = ui->textEdit_name->text().toStdString();
    //std::string name = ui->textEdit_name->text().toStdString();
}

