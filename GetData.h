#ifndef PROJEKTPROI2_GETDATA_H
#define PROJEKTPROI2_GETDATA_H

#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <json_spirit.h>
#include <iostream>

using namespace std;

class GetData {
public:
    static size_t write_to_string(void *ptr, size_t size, size_t count, void *stream){
        ((string*)stream)->append((char*)ptr, 0, size*count);
        return size*count;
    }
    GetData(string url):url(url){
        cURLpp::Cleanup myCleanup;
        curl = curl_easy_init();
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, GetData::write_to_string);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
        cout<<response;
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }
    string url;
    string getResponse();

private:
    string response;
    CURLcode res;
    CURL *curl;
};


#endif //PROJEKTPROI2_GETDATA_H
