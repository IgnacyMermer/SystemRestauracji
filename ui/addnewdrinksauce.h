#ifndef ADDNEWDRINKSAUCE_H
#define ADDNEWDRINKSAUCE_H

#include <QDialog>

namespace Ui {
class AddNewDrinkSauce;
}

class AddNewDrinkSauce : public QDialog
{
    Q_OBJECT

public:
    explicit AddNewDrinkSauce(QWidget *parent = nullptr);
    ~AddNewDrinkSauce();

private slots:
    void on_pushButton_confirm_clicked();

private:
    Ui::AddNewDrinkSauce *ui;
};

#endif // ADDNEWDRINKSAUCE_H
