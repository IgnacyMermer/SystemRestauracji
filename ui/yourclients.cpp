#include "yourclients.h"
#include "ui_yourclients.h"


YourClients::YourClients(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::YourClients)
{
    ui->setupUi(this);

}

YourClients::~YourClients()
{
    delete ui;
}

void YourClients::on_pushButton_clicked()
{

}

