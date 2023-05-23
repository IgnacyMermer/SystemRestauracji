#include "Employee.h"

class Chef : public Employee {
public:
    Chef(std::string id, std::string name, std::string email):Employee(id, name, "Chef", email){};
    std::string id() {return Employee::id();};
    std::string name() {return Employee::name();};
    std::string email() {return Employee::email();};
    void searchForFreeCook(/*parametry zamówienia*/) {
        // poszukiwanie w DB wolnego kucharza i zlecenie jemu przygotowania posiłku
        // giveOrderToCook()
    }
private:
    void giveOrderToCook() {
        // pobieranie order z DB od kelnera, czyli jak kelner dostanie zamówienie to wywołać u kelnera funkcję która sprawi że chef zleci wykonanie zamówienia
        // i klasa Chef będzie pełniła pośrednika między kelnerem a kucharzem
        // przypisanie Tasku kucharzowi
        // cook1.giveTask() if true => Order.done() = True
    };
};
