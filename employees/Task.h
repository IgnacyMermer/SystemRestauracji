#ifndef PROJEKTPROI2_TASK_H
#define PROJEKTPROI2_TASK_H
#include <iostream>

class Task {
    std::string taskName;
    std::string taskDescription;
    std::string taskEmployeeId;
    std::string bossId, id;
    bool done;
public:
    Task();
    Task(std::string id, std::string name, std::string description, std::string employeeID, std::string bossId, bool done);
    std::string name();
    std::string description();
    std::string getEmployeeId();
    std::string getBossId();
    std::string getId();
    bool isDone();
    int priority();
protected:
    void setTrueDone();
    void setFalseDone();
    void updateDescription(std::string newDescription);
};


#endif //PROJEKTPROI2_TASK_H
