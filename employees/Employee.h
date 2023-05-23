#ifndef PROJEKTPROI2_EMPLOYEE_H
#define PROJEKTPROI2_EMPLOYEE_H

#include <vector>
#include <string>
#include "Task.h"
#include "exception.cpp"

class Employee {
    std::string employeeId;
    std::string employeeName;
    std::string employeeRole;
    std::string employeeEmail;
    bool employeeTask;
public:
    Employee(){}
    Employee(std::string id, std::string name, std::string role, std::string email);
    std::string id();
    std::string name();
    std::string role();
    std::string email();
protected:
    void createTask(std::string name, std::string description);
    Task getTask();

    bool hasTask();
    std::vector<int> tasks; // podajemy task id
    std::vector<int> givenTasks; // podajemy task id
};




#endif //PROJEKTPROI2_EMPLOYEE_H
