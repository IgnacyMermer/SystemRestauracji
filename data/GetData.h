#ifndef PROJEKTPROI2_GETDATA_H
#define PROJEKTPROI2_GETDATA_H

#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <json_spirit.h>
#include <iostream>
#include "Data.h"

using namespace std;

class GetData: public Data{
public:
    GetData(string url):Data(url){

    }

    void send_request(){
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeToString);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        cout<<response;
        res = curl_easy_perform(curl);

        curl_easy_getinfo (curl, CURLINFO_RESPONSE_CODE, &httpCode);
        curl_easy_cleanup(curl);
    }

};


#endif //PROJEKTPROI2_GETDATA_H
