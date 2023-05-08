#include "Task.h"
#include "Employee.h"

class Waiter : public Employee {
public:
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
