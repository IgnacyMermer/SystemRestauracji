#include "Employee.h"

class Chef : public Employee {
public:
    Chef(int id, std::string name, std::string email):Employee(id, name, "Chef", email){};
    int id() {return Employee::id();};
    std::string name() {return Employee::name();};
    std::string email() {return Employee::email();};
private:
};
