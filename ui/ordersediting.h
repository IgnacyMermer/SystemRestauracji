#ifndef ORDERSEDITING_H
#define ORDERSEDITING_H

#include <QDialog>
#include "../orders/Order.h"

namespace Ui {
class ordersEditing;
}

class ordersEditing : public QDialog
{
    Q_OBJECT

public:
    explicit ordersEditing(QWidget *parent = nullptr);
    ~ordersEditing();

private slots:
    void on_pushButton_comeback_clicked();

    void on_pushButton_orderDone_clicked();

    void on_pushButton_showDetails_clicked();

private:
    Ui::ordersEditing *ui;
    std::vector<Order> orders;
};

#endif // ORDERSEDITING_H
