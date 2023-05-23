#include "addtasks.h"
#include "ui_addtasks.h"

AddTasks::AddTasks(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddTasks)
{
    ui->setupUi(this);
}

AddTasks::~AddTasks()
{
    delete ui;
}

void AddTasks::on_pushButton_comeback_clicked()
{

}

