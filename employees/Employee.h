#ifndef PROJEKTPROI2_EMPLOYEE_H
#define PROJEKTPROI2_EMPLOYEE_H

#include <iostream>
#include <vector>
#include "Task.h"

using namespace std;

class Employee {
public:
    int id;
private:
    string name;
    string role;
    string email;
    vector<Task> tasks;
    vector<Task> givenTasks;

};


#endif //PROJEKTPROI2_EMPLOYEE_H
