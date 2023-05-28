#include "Employee.h"
#include "../orders/Order.h"

class Supplier : public Employee {

public:
    Supplier(std::string id, std::string name, std::string email):Employee(id, name, "Supplier", email){};
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
    void deliverOrder(/*parametry potrzebne dla klasy order*/) {
        // pobranie zamówienia z DB
        // zrobione w klasie GetData
    }
private:
    void orderDelivered() {
        // usunięcie zamówienia z DB 
        // zrobione w klasie PostData
    }
};
