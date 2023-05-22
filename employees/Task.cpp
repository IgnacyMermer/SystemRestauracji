#include "Task.h"

Task::Task() {}

Task::Task(std::string id, std::string name, std::string description, std::string employeeID, std::string bossId):bossId(bossId), id(id) {
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

std::string Task::getBossId(){
    return bossId;
}

std::string Task::getEmployeeId(){
    return taskEmployeeId;
}

std::string Task::getId() {
    return id;
}
