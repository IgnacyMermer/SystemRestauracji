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

using namespace std;
using namespace json_spirit;

MainWindowLoggedInClient::MainWindowLoggedInClient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainWindowLoggedInClient)
{
    ui->setupUi(this);
    GetData getData = GetData("http://localhost:3000/meals/getallmeals");
    getData.send_request();
    string s = getData.getResponse();
    if(getData.getHttpCode() == 200){
        Value value;
        read( getData.getResponse(), value );
        Array& arr = value.get_obj()[0].value_.get_array();
        for(int i=0; i<arr.size(); i++){
            Object& obj = arr[i].get_obj();

            std::vector<Value> dest = obj[7].value_.get_array();
            vector<Value>::iterator it;
            vector<Ingredient> ingredientsList;

            for(it = dest.begin(); it!=dest.end(); it++){
                Object& objTemp = it->get_obj();
                Ingredient ingredient = Ingredient(objTemp[0].value_.get_str(), objTemp[2].value_.get_str(), objTemp[1].value_.get_str(),
                                   objTemp[3].value_.get_bool(),objTemp[4].value_.get_int());
                ingredientsList.push_back(ingredient);
            }

            Mainmeal meal = Mainmeal(obj[0].value_.get_str(), obj[1].value_.get_str(), obj[2].value_.get_str(), obj[4].value_.get_bool(),
                             obj[5].value_.get_int(), ingredientsList, obj[6].value_.get_real(), "");
            meals.push_back(meal);
            ui->listWidget_meals->addItem(QString::fromStdString(meal.getName()));
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

}


void MainWindowLoggedInClient::on_pushButton_yourOrders_clicked()
{

}


void MainWindowLoggedInClient::on_pushButton_logOut_clicked()
{

}


void MainWindowLoggedInClient::on_pushButton_addToOrder_clicked()
{
    Meal* chosenMeal;
    for(int i=0; i<meals.size(); i++){
        if((ui->listWidget_meals->currentItem()->text()).toStdString() == meals[i].getName()){
            chosenMeal = &meals[i];
            break;
        }
    }
    yourOrder.push_back(chosenMeal);
    //cout<<chosenMeal->getName()<<'\n';
    //const QString& s = ui->listWidget_meals->currentItem()->text();
    ui->listWidget_yourOrder->addItem(QString::fromStdString(chosenMeal->getName()));
    //cout<<yourOrder[0]->getName();
}


void MainWindowLoggedInClient::on_pushButton_removeFromOrder_clicked()
{

}


void MainWindowLoggedInClient::on_pushButton_removeOrder_clicked()
{

}


void MainWindowLoggedInClient::on_pushButton_confirmOrder_clicked()
{

}

