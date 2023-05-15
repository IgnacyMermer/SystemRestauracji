#include "mealsediting.h"
#include "ui_mealsediting.h"
#include "addnewmeal.h"
#include "addnewdrinksauce.h"
#include "../data/GetData.h"
#include "../meals/Meal.h"
#include "../meals/Ingredient.h"
#include "../meals/Mainmeal.h"
#include <iomanip>
#include <sstream>


using namespace std;
using namespace json_spirit;

MealsEditing::MealsEditing(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MealsEditing)
{
    ui->setupUi(this);
    GetData getData = GetData("http://localhost:3000/meals/getallmeals");
    getData.send_request();
    if(getData.getHttpCode() == 200){
        Value value;
        read( getData.getResponse(), value );
        Array& arr = value.get_obj()[0].value_.get_array();
        meals = getData.getMeals(arr);
        for(int i=0; i<meals.size(); i++){
            Meal meal = meals[i];
            std::stringstream stream;
            stream << std::fixed << std::setprecision(2) << meal.getPrice();
            std::string s = stream.str();
            string itemText = meal.getName()+"\t- "+ s + "zł";
            ui->listWidget_meals->addItem(QString::fromStdString(itemText));
        }

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

}


void MealsEditing::on_pushButton_removeMeal_clicked()
{

}

