#ifndef PROJEKTPROI2_ORDER_H
#define PROJEKTPROI2_ORDER_H

#include <iostream>
#include "../meals/Meal.h"

using namespace std;

class Order {
public:
    int id;
private:
    vector<Meal> meals;
};


#endif //PROJEKTPROI2_ORDER_H
