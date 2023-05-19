#ifndef YOURORDERDETAILS_H
#define YOURORDERDETAILS_H

#include <QDialog>
#include <iostream>

namespace Ui {
class YourOrderDetails;
}

class YourOrderDetails : public QDialog
{
    Q_OBJECT

public:
    explicit YourOrderDetails(std::string id, QWidget *parent = nullptr);
    //explicit YourOrderDetails(const std::string &id);
    ~YourOrderDetails();
    void setOrderId(std::string newOrderId);

private slots:
    void on_pushButton_goBack_clicked();

private:
    Ui::YourOrderDetails *ui;
    std::string orderId;
};

#endif // YOURORDERDETAILS_H
