#ifndef ADDTASKS_H
#define ADDTASKS_H

#include <QDialog>

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

private:
    Ui::AddTasks *ui;
};

#endif // ADDTASKS_H
