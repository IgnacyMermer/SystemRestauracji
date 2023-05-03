#ifndef PROJEKTPROI2_MEAL_H
#define PROJEKTPROI2_MEAL_H

#include <iostream>
#include "Ingredient.h"

using namespace std;

class Meal {
public:
    Meal(vector<Ingredient> ingredients): ingredients(ingredients){
        //available = true;
    }
    int id;
    vector<Ingredient> ingredients;
    bool available;


private:

};


#endif //PROJEKTPROI2_MEAL_H
