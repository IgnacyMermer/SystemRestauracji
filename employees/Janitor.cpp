#include "Employee.h"

class Janitor : public Employee {
public:
    Janitor(int id, std::string name, std::string email):Employee(id, name, "Janitor", email){};
    int id() {return Employee::id();};
    std::string name() {return Employee::name();};
    std::string email() {return Employee::email();};
    bool giveTask(int id, std::string name, std::string description, int priority) {
        if (hasTask() == true) {return false;}
        else {
            try {
                createTask(id, name, description, priority);
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
