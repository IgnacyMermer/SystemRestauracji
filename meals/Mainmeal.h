#include "Meal.h"
#include <vector>
#include <string>
#include "Ingredient.h"


using namespace std;

class Mainmeal:public Meal{
    string type;

public:
    Mainmeal(string id, string shortname, string name, bool availability, int productsCount, vector<Ingredient> ingredients,double price,string type):Meal(id, shortname, name, availability, productsCount, ingredients, price){

    }





};