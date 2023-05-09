#ifndef ADDNEWMEAL_H
#define ADDNEWMEAL_H

#include <QDialog>

namespace Ui {
class AddNewMeal;
}

class AddNewMeal : public QDialog
{
    Q_OBJECT

public:
    explicit AddNewMeal(QWidget *parent = nullptr);
    ~AddNewMeal();

private slots:
    void on_pushButton_addIngredient_clicked();

    void on_pushButton_removeIngredient_clicked();

    void on_pushButton_confirm_clicked();

private:
    Ui::AddNewMeal *ui;
};

#endif // ADDNEWMEAL_H
