#ifndef YOURORDERS_H
#define YOURORDERS_H

#include <QDialog>

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

private:
    Ui::YourOrders *ui;
};

#endif // YOURORDERS_H
