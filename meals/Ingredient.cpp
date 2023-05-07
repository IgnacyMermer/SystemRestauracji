#include "Ingredient.h"

bool Ingredient::checkAvailability() {
    if(productsCount<=0){
        availability=false;
    }
    return availability;
}

void Ingredient::setProductsCount(int productsCount) {
    this->productsCount = productsCount;
    if(this->productsCount<=0){
        availability=false;
    }
}
