#include "Employee.h"
#include "../orders/Order.h"

class Supplier : public Employee {

public:
    Supplier(int id, std::string name, std::string email):Employee(id, name, "Supplier", email){};
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
    void deliverOrder(/*parametry potrzebne dla klasy order*/) {
        // pobranie zamówienia z DB
    }
private:
    void orderDelivered() {
        // usunięcie zamówienia z DB 
    }
};