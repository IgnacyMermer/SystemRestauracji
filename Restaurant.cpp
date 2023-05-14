#include "Restaurant.h"
#include <string>
#include <vector>
#include "employees/Employee.h"
#include "client/Client.h"
#include "orders/Order.h"
#include "meals/Meal.h"
#include "meals/Ingredient.h"

using namespace std;

void Restaurant::setOpen(bool open) {
    this->open = open;
}

void Restaurant::addEmployee(Employee newEmployee) {
    employees.push_back(newEmployee);
}

void Restaurant::addClient(Client newClient) {
    clients.push_back(newClient);
}

void Restaurant::addOrder(Order newOrder) {
    orders.push_back(newOrder);
}

void Restaurant::addMeal(Meal newMeal) {
    meals.push_back(newMeal);
}

void Restaurant::addIngredient(Ingredient newIngredient) {
    ingredients.push_back(newIngredient);
}

vector<Employee> Restaurant::getEmployees() {
    return employees;
}

vector<Order> Restaurant::getOrders() {
    return orders;
}

vector<Order> Restaurant::getUndoneOrders() {
    vector<Order> undoneOrders;
    for(int i=0; i<orders.size(); i++){
        if(orders[i].isOrderComplete()){
            undoneOrders.push_back(orders[i]);
        }
    }
    return undoneOrders;
}

vector<Meal> Restaurant::getMeals() {
    return meals;
}

vector<Meal> Restaurant::getAvailableMeals() {
    vector<Meal> availableMeals;
    for(int i=0; i<meals.size(); i++){
        if(meals[i].getAvailability()){
            availableMeals.push_back(meals[i]);
        }
    }
    return availableMeals;
}

vector<Ingredient> Restaurant::getIngredients() {
    return ingredients;
}

vector<Ingredient> Restaurant::getAvailableIngredients() {
    vector<Ingredient> availableIngredients;
    for(int i=0; i<ingredients.size(); i++){
        if(ingredients[i].checkAvailability()){
            availableIngredients.push_back(ingredients[i]);
        }
    }
    return availableIngredients;
}
