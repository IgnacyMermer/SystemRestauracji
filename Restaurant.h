#ifndef PROJEKTPROI2_RESTAURANT_H
#define PROJEKTPROI2_RESTAURANT_H

#include <vector>
#include <string>
#include "employees/Employee.h"
#include "client/Client.h"
#include "orders/Order.h"
#include "meals/Meal.h"
#include "meals/Ingredient.h"


using namespace std;

class Restaurant {
public:
    string name = "Restauracja ...";
    bool open;
    vector<Meal> meals;
    vector<Ingredient> ingredients;
    Restaurant(){
        open = true;
    }
    void setOpen(bool open);
    void addEmployee(Employee newEmployee);
    void addClient(Client newClient);
    void addOrder(Order newOrder);
    void addMeal(Meal newMeal);
    void addIngredient(Ingredient newIngredient);
    vector<Employee> getEmployees();
    vector<Order> getOrders();
    vector<Order> getUndoneOrders();
    vector<Meal> getMeals();
    vector<Meal> getAvailableMeals();
    vector<Ingredient> getIngredients();
    vector<Ingredient> getAvailableIngredients();

private:
    vector<Employee> employees;
    vector<Client> clients;
    vector<Order> orders;
};


#endif //PROJEKTPROI2_RESTAURANT_H
