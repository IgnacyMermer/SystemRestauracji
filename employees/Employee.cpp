#include "Employee.h"
#include "../data/PostData.h"


Employee::Employee(std::string id, std::string name, std::string role, std::string email) {
    employeeId = id;
    employeeName = name;
    employeeRole = role;
    employeeEmail = email;
    employeeTask = false; 
}

std::string Employee::id() {
    return employeeId;
}

void Employee::createTask(std::string name, std::string description) {
    //Task task = Task(name, description, employeeID);
    // TODO: zapis do DB tasku; zrobione w klasie PostData
    std::string employeeID = this->employeeId; // nie wiem czy tak pobiera się id unikalnego obiektu
    std::string body = "{\"name\" : \""+name+"\", \"description\": \""+description+"\", \"employeeId\" : \""+employeeID+"\"}";
    PostData postData = PostData("http://localhost:3000/", body); // potrzebne URL
    postData.send_request();
    if (postData.getHttpCode() != 200) {
        myException exc;
        exc.setDescription("Info");
        throw exc;
    }
}

Task Employee::getTask() { // wyswietlanie obecnego tasku  
        // zrobione w UI
}

std::string Employee::name() {
    return employeeName;
}

std::string Employee::role() {
    return employeeRole;
}

std::string Employee::email() {
    return employeeEmail;
}

bool Employee::hasTask() {
    return employeeTask;
}