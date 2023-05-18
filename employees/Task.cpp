#include "Task.h"

Task::Task(std::string name, std::string description, int employeeID) {
    taskName = name;
    taskDescription = description;
    taskEmployeeId = employeeID;
    done = false; 
}


std::string Task::name() {
    return taskName;
}

std::string Task::description() {
    return taskDescription;
}

bool Task::isDone() {
    return done;
}

void Task::setTrueDone() {
    done = true;
}

void Task::setFalseDone() {
    done = false;
}

void Task::updateDescription(std::string newDescription) {
    taskDescription = newDescription;
}
