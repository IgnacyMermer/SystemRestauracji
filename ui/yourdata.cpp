#include "yourdata.h"
#include "ui_yourdata.h"

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
