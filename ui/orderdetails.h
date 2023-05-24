#ifndef ORDERDETAILS_H
#define ORDERDETAILS_H

#include <QDialog>

namespace Ui {
class OrderDetails;
}

class OrderDetails : public QDialog
{
    Q_OBJECT

public:
    explicit OrderDetails(QWidget *parent = nullptr);
    ~OrderDetails();

private slots:
    void on_pushButton_comeback_clicked();

private:
    Ui::OrderDetails *ui;
};

#endif // ORDERDETAILS_H
