#include "Data.h"

void Data::changeUrl(std::string url) {
    {
        this->url = url;
    }
}

long Data::getHttpCode() {
    return httpCode;
}

void Data::setHttpCode(long httpCode) {
    this->httpCode = httpCode;
}

size_t Data::writeToString(void *ptr, size_t size, size_t count, void *stream){
    ((string*)stream)->append((char*)ptr, 0, size*count);
    return size*count;
}

string Data::getResponse(){
    return response;
}
