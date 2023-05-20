#include "yourorderdetails.h"
#include "ui_yourorderdetails.h"
#include "../data/GetData.h"
#include <QMessageBox>
#include <json_spirit.h>
#include <iomanip>
#include <sstream>
#include "../meals/Meal.h"

using namespace json_spirit;
using namespace std;

YourOrderDetails::YourOrderDetails(std::string id, QWidget *parent) :
    QDialog(parent),
    orderId(id),
    ui(new Ui::YourOrderDetails)
{
    ui->setupUi(this);
    cout<<orderId<<'\n';
    string url = "http://localhost:3000/order/getorder/"+orderId;
    cout<<url<<'\n';
    GetData getData = GetData(url);
    getData.send_request();
    if(getData.getHttpCode()==200){
        Value value;
        read( getData.getResponse(), value );
        string price = to_string(value.get_obj()[0].value_.get_obj()[1].value_.get_real());
        price = price.substr(0, price.length()-3);
        ui->label_price->setText(QString::fromStdString(price));
        vector<Meal> meals = getData.getMealsWithoutMeals(value.get_obj()[0].value_.get_obj()[2].value_.get_array());
        for(int i=0; i<meals.size(); i++){
            ui->listWidget_meals->addItem(QString::fromStdString(meals[i].getName()));
        }
    }
    else{
        cout<<getData.getResponse();
        QMessageBox::information(this, "Error", "There was an error during getting order details");
    }
}

YourOrderDetails::~YourOrderDetails()
{
    delete ui;
}

void YourOrderDetails::on_pushButton_goBack_clicked()
{
    this->hide();
}

void YourOrderDetails::setOrderId(std::string newOrderId) {
    orderId = newOrderId;
}