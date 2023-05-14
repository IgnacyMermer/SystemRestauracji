#include "PostData.h"
#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <json_spirit.h>
#include <map>
#include <iostream>

using namespace std;

void PostData::send_request(){

    struct curl_slist *headers = NULL;
    headers = curl_slist_append(headers, "Expect:");
    headers = curl_slist_append(headers, "Content-Type: application/json");
    string bodyString = createBody(body);
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, bodyString.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeToString);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

    cout<<response;
    res = curl_easy_perform(curl);

    curl_easy_getinfo (curl, CURLINFO_RESPONSE_CODE, &httpCode);
    curl_easy_cleanup(curl);
}

string PostData::createBody(map<string, string> mapBody) {
    string body = "";
    body+="{";
    for(const auto& [key, value] : mapBody){
        body += "\"" + key + "\"" + ":" + "\"" + value + "\"" + ", ";
    }
    body = body.substr(0, body.length()-2);
    body+="}";
    cout<<body;
    return body;
}
