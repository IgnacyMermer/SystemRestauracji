#include "Meal.h"
#include <vector>
#include <string>
#include "Ingredient.h"
#include "drink.h"

Drink::Drink(int id, std::string shortname, std::string name, bool availability, int productsCount,vector<Ingredient> ingredients,double price,string type): Meal(id,shortname,name,availability,productsCount,ingredients,price){
    this -> type = type;
 }