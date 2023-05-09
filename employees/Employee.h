#ifndef PROJEKTPROI2_EMPLOYEE_H
#define PROJEKTPROI2_EMPLOYEE_H

#include <vector>
#include <string>
#include "Task.h"
#include "exception.cpp"

class Employee {
    int employeeId;
    std::string employeeName;
    std::string employeeRole;
    std::string employeeEmail;
    bool employeeTask;
public:
    Employee(int id, std::string name, std::string role, std::string email);
    int id();
protected:
    void createTask(int id, std::string name, std::string description, int priority);
    Task getTask();
    std::string name();
    std::string role();
    std::string email();
    bool hasTask();
    std::vector<int> tasks; // podajemy task id
    std::vector<int> givenTasks; // podajemy task id
};




#endif //PROJEKTPROI2_EMPLOYEE_H
