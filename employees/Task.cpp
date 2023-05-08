#include "Task.h"

Task::Task(int id, std::string name, std::string description, int priority) {
    taskId = id; taskName = taskName; 
    taskDescription = description;
    done = false; 
    taskPriority = priority; 
}

int Task::id() {
    return taskId;
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

int Task::priority() {
    return taskPriority;
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
