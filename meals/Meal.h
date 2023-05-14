#ifndef PROJEKTPROI2_MEAL_H
#define PROJEKTPROI2_MEAL_H

#include <iostream>
#include "Ingredient.h"
#include <vector>

using namespace std;

class Meal: public Ingredient {

    vector<Ingredient> ingredients;
    double price;
public:
    Meal(int id, std::string shortname, std::string name, bool availability, int productsCount,vector<Ingredient> ingredients, double price): Ingredient(id,shortname,name,availability,productsCount){
        bool availabilityTemp = true;
        for(int i=0; i<ingredients.size(); i++){
            if(!ingredients[i].checkAvailability()){
                availabilityTemp = false;
                break;
            }
        }
        availability = availabilityTemp;
    }


    virtual void refreshAvailability() =0;
    void refreshPrice(double price);
    virtual double getPrice() =0;
    virtual bool getAvailability()=0;
    virtual vector<Ingredient> getIngredients()=0;
    virtual void refreshProductsCount()=0; //maybe it could check ingredients counts and set meal count.
    


private:

};


#endif //PROJEKTPROI2_MEAL_H
