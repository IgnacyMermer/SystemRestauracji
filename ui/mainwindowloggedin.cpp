#include "mainwindowloggedin.h"
#include "ui_mainwindowloggedin.h"
#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <json_spirit.h>
#include <vector>
#include <string>
#include "../data/GetData.h"
#include "mealsediting.h"

using namespace curlpp::options;
using namespace json_spirit;
using namespace std;

mainwindowloggedin::mainwindowloggedin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mainwindowloggedin)
{
    ui->setupUi(this);
}

mainwindowloggedin::~mainwindowloggedin()
{
    delete ui;
}



void mainwindowloggedin::on_pushButton_YourData_clicked()
{
    ui->listWidget->addItem("lalal");
    GetData getData = GetData("https://fakestoreapi.com/products");
    cout<<getData.getResponse()<<'\n';

}


void mainwindowloggedin::on_pushButton_YourClients_clicked()
{
    ui->listWidget->addItem("lalalal");
    string name;
    GetData getData = GetData("http://localhost:3000/src/app.js");
    cout<<getData.getResponse()<<'\n';
    //string jsonStr("{\"name\":\"Tom\", \"lech\":\"tom\", \"array\":{\"lechu\":[1, 2, 3]}");
    string jsonStr(getData.getResponse());

    Value value;

    read( jsonStr, value );

    QString listItem = QString::fromStdString(value.get_obj()[0].value_.get_str());
    QString temp = "lalalal";
    ui->listWidget->addItem(listItem);
    std::cout<<value.get_obj()[0].value_.get_str();
}


void mainwindowloggedin::on_pushButton_closeRestaurant_clicked()
{

}


void mainwindowloggedin::on_pushButton_changeAvailabilityMeals_clicked()
{
    MealsEditing mealsEditing;
    mealsEditing.setModal(true);
    mealsEditing.exec();
}


void mainwindowloggedin::on_pushButton_changeAvailabilityIngredients_clicked()
{

}


void mainwindowloggedin::on_pushButton_confirmOrder_clicked()
{

}
