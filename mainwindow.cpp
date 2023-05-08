#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include "mainwindowloggedin.h"
#include <curlpp/cURLpp.hpp>
#include <curlpp/Options.hpp>
#include <cstdarg>
#include <json_spirit.h>
#include <string>

using namespace std;
using namespace json_spirit;

size_t writeToString(void *contents, size_t size, size_t nmemb, string *s)
{
    size_t newLength = size*nmemb;
    try
    {
        s->append((char*)contents, newLength);
    }
    catch(bad_alloc &e)
    {
        return 0;
    }
    return newLength;
}

mainwindow::mainwindow(QWidget *parent)
        : QMainWindow(parent)
        , ui(new Ui::mainwindow)
{
    ui->setupUi(this);
}

mainwindow::~mainwindow()
{
    delete ui;
}

void mainwindow::on_pushButton_Login_clicked(){

    string username = (ui->lineEdit_username->text()).toStdString();
    string password = (ui->lineEdit_password->text()).toStdString();

    CURL *curl;
    CURLcode res;
    struct curl_slist *headers = NULL;
    string s;

    curl = curl_easy_init();

    headers = curl_slist_append(headers, "Expect:");
    headers = curl_slist_append(headers, "Content-Type: application/json");
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

    curl_easy_setopt(curl, CURLOPT_URL, "http://localhost:3000/signin");

    string body = "{\"login\" : \""+username+"\", \"password\": \""+password+"\"}";
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, body.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeToString);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &s);

    res = curl_easy_perform(curl);

    long http_code = 0;
    curl_easy_getinfo (curl, CURLINFO_RESPONSE_CODE, &http_code);

    if(http_code==200){
        Value value;

        cout<<s<<'\n';
        read( s, value );
        cout<<value.get_obj()[0].value_.get_obj()[0].value_.get_str();

        this->hide();
        mainwindowloggedin mainWindowLoggedIn;
        mainWindowLoggedIn.setModal(true);
        mainWindowLoggedIn.exec();
    }
    else{
        QMessageBox::information(this, "Login", "Wrong credentials");
    }
}
