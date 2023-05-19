#include "yourorders.h"
#include "ui_yourorders.h"
#include "../ui/mainwindowloggedinclient.h"
#include "../data/GetData.h"
#include "../UserData.h"
#include "QMessageBox"

using namespace std;
using namespace json_spirit;


YourOrders::YourOrders(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::YourOrders)
{
    ui->setupUi(this);
    GetData getData = GetData("http://localhost:3000/order/getclientorders/"+UserData::getId());
    getData.send_request();
    if(getData.getHttpCode()==200){
        Value value;
        read(getData.getResponse(), value);
        cout<<value.get_obj()[0].value_.get_array()[0].get_obj()[0].value_.get_str();
        Array& arr = value.get_obj()[0].value_.get_array();
        for(int i=0; i<arr.size(); i++){
            string item = "Zamowienie kwota: "+to_string(value.get_obj()[0].value_.get_array()[i].get_obj()[1].value_.get_real());
            ui->listWidget_yourOrders->addItem(QString::fromStdString(item));
        }

    }
    else{
        QMessageBox::information(this, "Orders", "Error during getting your orders");
    }

}

YourOrders::~YourOrders()
{
    delete ui;
}

void YourOrders::on_pushButton_clicked()
{
    this->hide();
    MainWindowLoggedInClient mainWindowLoggedInClient;
    mainWindowLoggedInClient.setModal(true);
    mainWindowLoggedInClient.exec();
}

