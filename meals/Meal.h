#ifndef PROJEKTPROI2_MEAL_H
#define PROJEKTPROI2_MEAL_H

#include <iostream>
#include "Ingredient.h"
#include <vector>

using namespace std;

class Meal{
    string id;
    string shortname;
    string name;
    bool availability;
    int productsCount;
    vector<Ingredient> ingredients;
    double price;
public:
    Meal(string id, std::string shortname, std::string name, bool availability, int productsCount,vector<Ingredient> ingredients, double price);

    void refreshPrice(double price);
    void refreshAvailability(){

    }
    string getName(){
        return name;
    }
    string getId(){
        return id;
    }
    double getPrice(){return price;}
    bool getAvailability(){return availability;}
    vector<Ingredient> getIngredients(){return ingredients;}
    void refreshProductsCount(){

    }

private:

};


#endif //PROJEKTPROI2_MEAL_H
