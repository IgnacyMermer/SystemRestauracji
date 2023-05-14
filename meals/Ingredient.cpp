#include "Ingredient.h"


Ingredient::Ingredient(int id, std::string name, std::string shortname, bool availability, int productsCount){
    int foodid = id; 
    string foodshortname = shortname;
    string foodname = name;
    bool foodavailability = availability;
    int foodproductsCount = productsCount;
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