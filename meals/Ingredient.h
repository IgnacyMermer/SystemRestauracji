#ifndef PROJEKTPROI2_INGREDIENT_H
#define PROJEKTPROI2_INGREDIENT_H
#include <iostream>

using namespace std;

class Ingredient {
protected:
    int foodid;
    string foodshortname;
    string foodname;
    bool foodavailability;
    int foodproductsCount;
public:
    Ingredient(int id, std::string name, std::string shortname, bool availability, int productsCount);
    void setProductsCount(int productsCount);
    bool checkAvailability();
    virtual bool getAvailability();


};


#endif //PROJEKTPROI2_INGREDIENT_H
