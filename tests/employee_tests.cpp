#include <gtest/gtest.h>
#include "../employees/Task.h"
#include "../employees/Employee.h"
#include "../data/PostData.h"

TEST(TaskTest1, Initial) {
    Task task;
    EXPECT_EQ(task.name(), "");
    EXPECT_EQ(task.description(), "");
    EXPECT_EQ(task.getEmployeeId(), "");
    EXPECT_EQ(task.getBossId(), "");
    EXPECT_EQ(task.getId(), "");
    EXPECT_FALSE(task.isDone());
}

TEST(TaskTest2, Initial) {
    Task task("1", "name", "description", "employeeID", "bossId", true);
    EXPECT_EQ(task.name(), "name");
    EXPECT_EQ(task.description(), "description");
    EXPECT_EQ(task.getEmployeeId(), "employeeID");
    EXPECT_EQ(task.getBossId(), "bossId");
    EXPECT_EQ(task.getId(), "1");
    EXPECT_TRUE(task.isDone());
}

TEST(TaskTest3, setTrueDone) {
    class Test : public Task {
    public:
        void setTrueDone() {
            Task::setTrueDone();
        }
    };
    Test test;
    test.setTrueDone();
    EXPECT_TRUE(test.isDone());
}

TEST(TaskTest4, setFalseDone) {
    class Test : public Task {
    public:
        void setFalseDone() {
            Task::setFalseDone();
        }
    };
    Test test;
    test.setFalseDone();
    EXPECT_FALSE(test.isDone());
}

TEST(TaskTest5, updateDescription) {
    class Test : public Task {
    public:
        void updateDescription(std::string newDescription) {
            Task::updateDescription(newDescription);
        }
    };
    Test test;
    EXPECT_EQ(test.description(), "");
    test.updateDescription("newDescription");
    EXPECT_EQ(test.description(), "newDescription");
}

TEST(EmployeeTest1, Initial) {
    Employee employee;
    EXPECT_EQ(employee.id(), "");
    EXPECT_EQ(employee.name(), "");
    EXPECT_EQ(employee.role(), "");
    EXPECT_EQ(employee.email(), "");
}

TEST(EmployeeTest2, Constructor) {
    Employee employee("1", "name", "role", "email");
    EXPECT_EQ(employee.id(), "1");
    EXPECT_EQ(employee.name(), "name");
    EXPECT_EQ(employee.role(), "role");
    EXPECT_EQ(employee.email(), "email");
}

TEST(EmployeeTest3, GetTask) {
    class Test : public Employee {
    public:
        bool hasTask() {
            return Employee::hasTask();
        }
    };
    Test test;
    EXPECT_FALSE(test.hasTask());
}