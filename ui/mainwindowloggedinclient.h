#ifndef MAINWINDOWLOGGEDINCLIENT_H
#define MAINWINDOWLOGGEDINCLIENT_H

#include <QDialog>
#include <vector>
#include "../meals/Meal.h"
#include <QListWidgetItem>

namespace Ui {
class MainWindowLoggedInClient;
}

class MainWindowLoggedInClient : public QDialog
{
    Q_OBJECT

public:
    explicit MainWindowLoggedInClient(QWidget *parent = nullptr);
    ~MainWindowLoggedInClient();
    std::vector<Meal> meals;
    std::vector<Meal*> yourOrder;
    double totalPrice;

private slots:
    void on_pushButton_yourData_clicked();

    void on_pushButton_yourOrders_clicked();

    void on_pushButton_logOut_clicked();

    void on_pushButton_addToOrder_clicked();

    void on_pushButton_removeFromOrder_clicked();

    void on_pushButton_removeOrder_clicked();

    void on_pushButton_confirmOrder_clicked();

    void on_listWidget_meals_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::MainWindowLoggedInClient *ui;
};

#endif // MAINWINDOWLOGGEDINCLIENT_H
