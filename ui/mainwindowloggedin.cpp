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
#include "yourdata.h"
#include "./yourclients.h"

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
    this->hide();
    YourData yourData;
    yourData.setModal(true);
    yourData.exec();
}


void mainwindowloggedin::on_pushButton_YourClients_clicked()
{
    YourClients yourClients;
    yourClients.setModal(true);
    yourClients.exec();
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
