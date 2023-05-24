#ifndef ORDERSEDITING_H
#define ORDERSEDITING_H

#include <QDialog>

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
};

#endif // ORDERSEDITING_H
