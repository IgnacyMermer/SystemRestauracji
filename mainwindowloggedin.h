#ifndef MAINWINDOWLOGGEDIN_H
#define MAINWINDOWLOGGEDIN_H

#include <QDialog>

namespace Ui {
class mainwindowloggedin;
}

class mainwindowloggedin : public QDialog
{
    Q_OBJECT

public:
    explicit mainwindowloggedin(QWidget *parent = nullptr);
    ~mainwindowloggedin();

private slots:
    void on_pushButton_YourData_clicked();

    void on_pushButton_YourClients_clicked();

    void on_pushButton_closeRestaurant_clicked();

    void on_pushButton_changeAvailabilityMeals_clicked();

    void on_pushButton_changeAvailabilityIngredients_clicked();

    void on_pushButton_confirmOrder_clicked();

private:
    Ui::mainwindowloggedin *ui;
};

#endif // MAINWINDOWLOGGEDIN_H
