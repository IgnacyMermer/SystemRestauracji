//
// Created by Ignacy Mermer on 07/05/2023.
//

#ifndef PROJEKTPROI2_TASK_H
#define PROJEKTPROI2_TASK_H
#include <iostream>

using namespace std;

class Task {
public:
    int id;
    string taskName;
    string taskDescription;
    bool done;
    int priority;
    Task(int id, string taskName, string taskDescription, int priority):id(id), taskName(taskName),
    taskDescription(taskDescription), priority(priority){
        done = false;
    }
private:
    void setTrueDone();
    void setFalseDone();
    void updateDescription(string newDescription);
};


#endif //PROJEKTPROI2_TASK_H
