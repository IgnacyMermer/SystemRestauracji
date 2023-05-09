#include "Employee.h"

class Cook : public Employee {
public:
    Cook(int id, std::string name, std::string email):Employee(id, name, "Cook", email){};
    int id() {return Employee::id();};
    std::string name() {return Employee::name();};
    std::string email() {return Employee::email();};
    bool giveTask(int id, std::string name, std::string description, int priority) {
        // testowy
        try {
                createTask(id, name, description, priority);
            } catch(const myException& e) {
                std::cerr << e.what() << std::endl;
                std::cerr << e.showDescription() << std::endl;
            }
        
        //if (hasTask() == true) {return false;}
        //else {
            //try {
                //createTask(id, name, description, priority);
            //} catch(const myException& e) {
                //std::cerr << e.what();
            //}
        //};
    };
private:
};
