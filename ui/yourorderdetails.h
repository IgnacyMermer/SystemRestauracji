#ifndef YOURORDERDETAILS_H
#define YOURORDERDETAILS_H

#include <QDialog>

namespace Ui {
class YourOrderDetails;
}

class YourOrderDetails : public QDialog
{
    Q_OBJECT

public:
    explicit YourOrderDetails(QWidget *parent = nullptr);
    ~YourOrderDetails();

private slots:
    void on_pushButton_goBack_clicked();

private:
    Ui::YourOrderDetails *ui;
};

#endif // YOURORDERDETAILS_H
