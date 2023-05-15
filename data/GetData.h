#ifndef PROJEKTPROI2_GETDATA_H
#define PROJEKTPROI2_GETDATA_H

#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <json_spirit.h>
#include <iostream>
#include "Data.h"
#include "../meals/Meal.h"
#include "json_spirit.h"

using namespace std;

class GetData: public Data{
public:
    GetData(string url):Data(url){

    }

    void send_request();
    vector<Meal> getMeals(json_spirit::Array& arr);

};


#endif //PROJEKTPROI2_GETDATA_H
