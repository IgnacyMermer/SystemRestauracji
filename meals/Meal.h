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
    string description;
    bool availability;
    int productsCount;
    vector<Ingredient> ingredients;
    double price;
public:
    Meal(){}
    Meal(string id, std::string shortname, std::string name, std::string description, bool availability, int productsCount,vector<Ingredient> ingredients, double price);
    Meal(string id, std::string shortname, std::string name, std::string description, bool availability, int productsCount,vector<string> ingredients, double price);

    void refreshPrice(double price);
    void refreshAvailability(){

    }
    string getDescription(){
        return description;
    }
    string getName(){
        return name;
    }
    string getShortName(){
        return shortname;
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
