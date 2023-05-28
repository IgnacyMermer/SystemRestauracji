#include "Meal.h"
#include <vector>
#include <string>
#include "Ingredient.h"


using namespace std;

class Drink: public Meal{
    string type;

    public:
        Drink(string id, std::string shortname, std::string name,string description, bool availability, int productsCount,vector<Ingredient> ingredients,double price,string type): Meal(id,shortname,name,description,availability,productsCount,ingredients,price){
        this -> type = type;
        bool availabilityTemp = true;
        for(int i=0; i<ingredients.size(); i++){
            if(!ingredients[i].checkAvailability()){
                availabilityTemp = false;
                break;
            }
        }
        availability = availabilityTemp;
    }
};