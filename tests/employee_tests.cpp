#include <gtest/gtest.h>
#include "../employees/Task.h"
#include "../employees/Employee.h"
#include "../data/PostData.h"
#include "../employees/Cook.cpp"
#include "../employees/Chef.cpp"
#include "../employees/Janitor.cpp"
#include "../employees/Supplier.cpp"

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

TEST(CookTest1, Constructor) {
    Cook cook("1", "name", "email");
    EXPECT_EQ(cook.id(), "1");
    EXPECT_EQ(cook.name(), "name");
    EXPECT_EQ(cook.email(), "email");
}

TEST(CookTest2, GiveTask) {
    class CookTest : public Cook {
        public:
            CookTest(const std::string& id, const std::string& name, const std::string& email)
                : Cook(id, name, email) {}

    bool hasTaskWrapper() {
        return hasTask();
    }
};
    CookTest test("1", "name", "email");
    EXPECT_FALSE(test.giveTask("name", "description"));
    EXPECT_FALSE(test.hasTaskWrapper());
}

TEST(ChefTest1, Constructor) {
    Chef chef("1", "name", "email");
    EXPECT_EQ(chef.id(), "1");
    EXPECT_EQ(chef.name(), "name");
    EXPECT_EQ(chef.email(), "email");
}

TEST(exceptionTest, What) {
    myException ex;
    EXPECT_STREQ("Something went wrong", ex.what());
}

TEST(exceptionTest, ShowDescription) {
    myException ex;
    ex.setDescription("Custom description");
    EXPECT_EQ("Custom description", ex.showDescription());
}

TEST(SJanitorTest1, Constructor) {
    Janitor janitor("1", "name", "email");
    EXPECT_EQ(janitor.id(), "1");
    EXPECT_EQ(janitor.name(), "name");
    EXPECT_EQ(janitor.email(), "email");
}

TEST(JanitorTest2, GiveTask) {
    class JanitorTest : public Janitor {
        public:
            JanitorTest(const std::string& id, const std::string& name, const std::string& email)
                : Janitor(id, name, email) {}

    bool hasTaskWrapper() {
        return hasTask();
    }
};
    JanitorTest test("1", "name", "email");
    EXPECT_FALSE(test.giveTask("name", "description"));
    EXPECT_FALSE(test.hasTaskWrapper());
}

TEST(SupplierTest1, Constructor) {
    Supplier supplier("1", "name", "email");
    EXPECT_EQ(supplier.id(), "1");
    EXPECT_EQ(supplier.name(), "name");
    EXPECT_EQ(supplier.email(), "email");
}

TEST(SupplierTest2, GiveTask) {
    class SupplierTest : public Supplier {
        public:
            SupplierTest(const std::string& id, const std::string& name, const std::string& email)
                : Supplier(id, name, email) {}

    bool hasTaskWrapper() {
        return hasTask();
    }
};
    SupplierTest test("1", "name", "email");
    EXPECT_FALSE(test.giveTask("name", "description"));
    EXPECT_FALSE(test.hasTaskWrapper());
}
