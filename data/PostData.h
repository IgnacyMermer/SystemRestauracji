#ifndef PROJEKTPROI2_POSTDATA_H
#define PROJEKTPROI2_POSTDATA_H

#include <iostream>
#include "Data.h"
#include <map>

using namespace std;

class PostData:public Data {
    //map<string, string> body;
    string body;
public:

    PostData(string url, string bodyRequest):Data(url){
            body = bodyRequest;
    }

    void send_request();

protected:
    string createBody(std::map<string, string> mapBody);

};


#endif //PROJEKTPROI2_POSTDATA_H
