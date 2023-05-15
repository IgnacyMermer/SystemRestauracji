#include "GetData.h"
#include <iostream>

using namespace std;

void GetData::send_request(){
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeToString);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

    cout<<response;
    res = curl_easy_perform(curl);

    curl_easy_getinfo (curl, CURLINFO_RESPONSE_CODE, &httpCode);
    curl_easy_cleanup(curl);
}
