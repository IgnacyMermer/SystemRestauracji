#include "Meal.h"
#include <vector>
#include <string>
#include "Ingredient.h"

using namespace std;

void Meal::refreshAvailability() {
    bool availabilityTemp = true;
    for(int i=0; i<ingredients.size(); i++){
        if(!ingredients[i].checkAvailability()){
            availabilityTemp = false;
            break;
        }
    }
    availability = availabilityTemp;
}

bool Meal::getAvailability() {
    return availability;
}

vector<Ingredient> Meal::getIngredients() {
    return ingredients;
}

void Meal::setProductsCount(int productsCount) {
    this->productsCount = productsCount;
}

void Meal::refreshPrice(double price) {
    this->price = price;
}

double Meal::getPrice() {
    return price;
}
