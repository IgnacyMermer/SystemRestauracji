#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include "mainwindowloggedin.h"
#include <cstdarg>
#include <json_spirit.h>
#include <string>
#include "../data/PostData.h"
#include <map>
#include "mainwindowloggedinclient.h"
#include "../UserData.h"

using namespace std;
using namespace json_spirit;

mainwindow::mainwindow(QWidget *parent)
        : QMainWindow(parent)
        , ui(new Ui::mainwindow)
{
    ui->setupUi(this);
    ui->lineEdit_password->setEchoMode(QLineEdit::Password);
    UserData::mainwindowScreen = this;
}

mainwindow::~mainwindow()
{
    delete ui;
}

void mainwindow::on_pushButton_Login_clicked(){

    string username = (ui->lineEdit_username->text()).toStdString();
    string password = (ui->lineEdit_password->text()).toStdString();

    string body = "{\"login\" : \""+username+"\", \"password\": \""+password+"\"}";
    PostData postData = PostData("http://localhost:3000/signin", body);
    postData.send_request();
    if(postData.getHttpCode()==200){
        Value value;
        string s = postData.getResponse();
        read( s, value );
        UserData::setId(value.get_obj()[0].value_.get_obj()[0].value_.get_str());
        UserData::login = value.get_obj()[0].value_.get_obj()[1].value_.get_str();
        UserData::role = value.get_obj()[0].value_.get_obj()[3].value_.get_str();
        UserData::name = value.get_obj()[0].value_.get_obj()[4].value_.get_str();
        if(value.get_obj()[0].value_.get_obj()[3].value_.get_str()=="Client"){
            this->hide();
            MainWindowLoggedInClient mainWindowLoggedInClient;
            mainWindowLoggedInClient.setModal(true);
            mainWindowLoggedInClient.exec();
        }
        else {
            this->hide();
            mainwindowloggedin mainWindowLoggedIn;
            mainWindowLoggedIn.setModal(true);
            mainWindowLoggedIn.exec();
        }
    }
    else{
        QMessageBox::information(this, "Login", "Wrong credentials");
    }
}
