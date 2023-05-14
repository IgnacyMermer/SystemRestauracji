#ifndef PROJEKTPROI2_POSTDATA_H
#define PROJEKTPROI2_POSTDATA_H
#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <json_spirit.h>
#include <iostream>
#include "Data.h"

using namespace std;

class PostData:public Data {
    string body;
public:
    long http_code = 0;

    PostData(string url, string bodyRequest):Data(url){
            body = bodyRequest;
    }

    void send_request(){
        cout<<body;
        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, "Expect:");
        headers = curl_slist_append(headers, "Content-Type: application/json");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, body.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeToString);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        cout<<response;
        res = curl_easy_perform(curl);

        curl_easy_getinfo (curl, CURLINFO_RESPONSE_CODE, &http_code);
        curl_easy_cleanup(curl);
    }
};


#endif //PROJEKTPROI2_POSTDATA_H
