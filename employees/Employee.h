#ifndef PROJEKTPROI2_EMPLOYEE_H
#define PROJEKTPROI2_EMPLOYEE_H

#include <iostream>
#include <vector>
#include "Task.h"

class Employee {
    int employeeId;
    std::string employeeName;
    std::string employeeRole;
    std::string employeeEmail;
public:
    Employee(int id, std::string name, std::string role, std::string email);
    int id();
protected:
    std::string name();
    std::string role();
    std::string email();
    std::vector<Task> tasks;
    std::vector<Task> givenTasks;
};


#endif //PROJEKTPROI2_EMPLOYEE_H
