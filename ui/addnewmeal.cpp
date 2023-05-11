#include "addnewmeal.h"
#include "ui_addnewmeal.h"
#include <iostream>
#include <curlpp/cURLpp.hpp>
#include <curlpp/Options.hpp>
#include <json_spirit.h>
#include <vector>
#include <QMessageBox>

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
    cout<<"lalal";
    ui->setupUi(this);
    cout<<"lalal0";

    CURL *curl;
    CURLcode res;
    struct curl_slist *headers = NULL;
    string s;

    curl = curl_easy_init();

    //headers = curl_slist_append(headers, "Expect:");
    //headers = curl_slist_append(headers, "Content-Type: application/json");
    //curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

    curl_easy_setopt(curl, CURLOPT_URL, "http://localhost:3000/meals/getallingredients");

    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &s);

    res = curl_easy_perform(curl);

    long http_code = 0;
    curl_easy_getinfo (curl, CURLINFO_RESPONSE_CODE, &http_code);
    if(http_code==200){
        Value value;

        cout<<s<<'\n';
        read( s, value );
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

