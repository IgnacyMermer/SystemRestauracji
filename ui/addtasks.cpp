#include "addtasks.h"
#include "ui_addtasks.h"
#include "../data/GetData.h"
#include "../data/PostData.h"
#include <QMessageBox>
#include "json_spirit.h"
#include "../employees/Employee.h"
#include "../UserData.h"


using namespace json_spirit;

AddTasks::AddTasks(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddTasks)
{
    ui->setupUi(this);
    GetData getData = GetData("http://localhost:3000/employees/getallemploees");
    getData.send_request();
    if(getData.getHttpCode()==200){
        Value value;
        read(getData.getResponse(), value);
        Array& arr = value.get_obj()[0].value_.get_array();
        for(int i=0; i<arr.size(); i++){
            Employee employee = Employee(arr[i].get_obj()[0].value_.get_str(), arr[i].get_obj()[4].value_.get_str(),
                                         arr[i].get_obj()[3].value_.get_str(), arr[i].get_obj()[1].value_.get_str());
            employees.push_back(employee);
            ui->listWidget_employees->addItem(QString::fromStdString(employee.name()+" - "+employee.email()));
        }
    }
    else{
        QMessageBox::information(this, "Error", "Error during get clients");
    }
}

AddTasks::~AddTasks()
{
    delete ui;
}

void AddTasks::on_pushButton_comeback_clicked()
{
    this->hide();
}

void AddTasks::on_pushButton_confirm_clicked() {
    std::string title = ui->lineEdit_title->text().toStdString();
    std::string description = ui->textEdit_description->toPlainText().toStdString();
    std::string itemtextS = ui->listWidget_employees->currentItem()->text().toStdString();
    std::string employeeName = "";
    std::string employeeLogin = "";
    bool addToName=true;
    for(int i=0; i<itemtextS.length(); i++){
        if(itemtextS[i]=='-'){
            addToName=false;
        }
        else if(addToName){
            employeeName+=itemtextS[i];
        }
        else{
            employeeLogin+=itemtextS[i];
        }
    }
    employeeName = employeeName.substr(0, employeeName.length()-1);
    employeeLogin = employeeLogin.substr(1);
    Employee chosenEmployee;
    for(int i=0; i<employees.size(); i++){
        if(employees[i].name()==employeeName&&employees[i].email()==employeeLogin){
            chosenEmployee=employees[i];
            break;
        }
    }
    std::cout<<chosenEmployee.email();
    std::cout<<chosenEmployee.id();
    std::cout<<"lala";
    std::string body = "{\"name\": \""+title+"\", \"description\": \""+description+"\", \"employeeId\": \""+chosenEmployee.id()+"\", ";
    body+= "\"bossId\": \""+UserData::getId()+"\"}";
    PostData postData = PostData("http://localhost:3000/task/addnewtask", body);
    postData.send_request();
    if(postData.getHttpCode()==200){
        this->hide();
        QMessageBox::information(this, "Success", "Task added");
    }
    else{
        QMessageBox::information(this, "Error", "Error during adding task");
    }
}
