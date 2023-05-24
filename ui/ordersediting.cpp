#include "ordersediting.h"
#include "ui_ordersediting.h"
#include "../data/GetData.h"
#include "../data/PostData.h"
#include "json_spirit.h"
#include <QMessageBox>
#include "../meals/Mainmeal.h"
#include "../meals/Meal.h"
#include "../orders/Order.h"
#include <QListWidgetItem>
#include "./orderdetails.h"

using namespace std;
using namespace json_spirit;

ordersEditing::ordersEditing(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ordersEditing)
{
    ui->setupUi(this);
    GetData getData = GetData("http://localhost:3000/order/getallorders");
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
            Order order = Order(meals, arr[i].get_obj()[3].value_.get_obj()[0].value_.get_str(), arr[i].get_obj()[1].value_.get_real(),
                                arr[i].get_obj()[3].value_.get_obj()[4].value_.get_str(), arr[i].get_obj()[4].value_.get_str());
            order.setId(arr[i].get_obj()[0].value_.get_str());
            orders.push_back(order);
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
            ui->listWidget->addItem(QString::fromStdString(item));
        }
    }
    else{
        QMessageBox::information(this, "Error", "Error during getting orders");
    }

}

ordersEditing::~ordersEditing()
{
    delete ui;
}

void ordersEditing::on_pushButton_comeback_clicked()
{
    this->hide();
}


void ordersEditing::on_pushButton_orderDone_clicked()
{
    string itemText = ui->listWidget->currentItem()->text().toStdString();
    string id = "";
    for(int i=0; i<itemText.length(); i++){
        if(itemText[i]=='-'){
            break;
        }
        else{
            id+=itemText[i];
        }
    }
    id = id.substr(0, id.length()-1);
    /*Order chosenOrder;
    for(int i=0; i<orders.size(); i++){
        if(itemText==orders[i].getId()){
            chosenOrder = orders[i];
        }
    }*/
    PostData postData = PostData("http://localhost:3000/order/setstatusdone/"+id, "");
    postData.send_request();
    if(postData.getHttpCode()==200){
        QListWidgetItem *it = ui->listWidget->takeItem(ui->listWidget->currentRow());
        delete it;
        vector<Order> newOrders;
        for(int i=0; i<orders.size(); i++){
            if(orders[i].getId()!=id){
                newOrders.push_back(orders[i]);
            }
        }
    }
    else{
        QMessageBox::information(this, "Error", "Error while changing order status");
    }

}


void ordersEditing::on_pushButton_showDetails_clicked()
{
    string itemText = ui->listWidget->currentItem()->text().toStdString();
    string id = "";
    for(int i=0; i<itemText.length(); i++){
        if(itemText[i]=='-'){
            break;
        }
        else{
            id+=itemText[i];
        }
    }
    id = id.substr(0, id.length()-1);
    Order chosenOrder;
    for(int i=0; i<orders.size(); i++){
        if(id==orders[i].getId()){
            chosenOrder = orders[i];
        }
    }
    OrderDetails orderDetails(chosenOrder);
    orderDetails.setModal(true);
    orderDetails.exec();
}

