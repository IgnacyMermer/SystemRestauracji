#include "Employee.h"
#include "Order.h"

class Waiter : public Employee {

public:
    Waiter(int id, std::string name, std::string email):Employee(id, name, "Waiter", email){};
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
    void takeOrder(/*parametry potrzebne dla klasy order*/) {
        //Order order = Order();
        // zapis order do DB z try catch
    }
private:
    void giveOrderToChef() {
        // przekazanie zamówienia szefowi, który to znajdzie wolnego kucharza i jemu zleci przygotowanie posiłku
        // chef.searchForFreeCook() 
    }
};
