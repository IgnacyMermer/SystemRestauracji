#include "Employee.h"

Employee::Employee(int id, std::string name, std::string role, std::string email) {
    employeeId = id;
    employeeName = name;
    employeeRole = role;
    employeeEmail = email;
    employeeTask = false; 
}

int Employee::id() {
    return employeeId;
}

Task Employee::createTask(int id, std::string name, std::string description, int priority) {
    Task task = Task(id, name, description, priority);
    // TODO: zapis do DB tasku;
    if (0 == 1) {
        myException exc;
        exc.setDescription("Info");
        throw exc;
    }
    return task;
}

Task Employee::getTask() { // wyswietlanie obecnego tasku 
        // TODO: pobieranie z DB danych 
}

std::string Employee::name() {
    return employeeName;
}

std::string Employee::role() {
    return employeeRole;
}

std::string Employee::email() {
    return employeeEmail;
}

bool Employee::hasTask() {
    return employeeTask;
}