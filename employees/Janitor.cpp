#include "Employee.h"

class Janitor : public Employee {
public:
    Janitor(int id, std::string name, std::string email):Employee(id, name, "Janitor", email){};
    int id() {return Employee::id();};
    std::string name() {return Employee::name();};
    std::string email() {return Employee::email();};
private:
};
