#include "yourorderdetails.h"
#include "ui_yourorderdetails.h"
#include "../data/GetData.h"
#include <QMessageBox>
#include <json_spirit.h>

using namespace json_spirit;

YourOrderDetails::YourOrderDetails(std::string id, QWidget *parent) :
    QDialog(parent),
    orderId(id),
    ui(new Ui::YourOrderDetails)
{
    ui->setupUi(this);
    string url = "http://localhost:3000/order/getorder/"+orderId;
    GetData getData = GetData(url);
    getData.send_request();
    if(getData.getHttpCode()==200){
        Value value;
        read( getData.getResponse(), value );
        std::cout<<value.get_obj()[0].value_.get_obj()[1].value_.get_real();
    }
    else{
        QMessageBox::information(this, "Error", "There was an error during getting order details");
    }
}

YourOrderDetails::~YourOrderDetails()
{
    delete ui;
}

void YourOrderDetails::on_pushButton_goBack_clicked()
{
    this->hide();
}

void YourOrderDetails::setOrderId(std::string newOrderId) {
    orderId = newOrderId;
}