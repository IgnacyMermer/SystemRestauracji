#include "Meal.h"
#include <vector>
#include <string>
#include "Ingredient.h"


using namespace std;

class Mainmeal: public Meal{
    string type;

    public:
        Mainmeal(int id, std::string shortname, std::string name, bool availability, int productsCount,vector<Ingredient> ingredients,double price,string type): Meal(id,shortname,name,availability,productsCount,ingredients,price){
        bool availabilityTemp = true;
        for(int i=0; i<ingredients.size(); i++){
            if(!ingredients[i].checkAvailability()){
                availabilityTemp = false;
                break;
            }
        }
        availability = availabilityTemp;
    }
    void refreshAvailability(){return Meal::refreshAvailability();};
    double getPrice(){return Meal::getPrice();};
    bool getAvailability(){return Meal::getAvailability();};
    vector<Ingredient> getIngredients(){return Meal::getIngredients();};
    void refreshProductsCount(){return Meal::refreshProductsCount();};

    
};