#include "Task.h"

void Task::setTrueDone(){
    done = true;
}

void Task::setFalseDone(){
    done = false;
}

void Task::updateDescription(std::string newDescription) {
    taskDescription = newDescription;
}
