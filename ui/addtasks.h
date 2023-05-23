#ifndef ADDTASKS_H
#define ADDTASKS_H

#include <QDialog>
#include "../employees/Employee.h"

namespace Ui {
class AddTasks;
}

class AddTasks : public QDialog
{
    Q_OBJECT

public:
    explicit AddTasks(QWidget *parent = nullptr);
    ~AddTasks();

private slots:
    void on_pushButton_comeback_clicked();
    void on_pushButton_confirm_clicked();

private:
    Ui::AddTasks *ui;
    std::vector<Employee> employees;
};

#endif // ADDTASKS_H
