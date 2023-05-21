#include "addnewmeal.h"
#include "ui_addnewmeal.h"
#include <iostream>
#include <curlpp/cURLpp.hpp>
#include <curlpp/Options.hpp>
#include <json_spirit.h>
#include <vector>
#include <QMessageBox>
#include "../data/GetData.h"
#include "../meals/Ingredient.h"
#include "../data/PostData.h"

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
            Ingredient ingredient = Ingredient(obj[0].value_.get_str(), obj[2].value_.get_str(), obj[1].value_.get_str(),
                                               obj[3].value_.get_bool(), obj[4].value_.get_int());
            ingredients.push_back(ingredient);
            ui->listWidget_ingredientsToChoose->addItem(QString::fromStdString(ingredient.getName()));
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
    const QString& countText = QString::fromStdString(" - Ilość: ");
    ui->listWidget_chosenIngredients->addItem(s+countText+sCount);
}


void AddNewMeal::on_pushButton_removeIngredient_clicked()
{
    string itemText = ui->listWidget_chosenIngredients->currentItem()->text().toStdString();
    string ingredientName="";
    for(int i=0; i<itemText.length(); i++){
        if(itemText[i]=='-'){
            break;
        }
        else{
            ingredientName+=itemText[i];
        }
    }
    itemText = itemText.substr(0, itemText.length()-1);
    vector<Ingredient> newIngredients;
    bool deleted = false;
    for(int j=0; j<ingredients.size(); j++){
        if(ingredients[j].getName()!=itemText || deleted){
            newIngredients.push_back(ingredients[j]);
        }
        else{
            deleted=true;
        }
    }
    ingredients = newIngredients;
    QListWidgetItem *it = ui->listWidget_chosenIngredients->takeItem(ui->listWidget_chosenIngredients->currentRow());
    delete it;
}


void AddNewMeal::on_pushButton_confirm_clicked()
{
    string name = ui->lineEdit_mealName->text().toStdString();
    string priceStr = ui->lineEdit_price->text().toStdString();
    string description = ui->textEdit_mealPrepareDescription->toPlainText().toStdString();
    string body = "{\"shortName\":\""+name+"\", \"name\":\""+name+"\", \"description\":\""+description+"\",";
    body+=" \"productsCount\": 100, \"price\":"+priceStr+", \"ingredients\": [";
    for(int i=0; i<ingredients.size(); i++){
        string itemBody = "";
        Ingredient ingredient = ingredients[i];
        itemBody+="{\"_id\": \""+ingredient.getId()+"\", ";
        itemBody+="\"shortName\": \""+ingredient.getName()+"\", \"name\": \""+ingredient.getName()+"\", ";
        itemBody+="\"availability\": true, \"productsCount\": 100}";
        body+=itemBody+", ";
    }
    body = body.substr(0, body.length()-2);
    //body+="{\"_id\": \"645cfbd6f1aa6a220b7b4268\", \"shortName\": \"Ogórki zielone\", \"name\": \"Ogórki zielone\", \"availability\": true, \"productsCount\": 100}";
    body+="], \"type\": \"meal\"}";
    cout<<body;
    PostData postData = PostData("http://localhost:3000/meals/addnewmeal", body);
    postData.send_request();
    if(postData.getHttpCode()==200){
        this->hide();
        QMessageBox::information(this, "Meal", "Meal added");
    }
    else{
        QMessageBox::information(this, "Meal", "Error during adding meal");
    }
}

