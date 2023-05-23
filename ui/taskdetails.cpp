#include "taskdetails.h"
#include "ui_taskdetails.h"
#include "../employees/Task.h"
#include "../data/GetData.h"
#include "json_spirit.h"
#include "../data/PostData.h"
#include <QMessageBox>

using namespace json_spirit;

TaskDetails::TaskDetails(Task task, QWidget *parent) :
    QDialog(parent),
    task(task),
    ui(new Ui::TaskDetails)
{
    ui->setupUi(this);
    GetData getData = GetData("http://localhost:3000/employees/employeebyid/"+task.getBossId());
    getData.send_request();
    if(getData.getHttpCode()==200){
        Value value;
        read(getData.getResponse(), value);
        std::string bossName = value.get_obj()[0].value_.get_array()[0].get_obj()[4].value_.get_str();
        ui->label_boss->setText(QString::fromStdString(bossName));
    }
    ui->label_title->setText(QString::fromStdString(task.name()));
    ui->textBrowser_description->setText(QString::fromStdString(task.description()));
}

TaskDetails::~TaskDetails()
{
    delete ui;
}

void TaskDetails::on_pushButton_comeback_clicked()
{
    this->hide();
}

void TaskDetails::on_pushButton_taskDone_clicked()
{
    PostData postData = PostData("http://localhost:3000/task/changetaskdone/"+task.getId(), "{\"done\": "+to_string(!task.isDone())+"}");
    postData.send_request();
    if(postData.getHttpCode()==200){
        QMessageBox::information(this, "Done", "changed");
    }

}

