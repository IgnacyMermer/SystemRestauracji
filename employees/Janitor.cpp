#include "Employee.h"

class Janitor : public Employee {
public:
    Janitor(std::string id, std::string name, std::string email):Employee(id, name, "Janitor", email){};
    std::string id() {return Employee::id();};
    std::string name() {return Employee::name();};
    std::string email() {return Employee::email();};
    bool giveTask(std::string name, std::string description) {
        if (hasTask() == true) {return false;}
        else {
            try {
                createTask(name, description);
                return true;
            } catch(const myException& e) {
                std::cerr << e.what() << std::endl;
                std::cerr << e.showDescription() << std::endl;
                return false;
            }
        };
    };
private:
};
