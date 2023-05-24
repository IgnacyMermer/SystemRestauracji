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
            clients.push_back(client);
            ui->listWidget->addItem(QString::fromStdString(client.name()+" - "+client.login()));
        }
    }
}

YourClients::~YourClients()
{
    delete ui;
}

void YourClients::on_pushButton_clicked()
{
    std::string itemText = ui->currentItem()->text().toStdString();
    std::string name = "";
    std::string login = "";
    bool isLogin = false;
    for(int i=0; i<itemText.length(); i++){
        if(itemText[i]=='-'){
            isLogin = true;
        }
        else if(isLogin){
            login+=itemText[i];
        }
        else{
            name+=itemText[i];
        }
    }
    name = name.substr(0, name.length()-1);
    login = login.substr(1);
    Client chosenClient;
    for(int i=0; i<clients.size(); i++){
        if(clients[i].name()==name&&clients[i].login()==login){
            chosenClient=clients[i];
        }
    }

}

