#include "clientdetails.h"
#include "ui_clientdetails.h"
#include "../client/Client.h"
#include "../data/GetData.h"
#include <QMessageBox>
#include "json_spirit.h"
#include "../meals/Meal.h"
#include "../meals/Mainmeal.h"
#include "../orders/Order.h"
#include "./yourorderdetails.h"
#include <QListWidgetItem>

using namespace json_spirit;

ClientDetails::ClientDetails(Client client, QWidget *parent) :
    QDialog(parent),
    client(client),
    ui(new Ui::ClientDetails)
{
    ui->setupUi(this);
    ui->label_clientLogin->setText(QString::fromStdString(client.login()));
    ui->label_clientName->setText(QString::fromStdString(client.name()));
    ui->label_clientPoints->setText(QString::fromStdString(std::to_string(client.myPoint())));
    GetData getData = GetData("http://localhost:3000/order/getclientorders/"+client.id());
    getData.send_request();
    if(getData.getHttpCode()==200){
        Value value;
        read(getData.getResponse(), value);
        Array& arr = value.get_obj()[0].value_.get_array();
        for(int i=0; i<arr.size(); i++) {
            vector <Meal> meals;
            Array &arrMeals = arr[i].get_obj()[2].value_.get_array();
            for (int j = 0; j < arrMeals.size(); j++) {
                json_spirit::Object &obj = arrMeals[j].get_obj();

                std::vector <Value> dest = obj[7].value_.get_array();
                vector<Value>::iterator it;
                vector <string> ingredientsList;

                for (it = dest.begin(); it != dest.end(); it++) {
                    std::string objTemp = it->get_str();
                    ingredientsList.push_back(objTemp);
                }

                Mainmeal meal = Mainmeal(obj[0].value_.get_str(), obj[1].value_.get_str(), obj[2].value_.get_str(), obj[2].value_.get_str(),
                                         obj[4].value_.get_bool(),
                                         obj[5].value_.get_int(), ingredientsList, obj[6].value_.get_real(), "");
                meals.push_back(meal);
            }
            Order order = Order(meals, arr[i].get_obj()[3].value_.get_str(), arr[i].get_obj()[1].value_.get_real());
            order.setId(arr[i].get_obj()[0].value_.get_str());
            orders.push_back(order);
            std::string price = to_string(order.totalPrice());
            price = price.substr(0, price.length() - 4);
            std::string item = order.getId() + " - Zamowienie kwota: " + price;
            std::string date = "";
            try {
                date = arr[i].get_obj()[5].value_.get_str();
                date = date.substr(0, date.length() - 8);
            }
            catch (exception e) {
                date = "No date";
            }
            item += " " + date;
            ui->listWidget->addItem(QString::fromStdString(item));
        }
    }
    else{
        QMessageBox::information(this, "Error", "Error during getting client orders");
    }
}

ClientDetails::~ClientDetails()
{
    delete ui;
}

void ClientDetails::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    std::string itemText = (item->text()).toStdString();
    std::string itemName = "";
    for(int i=0; i<itemText.length(); i++){
        if(itemText[i]=='-'){
            break;
        }
        else{
            cout<<itemName<<'\n';
            itemName+=itemText[i];
        }
    }
    itemName = itemName.substr(0, itemName.length()-1);

    YourOrderDetails yourOrderDetails(itemName);
    yourOrderDetails.setModal(true);
    yourOrderDetails.exec();
}