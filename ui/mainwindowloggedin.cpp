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
#include "../UserData.h"
#include <QMessageBox>
#include "../employees/Employee.h"
#include "./taskdetails.h"

using namespace curlpp::options;
using namespace json_spirit;
using namespace std;

mainwindowloggedin::mainwindowloggedin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mainwindowloggedin)
{
    ui->setupUi(this);
    string url = "http://localhost:3000/task/getemployeetask/"+UserData::getId();
    GetData getData = GetData(url);
    getData.send_request();
    if(getData.getHttpCode()==200){
        string s = getData.getResponse();
        Value value;
        read(s, value);
        Array& arr = value.get_obj()[0].value_.get_array();
        for(int i=0; i<arr.size(); i++){
            Task task = Task(arr[i].get_obj()[0].value_.get_str(), arr[i].get_obj()[1].value_.get_str(),
                             arr[i].get_obj()[2].value_.get_str(), arr[i].get_obj()[3].value_.get_str(),
                             arr[i].get_obj()[4].value_.get_str(), arr[i].get_obj()[5].value_.get_bool());
            string itemText = task.name()+" - "+task.description();
            tasks.push_back(task);
            ui->listWidget->addItem(QString::fromStdString(itemText));
        }
    }
    else{
        QMessageBox::information(this, "Error", "Error during get tasks");
    }
}

mainwindowloggedin::~mainwindowloggedin()
{
    delete ui;
}



void mainwindowloggedin::on_pushButton_YourData_clicked()
{
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
    std::string itemtextS = ui->listWidget->currentItem()->text().toStdString();
    string itemText = "";
    string itemTextDescription = "";
    bool isDescription = false;
    for(int i=0; i<itemtextS.length(); i++){
        if(itemtextS[i]=='-'){
            isDescription = true;
        }
        else{
            if(!isDescription){
                itemText+=itemtextS[i];
            }
            else{
                itemTextDescription+=itemtextS[i];
            }

        }
    }
    itemText = itemText.substr(0, itemText.length()-1);
    itemTextDescription = itemTextDescription.substr(1);
    vector<Task>::iterator iterator;
    Task chosenTask;
    for(iterator = tasks.begin(); iterator!=tasks.end(); iterator++){
        if(iterator->name() == itemText && itemTextDescription == iterator->description()){
            chosenTask = Task(iterator->getId(), iterator->name(), iterator->description(),
                              iterator->getEmployeeId(), iterator->getBossId(), iterator->isDone());
            break;
        }
    }
    TaskDetails taskDetails(chosenTask);
    taskDetails.setModal(this);
    taskDetails.exec();
}
