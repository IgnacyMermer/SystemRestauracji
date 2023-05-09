#include <exception>
#include <string>

class myException : public std::exception {
    std::string description;
public:
    virtual const char* what() const throw(){return "Something went wrong";}
    void setDescription(std::string desc) {
        this->description = desc;
    }
    virtual const std::string showDescription() const throw() {return description;}
};