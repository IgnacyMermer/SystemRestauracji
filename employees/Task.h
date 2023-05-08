#ifndef PROJEKTPROI2_TASK_H
#define PROJEKTPROI2_TASK_H
#include <iostream>

class Task {
    int taskId;
    std::string taskName;
    std::string taskDescription;
    bool done;
    int taskPriority;
public:
    Task(int id, std::string name, std::string description, int priority);
    int id();
    std::string name();
    std::string description();
    bool isDone();
    int priority();
protected:
    void setTrueDone();
    void setFalseDone();
    void updateDescription(std::string newDescription);
};


#endif //PROJEKTPROI2_TASK_H
