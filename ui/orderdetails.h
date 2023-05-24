#ifndef ORDERDETAILS_H
#define ORDERDETAILS_H

#include <QDialog>
#include "../orders/Order.h"

namespace Ui {
class OrderDetails;
}

class OrderDetails : public QDialog
{
    Q_OBJECT

public:
    explicit OrderDetails(Order order, QWidget *parent = nullptr);
    ~OrderDetails();

private slots:
    void on_pushButton_comeback_clicked();

private:
    Ui::OrderDetails *ui;
    Order order;
};

#endif // ORDERDETAILS_H
