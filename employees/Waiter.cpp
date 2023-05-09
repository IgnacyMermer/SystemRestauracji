#include "Task.h"
#include "Employee.h"

class Waiter : public Employee {
public:
    Waiter(int id, std::string name, std::string email):Employee(id, name, "Waiter", email){};
    int id() {return Employee::id();};
    std::string name() {return Employee::name();};
    std::string email() {return Employee::email();};
    Task createTask(int id, std::string name, std::string description, int priority) {
        Task task = Task (id, name, description, priority);
        // TODO: zapis do DB tasku;
        return task;
    };
    Task getTask() { // wyswietlanie obecnego tasku 
        // TODO: pobieranie z DB danych 
    }; 
private:
};
