#include "Ingredient.h"

using namespace std;

Ingredient::Ingredient(std::string id, std::string name, std::string shortname, bool availability, int productsCount){
    foodid = id;
    foodshortname = shortname;
    foodname = name;
    foodavailability = availability;
    foodproductsCount = productsCount;
}

bool Ingredient::checkAvailability() {
    if(foodproductsCount<=0){
        foodavailability=false;
    }
    return foodavailability;
}

void Ingredient::setProductsCount(int productsCount) {
    this->foodproductsCount = productsCount;
    if(this->foodproductsCount<=0){
        foodavailability=false;
    }
    else{
        foodavailability=true;
    }
}

bool Ingredient::getAvailability(){
    return foodavailability;
}