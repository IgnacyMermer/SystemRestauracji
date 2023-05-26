#include "mealsediting.h"
#include "ui_mealsediting.h"
#include "addnewmeal.h"
#include "addnewdrinksauce.h"
#include "../data/GetData.h"
#include "../data/PostData.h"
#include "../meals/Meal.h"
#include "../meals/Ingredient.h"
#include "../meals/Mainmeal.h"
#include <iomanip>
#include <sstream>
#include <QMessageBox>


using namespace std;
using namespace json_spirit;
vector<Meal> getMealsFromDB();

MealsEditing::MealsEditing(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MealsEditing)
{
    ui->setupUi(this);
    vector<Meal> mealsTemp;
    GetData getData = GetData("http://localhost:3000/meals/getallmeals");
    getData.send_request();

    if(getData.getHttpCode() == 200){
        Value value;
        read( getData.getResponse(), value );
        Array& arr = value.get_obj()[0].value_.get_array();
        meals = getData.getMeals(arr);
    }
    for(int i=0; i<meals.size(); i++){
        Meal meal = meals[i];
        std::stringstream stream;
        stream << std::fixed << std::setprecision(2) << meal.getPrice();
        std::string s = stream.str();
        string stringAvailability = meal.getAvailability()==0?"nie":"tak";
        string itemText = meal.getName()+" - "+ s + "zł\tDostepny: "+ stringAvailability;
        ui->listWidget_meals->addItem(QString::fromStdString(itemText));
    }
}

vector<Meal> getMealsFromDB(){
    vector<Meal> mealsTemp;
    GetData getData = GetData("http://localhost:3000/meals/getallmeals");
    getData.send_request();

    if(getData.getHttpCode() == 200){
        Value value;
        read( getData.getResponse(), value );
        Array& arr = value.get_obj()[0].value_.get_array();
        mealsTemp = getData.getMeals(arr);
    }
}

MealsEditing::~MealsEditing()
{
    delete ui;
}

void MealsEditing::on_pushButton_addNewMeal_clicked()
{
    AddNewMeal addNewMeal;
    addNewMeal.setModal(true);
    addNewMeal.exec();
}

void MealsEditing::on_pushButton_addNewDrinkSauce_clicked()
{
    AddNewDrinkSauce addNewDrinkSauce;
    addNewDrinkSauce.setModal(true);
    addNewDrinkSauce.exec();
}


void MealsEditing::on_pushButton_editMeal_clicked()
{

}


void MealsEditing::on_pushButton_changeAvailabilityMeal_clicked()
{
    string text = (ui->listWidget_meals->currentItem()->text()).toStdString();
    string mealName = "";
    for(int i=0; i<text.length(); i++){
        if(text[i]!='-'){
            mealName+=text[i];
        }
        else{
            break;
        }
    }
    mealName = mealName.substr(0, mealName.length() - 1);
    string id = "";
    bool availability = false;
    for(int i=0; i<meals.size(); i++){
        if(meals[i].getName()==mealName){
            id = meals[i].getId();
            availability = !meals[i].getAvailability();
            break;
        }
    }
    if(id!=""){
        string stringAvailability = availability==0?"false":"true";
        string stringAvailabilityScreen = availability==0?"nie":"tak";
        string body = "{\"availability\":" +stringAvailability+"}";
        availability = !availability;
        PostData postData = PostData("http://localhost:3000/meals/changemealavailability/"+id, body);
        postData.send_request();
        if(postData.getHttpCode()==200){
            string itemtext = ui->listWidget_meals->currentItem()->text().toStdString();
            ui->listWidget_meals->currentItem()->setText(QString::fromStdString(itemtext.substr(0, itemtext.length()-3)+stringAvailabilityScreen));
        }
        else{

        }
    }

}


void MealsEditing::on_pushButton_removeMeal_clicked()
{
    string text = (ui->listWidget_meals->currentItem()->text()).toStdString();
    string mealName = "";
    for(int i=0; i<text.length(); i++){
        if(text[i]!='-'){
            mealName+=text[i];
        }
        else{
            break;
        }
    }
    mealName = mealName.substr(0, mealName.length() - 1);
    string id = "";
    bool availability = false;
    for(int i=0; i<meals.size(); i++){
        if(meals[i].getName()==mealName){
            id = meals[i].getId();
            availability = !meals[i].getAvailability();
            break;
        }
    }
    PostData postData = PostData("http://localhost:3000/meals/removemeal/"+id, "{}");
    postData.send_request();
    if(postData.getHttpCode()==200){
        QMessageBox::information(this, "Success", "Meal removed successfully");
    }
    else{
        QMessageBox::information(this, "Error", "Error during removing, try again later");
    }
}

void MealsEditing::on_pushButton_refresh_clicked() {
    GetData getData = GetData("http://localhost:3000/meals/getallmeals");
    getData.send_request();

    if(getData.getHttpCode() == 200){
        Value value;
        read( getData.getResponse(), value );
        Array& arr = value.get_obj()[0].value_.get_array();
        meals = getData.getMeals(arr);
    }
    ui->listWidget_meals->clear();
    for(int i=0; i<meals.size(); i++){
        Meal meal = meals[i];
        std::stringstream stream;
        stream << std::fixed << std::setprecision(2) << meal.getPrice();
        std::string s = stream.str();
        string stringAvailability = meal.getAvailability()==0?"nie":"tak";
        string itemText = meal.getName()+" - "+ s + "zł\tDostepny: "+ stringAvailability;
        ui->listWidget_meals->addItem(QString::fromStdString(itemText));
    }
}
