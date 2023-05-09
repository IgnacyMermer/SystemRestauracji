#include "Employee.h"

Employee::Employee(int id, std::string name, std::string role, std::string email) {
    employeeId = id;
    employeeName = name;
    employeeRole = role;
    employeeEmail = email;    
};

int Employee::id() {
    return employeeId;
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