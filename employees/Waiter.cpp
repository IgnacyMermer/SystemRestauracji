#include "Employee.h"

class Waiter : public Employee {
public:
    Waiter(int id, std::string name, std::string email):Employee(id, name, "Waiter", email){};
    int id() {return Employee::id();};
    std::string name() {return Employee::name();};
    std::string email() {return Employee::email();};
private:
};
