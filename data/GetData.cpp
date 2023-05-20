#include "GetData.h"
#include <iostream>
#include "../meals/Meal.h"
#include "../meals/Mainmeal.h"
#include "../meals/Ingredient.h"
#include "json_spirit.h"

using namespace std;

void GetData::send_request(){
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeToString);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

    res = curl_easy_perform(curl);

    curl_easy_getinfo (curl, CURLINFO_RESPONSE_CODE, &httpCode);
    curl_easy_cleanup(curl);
}

vector<Meal> GetData::getMeals(json_spirit::Array& arr) {
    vector<Meal> meals;
    for(int i=0; i<arr.size(); i++){
        json_spirit::Object& obj = arr[i].get_obj();

        std::vector<json_spirit::Value> dest = obj[7].value_.get_array();
        vector<json_spirit::Value>::iterator it;
        vector<Ingredient> ingredientsList;

        for(it = dest.begin(); it!=dest.end(); it++){
            json_spirit::Object& objTemp = it->get_obj();
            Ingredient ingredient = Ingredient(objTemp[0].value_.get_str(), objTemp[2].value_.get_str(), objTemp[1].value_.get_str(),
                                               objTemp[3].value_.get_bool(),objTemp[4].value_.get_int());
            ingredientsList.push_back(ingredient);
        }

        Mainmeal meal = Mainmeal(obj[0].value_.get_str(), obj[1].value_.get_str(), obj[2].value_.get_str(), obj[4].value_.get_bool(),
                                 obj[5].value_.get_int(), ingredientsList, obj[6].value_.get_real(), "");
        meals.push_back(meal);
    }
    return meals;
}

vector<Meal> GetData::getMealsWithoutMeals(json_spirit::Array& arr) {
    vector<Meal> meals;
    for(int i=0; i<arr.size(); i++){
        json_spirit::Object& obj = arr[i].get_obj();

        std::vector<json_spirit::Value> dest = obj[7].value_.get_array();
        vector<json_spirit::Value>::iterator it;
        vector<string> ingredientsList;

        for(it = dest.begin(); it!=dest.end(); it++){
            ingredientsList.push_back(it->get_str());
        }

        Mainmeal meal = Mainmeal(obj[0].value_.get_str(), obj[1].value_.get_str(), obj[2].value_.get_str(), obj[4].value_.get_bool(),
                                 obj[5].value_.get_int(), ingredientsList, obj[6].value_.get_real(), "");
        meals.push_back(meal);
    }
    return meals;
}
