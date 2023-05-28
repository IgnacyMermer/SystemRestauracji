#include "Meal.h"
#include <vector>
#include <string>
#include "Ingredient.h"


using namespace std;

class Mainmeal:public Meal{
    string type;

public:
    Mainmeal(string id, string shortname, string name, string description, bool availability, int productsCount, vector<Ingredient> ingredients,double price,string type):Meal(id, shortname, name, description, availability, productsCount, ingredients, price){}
    Mainmeal(string id, string shortname, string name, string description, bool availability, int productsCount, vector<string> ingredients,double price,string type):Meal(id, shortname, name, description, availability, productsCount, ingredients, price){}
};