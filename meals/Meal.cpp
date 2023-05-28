#include "Meal.h"
#include <vector>
#include <string>
#include "Ingredient.h"

using namespace std;


Meal::Meal(string id, std::string shortname, std::string name, std::string description, bool availability, int productsCount,vector<Ingredient> ingredients,double price){
    this->id = id;
    this->shortname = shortname;
    this->name = name;
    this->availability = availability;
    this->productsCount = productsCount;
    this -> price = price;
    this -> ingredients = ingredients;
    this -> description = description;
}

Meal::Meal(string id, std::string shortname, std::string name, std::string description, bool availability, int productsCount,vector<string> ingredients,double price){
    this->id = id;
    this->shortname = shortname;
    this->name = name;
    this->availability = availability;
    this->productsCount = productsCount;
    this -> price = price;
    this->description = description;
    //this -> ingredients = ingredients;
}


void Meal::refreshPrice(double price) {
    this->price = price;
}

void Meal::setProductsCount(int productsCount){
    this->productsCount = productsCount;
    if(this->productsCount<=0){
        availability=false;
    }
    else{
        availability=true;
    }
}

