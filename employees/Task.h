#ifndef PROJEKTPROI2_TASK_H
#define PROJEKTPROI2_TASK_H
#include <iostream>

class Task {
    std::string taskName;
    std::string taskDescription;
    int taskEmployeeId;
    bool done;
public:
    Task(std::string name, std::string description, int employeeID);
    std::string name();
    std::string description();
    int employeeId();
    bool isDone();
    int priority();
protected:
    void setTrueDone();
    void setFalseDone();
    void updateDescription(std::string newDescription);
};


#endif //PROJEKTPROI2_TASK_H
