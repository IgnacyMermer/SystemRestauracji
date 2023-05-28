#ifndef TASKDETAILS_H
#define TASKDETAILS_H

#include <QDialog>
#include <iostream>
#include "../employees/Task.h"


namespace Ui {
class TaskDetails;
}

class TaskDetails : public QDialog
{
    Q_OBJECT

public:
    explicit TaskDetails(Task task, QWidget *parent = nullptr);
    ~TaskDetails();

private slots:
    void on_pushButton_comeback_clicked();
    void on_pushButton_taskDone_clicked();

private:
    Ui::TaskDetails *ui;
    Task task;
};

#endif // TASKDETAILS_H
