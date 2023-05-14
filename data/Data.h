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
    long httpCode;
    Data(string url):url(url){
        cURLpp::Cleanup myCleanup;
        curl = curl_easy_init();
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        httpCode = 0;
    }

    static size_t writeToString(void *ptr, size_t size, size_t count, void *stream);

    virtual void send_request() = 0;

    string getResponse();
    long getHttpCode();
    void setHttpCode(long httpCode);
    void changeUrl(string url);

protected:
    string response;
    CURLcode res;
    CURL *curl;
    string url;

};


#endif //PROJEKTPROI2_DATA_H
