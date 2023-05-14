#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include "mainwindowloggedin.h"
#include <cstdarg>
#include <json_spirit.h>
#include <string>
#include "../data/PostData.h"
#include <map>

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

    string body = "{\"login\" : \""+username+"\", \"password\": \""+password+"\"}";
    //map<string, string> body = {};
    //body["login"] = username;
    //body["password"] = password;
    PostData postData = PostData("http://localhost:3000/signin", body);
    postData.send_request();

    if(postData.getHttpCode()==200){
        Value value;
        string s = postData.getResponse();
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
