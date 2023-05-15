#ifndef PROJEKTPROI2_INGREDIENT_H
#define PROJEKTPROI2_INGREDIENT_H
#include <iostream>

using namespace std;

class Ingredient {
protected:
    string foodid;
    string foodshortname;
    string foodname;
    bool foodavailability;
    int foodproductsCount;
public:
    Ingredient(string id, std::string name, std::string shortname, bool availability, int productsCount);
    string getName(){
        return foodname;
    }
    void setProductsCount(int productsCount);
    bool checkAvailability();
    bool getAvailability();


};


#endif //PROJEKTPROI2_INGREDIENT_H
