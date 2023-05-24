#include "yourclients.h"
#include "ui_yourclients.h"
#include "../data/GetData.h"
#include "json_spirit.h"
#include "../client/Client.h"

using namespace json_spirit;

YourClients::YourClients(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::YourClients)
{
    ui->setupUi(this);
    GetData getData = GetData("http://localhost:3000/clients/getallclients");
    getData.send_request();
    if(getData.getHttpCode()==200){
        Value value;
        read(getData.getResponse(), value);
        Array& arr = value.get_obj()[0].value_.get_array();
        for(int i=0; i<arr.size(); i++){
            Client client = Client(arr[i].get_obj()[0].value_.get_str(), arr[i].get_obj()[4].value_.get_str(),
                                   arr[i].get_obj()[1].value_.get_str());
            ui->listWidget->addItem(QString::fromStdString(client.name()));
        }
    }
}

YourClients::~YourClients()
{
    delete ui;
}

void YourClients::on_pushButton_clicked()
{

}

