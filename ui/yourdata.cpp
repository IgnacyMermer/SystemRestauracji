#include "yourdata.h"
#include "ui_yourdata.h"
#include "../UserData.h"

YourData::YourData(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::YourData)
{
    ui->setupUi(this);

}

YourData::~YourData()
{
    delete ui;
}

void YourData::on_pushButton_changePassword_clicked()
{
    UserData::name = "";
    ui->label_name->setText(QString::fromStdString(UserData::name));
}

