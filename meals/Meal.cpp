#include "Meal.h"
#include <vector>
#include <string>
#include "Ingredient.h"

using namespace std;


Meal::Meal(int id, std::string shortname, std::string name, bool availability, int productsCount,vector<Ingredient> ingredients,double price):Ingredient(id,shortname,name,availability,productsCount){
    this -> price = price;
    this -> ingredients = ingredients;
}

void Meal::refreshAvailability() {
    bool availabilityTemp = true;
    for(int i=0; i<ingredients.size(); i++){
        if(!ingredients[i].checkAvailability()){
            availabilityTemp = false;
            break;
        }
    }
    foodavailability = availabilityTemp;
}


vector<Ingredient> Meal::getIngredients() {
    return ingredients;
}


void Meal::refreshPrice(double price) {
    this->price = price;
}

double Meal::getPrice() {
    return price;
}
