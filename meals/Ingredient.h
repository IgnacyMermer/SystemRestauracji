#ifndef PROJEKTPROI2_INGREDIENT_H
#define PROJEKTPROI2_INGREDIENT_H
#include <iostream>

using namespace std;

class Ingredient {
public:
    int id;
    string shortname;
    string name;
    bool availability;
    int productsCount;

    void setProductsCount(int productsCount);
    bool checkAvailability();

private:

};


#endif //PROJEKTPROI2_INGREDIENT_H
