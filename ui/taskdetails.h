#ifndef TASKDETAILS_H
#define TASKDETAILS_H

#include <QDialog>
#include <iostream>


namespace Ui {
class TaskDetails;
}

class TaskDetails : public QDialog
{
    Q_OBJECT

public:
    explicit TaskDetails(std::string id, QWidget *parent = nullptr);
    ~TaskDetails();

private slots:
    void on_pushButton_comeback_clicked();

private:
    Ui::TaskDetails *ui;
    std::string id;
};

#endif // TASKDETAILS_H
