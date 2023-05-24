#include "clientdetails.h"
#include "ui_clientdetails.h"

ClientDetails::ClientDetails(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ClientDetails)
{
    ui->setupUi(this);
}

ClientDetails::~ClientDetails()
{
    delete ui;
}
