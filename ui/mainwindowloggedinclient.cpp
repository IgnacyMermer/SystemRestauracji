#include "mainwindowloggedinclient.h"
#include "ui_mainwindowloggedinclient.h"
#include <iostream>
#include <curlpp/cURLpp.hpp>
#include <curlpp/Options.hpp>
#include <json_spirit.h>
#include <vector>
#include <QMessageBox>
#include "../data/GetData.h"
#include <string>
#include "../meals/Mainmeal.h"
#include "../meals/Ingredient.h"
#include <iomanip>
#include <sstream>
#include "../orders/Order.h"
#include "../UserData.h"
#include "../data/PostData.h"
#include "../ui/mainwindow.h"
#include "../ui/yourdata.h"
#include "../ui/yourorders.h"
#include "./mealdetails.h"

using namespace std;
using namespace json_spirit;

MainWindowLoggedInClient::MainWindowLoggedInClient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainWindowLoggedInClient)
{
    totalPrice = 0;
    ui->setupUi(this);
    GetData getData = GetData("http://localhost:3000/meals/getallmealsavailable");
    getData.send_request();
    string s = getData.getResponse();
    if(getData.getHttpCode() == 200){
        Value value;
        read( getData.getResponse(), value );
        Array& arr = value.get_obj()[0].value_.get_array();
        meals = getData.getMeals(arr);
        for(int i=0; i<meals.size(); i++){
            Meal meal = meals[i];
            std::stringstream stream;
            stream << std::fixed << std::setprecision(2) << meal.getPrice();
            std::string s = stream.str();
            string itemText = meal.getName()+" - "+ s + "zł";
            ui->listWidget_meals->addItem(QString::fromStdString(itemText));
        }
    }
    else{
        QMessageBox::information(this, "Meals", "Error during getting meals");
    }
}

MainWindowLoggedInClient::~MainWindowLoggedInClient()
{
    delete ui;
}

void MainWindowLoggedInClient::on_pushButton_yourData_clicked()
{
    YourData yourData;
    yourData.setModal(true);
    yourData.exec();
}


void MainWindowLoggedInClient::on_pushButton_yourOrders_clicked()
{
    YourOrders yourOrders;
    yourOrders.setModal(true);
    yourOrders.exec();
}


void MainWindowLoggedInClient::on_pushButton_logOut_clicked()
{
    UserData::setId("");
    this->hide();
    UserData::mainwindowScreen->show();
}


void MainWindowLoggedInClient::on_pushButton_addToOrder_clicked()
{
    Meal* chosenMeal;
    for(int i=0; i<meals.size(); i++){
        string text = (ui->listWidget_meals->currentItem()->text()).toStdString();
        string mealName = "";
        for(int i=0; i<text.length(); i++){
            if(text[i]=='-'){
                break;
            }
            else{
                mealName+=text[i];
            }
        }
        mealName = mealName.substr(0, mealName.length()-1);
        if(mealName == meals[i].getName()){
            chosenMeal = &meals[i];
            break;
        }
    }
    yourOrder.push_back(chosenMeal);
    totalPrice += chosenMeal->getPrice();
    stringstream stream;
    stream << std::fixed << std::setprecision(2) << totalPrice;
    string s = stream.str();
    string priceText = "Cena całkowita: "+s+" zł";
    ui->label_totalPrice->setText(QString::fromStdString(priceText));
    stringstream stream2;
    stream2 << std::fixed << std::setprecision(2) << chosenMeal->getPrice();
    string s2 = stream2.str();
    string itemText = chosenMeal->getName()+"\t-\t"+ s2 + "zł";
    ui->listWidget_yourOrder->addItem(QString::fromStdString(itemText));
}

void MainWindowLoggedInClient::on_pushButton_removeFromOrder_clicked()
{
    Meal* chosenMeal;
    for(int i=0; i<meals.size(); i++){
        string text = (ui->listWidget_yourOrder->currentItem()->text()).toStdString();
        string mealName = "";
        for(int i=0; i<text.length(); i++){
            if(text[i]=='-'){
                break;
            }
            else{
                mealName+=text[i];
            }
        }
        mealName = mealName.substr(0, mealName.length()-1);
        if(mealName == meals[i].getName()){
            chosenMeal = &meals[i];
            break;
        }
    }
    vector<Meal*> newYourOrder;
    bool deleted = false;
    for(int j=0; j<yourOrder.size(); j++){
        if(yourOrder[j]->getId()!=chosenMeal->getId() || deleted){
            newYourOrder.push_back(yourOrder[j]);
        }
        else{
            deleted=true;
        }
    }
    yourOrder = newYourOrder;
    //yourOrder = remove(yourOrder.begin(), yourOrder.end(),chosenMeal);
    totalPrice -= chosenMeal->getPrice();

    stringstream stream;
    stream << std::fixed << std::setprecision(2) << totalPrice;
    string s = stream.str();
    string priceText = "Cena całkowita: "+s+" zł";
    ui->label_totalPrice->setText(QString::fromStdString(priceText));
    QListWidgetItem *it = ui->listWidget_yourOrder->takeItem(ui->listWidget_yourOrder->currentRow());
    delete it;
}


void MainWindowLoggedInClient::on_pushButton_removeOrder_clicked()
{
    ui->listWidget_yourOrder->clear();
    yourOrder.clear();
    totalPrice = 0;
    string priceText = "Cena całkowita: ";
    ui->label_totalPrice->setText(QString::fromStdString(priceText));
}


void MainWindowLoggedInClient::on_pushButton_confirmOrder_clicked()
{
    vector<Meal> orderMeals;
    string mealsIDs = "";
    for(int i=0; i<yourOrder.size(); i++){
        if(mealsIDs!=""){
            mealsIDs+=", ";
        }
        orderMeals.push_back(*yourOrder[i]);
        mealsIDs+="\""+yourOrder[i]->getId()+"\"";
    }
    Order order = Order(orderMeals, UserData::getId(), totalPrice);
    string body = "{";
    body+="\"clientId\": \""+UserData::getId()+"\", \"totalPrice\": "+to_string(totalPrice)+", \"mealsIds\": [";
    body+=mealsIDs+"]}";
    PostData postData = PostData("http://localhost:3000/order/addneworder", body);
    postData.send_request();
    if(postData.getHttpCode()==200){
        QMessageBox::information(this, "Zamowienie", "Zamowienie dodane");
        Value value;
        string s = postData.getResponse();
        read( s, value );
        order.setId(value.get_obj()[0].value_.get_obj()[3].value_.get_str());
        ui->listWidget_yourOrder->clear();
        yourOrder.clear();
        totalPrice = 0;
        string priceText = "Cena całkowita: ";
        ui->label_totalPrice->setText(QString::fromStdString(priceText));
    }
    else{
        QMessageBox::information(this, "Zamowienie", "Wystapil blad");
    }

}

void MainWindowLoggedInClient::on_listWidget_meals_itemDoubleClicked(QListWidgetItem *item){
    std::string itemText = (item->text()).toStdString();
    std::string name = "";
    for(int i=0; i<itemText.length(); i++){
        if(itemText[i]=='-'){
            break;
        }
        else{
            name+=itemText[i];
        }
    }
    name = name.substr(0, name.length()-1);
    Meal chosenMeal;
    for(int i=0; i<meals.size(); i++){
        if(meals[i].getName()==name){
            chosenMeal = meals[i];
        }
    }
    MealDetails mealDetails(chosenMeal);
    mealDetails.setModal(this);
    mealDetails.exec();
}
