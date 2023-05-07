#ifndef PROJEKTPROI2_MEAL_H
#define PROJEKTPROI2_MEAL_H

#include <iostream>
#include "Ingredient.h"
#include <vector>

using namespace std;

class Meal {
public:
    Meal(vector<Ingredient> ingredients): ingredients(ingredients){
        bool availabilityTemp = true;
        for(int i=0; i<ingredients.size(); i++){
            if(!ingredients[i].checkAvailability()){
                availabilityTemp = false;
                break;
            }
        }
        availability = availabilityTemp;
    }
    int id;
    vector<Ingredient> ingredients;
    bool availability;
    double price;
    int productsCount;

    void refreshAvailability();
    void refreshPrice(double price);
    double getPrice();
    bool getAvailability();
    vector<Ingredient> getIngredients();
    void refreshProductsCount(); //maybe it could check ingredients counts and set meal count.
    void setProductsCount(int productsCount);


private:

};


#endif //PROJEKTPROI2_MEAL_H
