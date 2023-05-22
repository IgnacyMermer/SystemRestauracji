#include "taskdetails.h"
#include "ui_taskdetails.h"

TaskDetails::TaskDetails(std::string id, QWidget *parent) :
    QDialog(parent),
    id(id),
    ui(new Ui::TaskDetails)
{
    ui->setupUi(this);
}

TaskDetails::~TaskDetails()
{
    delete ui;
}

void TaskDetails::on_pushButton_comeback_clicked()
{

}

