#include "yourorders.h"
#include "ui_yourorders.h"
#include "../ui/mainwindowloggedinclient.h"
#include "../data/GetData.h"
#include "../UserData.h"
#include "QMessageBox"
#include "./yourorderdetails.h"
#include "../orders/Order.h"
#include <vector>
#include "../meals/Mainmeal.h"


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
        Array& arr = value.get_obj()[0].value_.get_array();
        for(int i=0; i<arr.size(); i++){
            vector<Meal> meals;
            Array& arrMeals = arr[i].get_obj()[2].value_.get_array();
            for(int j=0; j<arrMeals.size(); j++){
                json_spirit::Object& obj = arrMeals[j].get_obj();

                std::vector<json_spirit::Value> dest = obj[7].value_.get_array();
                vector<json_spirit::Value>::iterator it;
                vector<string> ingredientsList;

                for(it = dest.begin(); it!=dest.end(); it++){
                    std::string objTemp = it->get_str();
                    ingredientsList.push_back(objTemp);
                }

                Mainmeal meal = Mainmeal(obj[0].value_.get_str(), obj[1].value_.get_str(), obj[2].value_.get_str(), obj[4].value_.get_bool(),
                                         obj[5].value_.get_int(), ingredientsList, obj[6].value_.get_real(), "");
                meals.push_back(meal);
            }
            Order order = Order(meals, arr[i].get_obj()[3].value_.get_str(), arr[i].get_obj()[1].value_.get_real(),
                                arr[i].get_obj()[3].value_.get_str(), arr[i].get_obj()[4].value_.get_str());
            order.setId(arr[i].get_obj()[0].value_.get_str());
            if(order.getStatus()=="done"){
                ordersDone.push_back(order);
            }
            else{
                orders.push_back(order);
            }
            string price = to_string(order.totalPrice());
            price = price.substr(0, price.length()-4);
            string item = order.getId()+" - Zamowienie kwota: "+price;
            string date = "";
            try{
                date = arr[i].get_obj()[5].value_.get_str();
                date = date.substr(0, date.length()-8);
            }
            catch(exception e){
                date = "No date";
            }
            item += " "+date;
            if(order.getStatus()=="done"){
                ui->listWidget_yourOrdersDone->addItem(QString::fromStdString(item));
            }
            else{
                ui->listWidget_yourOrders->addItem(QString::fromStdString(item));
            }

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
}

void YourOrders::on_listWidget_yourOrders_itemDoubleClicked(QListWidgetItem *item)
{
    std::string itemText = (item->text()).toStdString();
    std::string itemName = "";
    for(int i=0; i<itemText.length(); i++){
        if(itemText[i]=='-'){
            break;
        }
        else{
            itemName+=itemText[i];
        }
    }
    itemName = itemName.substr(0, itemName.length()-1);

    YourOrderDetails yourOrderDetails(itemName);
    yourOrderDetails.setModal(true);
    yourOrderDetails.exec();
}

void YourOrders::on_listWidget_yourOrdersDone_itemDoubleClicked(QListWidgetItem *item)
{
    std::string itemText = (item->text()).toStdString();
    std::string itemName = "";
    for(int i=0; i<itemText.length(); i++){
        if(itemText[i]=='-'){
            break;
        }
        else{
            itemName+=itemText[i];
        }
    }
    itemName = itemName.substr(0, itemName.length()-1);

    YourOrderDetails yourOrderDetails(itemName);
    yourOrderDetails.setModal(true);
    yourOrderDetails.exec();
}
