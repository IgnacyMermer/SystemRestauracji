#ifndef PROJEKTPROI2_DATA_H
#define PROJEKTPROI2_DATA_H
#include <iostream>
#include <string>
#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>

using namespace std;

class Data {
public:
    Data(string url):url(url){
        cURLpp::Cleanup myCleanup;
        curl = curl_easy_init();
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    }
    static size_t writeToString(void *ptr, size_t size, size_t count, void *stream){
        ((string*)stream)->append((char*)ptr, 0, size*count);
        return size*count;
    }
    string getResponse(){
        return response;
    }
    virtual void send_request() = 0;
protected:
    string response;
    CURLcode res;
    CURL *curl;
    string url;
    void changeUrl(string url);
};


#endif //PROJEKTPROI2_DATA_H
