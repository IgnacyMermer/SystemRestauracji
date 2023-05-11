#ifndef MEALSEDITING_H
#define MEALSEDITING_H

#include <QDialog>

namespace Ui {
class MealsEditing;
}

class MealsEditing : public QDialog
{
    Q_OBJECT

public:
    explicit MealsEditing(QWidget *parent = nullptr);
    ~MealsEditing();

private slots:
    void on_pushButton_addNewMeal_clicked();

    void on_pushButton_addNewDrinkSauce_clicked();

    void on_pushButton_editMeal_clicked();

    void on_pushButton_changeAvailabilityMeal_clicked();

    void on_pushButton_removeMeal_clicked();

private:
    Ui::MealsEditing *ui;
};

#endif // MEALSEDITING_H
