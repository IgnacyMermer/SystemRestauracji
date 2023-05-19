#include "Meal.h"
#include <vector>
#include <string>
#include "Ingredient.h"

using namespace std;


Meal::Meal(string id, std::string shortname, std::string name, bool availability, int productsCount,vector<Ingredient> ingredients,double price){
    this->id = id;
    this->shortname = shortname;
    this->name = name;
    this->availability = availability;
    this->productsCount = productsCount;
    this -> price = price;
    this -> ingredients = ingredients;
}


void Meal::refreshPrice(double price) {
    this->price = price;
}


