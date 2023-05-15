#include "yourdata.h"
#include "ui_yourdata.h"
#include "../UserData.h"

YourData::YourData(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::YourData)
{
    ui->setupUi(this);
    ui->label_name->setText(QString::fromStdString(UserData::name));
    ui->label_login->setText(QString::fromStdString(UserData::login));
    ui->label_role->setText(QString::fromStdString(UserData::role));

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

