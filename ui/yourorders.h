#ifndef YOURORDERS_H
#define YOURORDERS_H

#include <QDialog>
#include <QListWidgetItem>
#include <vector>
#include "../orders/Order.h"
#include "json_spirit.h"

namespace Ui {
class YourOrders;
}

class YourOrders : public QDialog
{
    Q_OBJECT

public:
    explicit YourOrders(QWidget *parent = nullptr);
    ~YourOrders();

private slots:
    void on_pushButton_clicked();
    void on_listWidget_yourOrders_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::YourOrders *ui;
    std::vector<Order> orders;
};

#endif // YOURORDERS_H
