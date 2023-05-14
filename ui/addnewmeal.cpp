#include "addnewmeal.h"
#include "ui_addnewmeal.h"
#include <iostream>
#include <curlpp/cURLpp.hpp>
#include <curlpp/Options.hpp>
#include <json_spirit.h>
#include <vector>
#include <QMessageBox>
#include "../data/GetData.h"

using namespace std;
using namespace json_spirit;

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}


AddNewMeal::AddNewMeal(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddNewMeal)
{
    ui->setupUi(this);

    GetData getData = GetData("http://localhost:3000/meals/getallingredients");
    getData.send_request();
    if(getData.getHttpCode()==200){
        Value value;
        //string s = getData.getResponse();
        read( getData.getResponse(), value );
        Array& arr = value.get_obj()[0].value_.get_array();
        for(int i=0; i<arr.size(); i++){
            Object& obj = arr[i].get_obj();
            ui->listWidget_ingredientsToChoose->addItem(QString::fromStdString(obj[2].value_.get_str()));
        }
    }
    else{
        QMessageBox::information(this, "Ingredients", "houston we have problem");
    }
}

AddNewMeal::~AddNewMeal()
{
    delete ui;
}

void AddNewMeal::on_pushButton_addIngredient_clicked()
{
    const QString& s = ui->listWidget_ingredientsToChoose->currentItem()->text();
    const QString& sCount = ui->lineEdit_newIngredientCount->text();
    ui->listWidget_chosenIngredients->addItem(s+sCount);
}


void AddNewMeal::on_pushButton_removeIngredient_clicked()
{

}


void AddNewMeal::on_pushButton_confirm_clicked()
{

}

