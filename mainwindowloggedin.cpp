#include "mainwindowloggedin.h"
#include "ui_mainwindowloggedin.h"
#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <json_spirit.h>
#include <vector>

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

size_t write_to_string(void *ptr, size_t size, size_t count, void *stream) {
    ((string*)stream)->append((char*)ptr, 0, size*count);
    return size*count;
}

void mainwindowloggedin::on_pushButton_YourData_clicked()
{
    ui->listWidget->addItem("lalal");
    cURLpp::Cleanup myCleanup;
    CURL *curl;
    CURLcode res;
    curl = curl_easy_init();
    curl_easy_setopt(curl, CURLOPT_URL, "https://fakestoreapi.com/products");

    string response;
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_to_string);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
    res = curl_easy_perform(curl);

    res = curl_easy_perform(curl);
    cout<<response<<'\n';
    cout<<res<<'\n';
    curl_easy_cleanup(curl);
}


void mainwindowloggedin::on_pushButton_YourClients_clicked()
{
    cout<<"lala";
    //ui->listWidget->addItem("lalalal");
    string name;
    string jsonStr("{\"name\":\"Tom\", \"lech\":\"tom\", \"array\":{\"lechu\":[1, 2, 3]}");

    Value value;

    read( jsonStr, value );

    QString listItem = QString::fromStdString(to_string(value.get_obj()[2].value_.get_obj()[0].value_.get_array()[2].get_int()));
    QString temp = "lalalal";
    ui->listWidget->addItem(listItem);
    std::cout<<std::to_string(value.get_obj()[2].value_.get_obj()[0].value_.get_array()[2].get_int());
}


void mainwindowloggedin::on_pushButton_closeRestaurant_clicked()
{

}


void mainwindowloggedin::on_pushButton_changeAvailabilityMeals_clicked()
{

}


void mainwindowloggedin::on_pushButton_changeAvailabilityIngredients_clicked()
{

}


void mainwindowloggedin::on_pushButton_confirmOrder_clicked()
{

}
