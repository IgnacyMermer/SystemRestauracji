#include "addnewdrinksauce.h"
#include "ui_addnewdrinksauce.h"
#include <iostream>
#include "../data/PostData.h"
#include <QMessageBox>

using namespace std;

AddNewDrinkSauce::AddNewDrinkSauce(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddNewDrinkSauce)
{
    ui->setupUi(this);
}

AddNewDrinkSauce::~AddNewDrinkSauce()
{
    delete ui;
}

void AddNewDrinkSauce::on_pushButton_confirm_clicked()
{
    string name = ui->lineEdit_name->text().toStdString();
    string description = ui->textEdit_description->toPlainText().toStdString();
    string priceStr = ui->lineEdit_price->text().toStdString();
    string type = "";
    double price = 0.0;
    if(priceStr!=""){
        try{
            replace(priceStr.begin(), priceStr.end(), ',', '.');
            price = stod(priceStr);
        }
        catch(exception e){

        }
    }
    if(ui->checkBox_sauce->isChecked()){
        type="sauce";
    }
    if(ui->checkBox_drink->isChecked()){
        type="drink";
    }
    string body = "{\"shortName\":\""+name+"\", \"name\":\""+name+"\", \"description\":\""+description+"\",";
    body+=" \"productsCount\": 100, \"price\":"+priceStr+", \"ingredients\": [], \"type\": \""+type+"\"}";
    PostData postData = PostData("http://localhost:3000/meals/addnewmeal", body);
    postData.send_request();
    if(postData.getHttpCode()==200){
        this->hide();
        QMessageBox::information(this, "Meal", "Meal added");
    }
    else{
        QMessageBox::information(this, "Meal", "Error during getting your orders");
    }
}

