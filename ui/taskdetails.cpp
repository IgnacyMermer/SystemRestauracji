#include "taskdetails.h"
#include "ui_taskdetails.h"
#include "../employees/Task.h"

TaskDetails::TaskDetails(Task task, QWidget *parent) :
    QDialog(parent),
    task(task),
    ui(new Ui::TaskDetails)
{
    ui->setupUi(this);
    std::cout<<task.getId();
}

TaskDetails::~TaskDetails()
{
    delete ui;
}

void TaskDetails::on_pushButton_comeback_clicked()
{

}

