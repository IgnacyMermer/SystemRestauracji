#include "Meal.h"
#include "Ingredient.h"
#include "drink.h"

int main(){
    Ingredient sugar(2,"sugar","sugar",true,4);
    Drink coca_cola(1,"coke","coca-cola",true,3,{sugar},7.1,"drink");
    coca_cola.setProductsCount(8);
}