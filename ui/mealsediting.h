#ifndef MEALSEDITING_H
#define MEALSEDITING_H

#include <QDialog>
#include "../meals/Meal.h"

namespace Ui {
class MealsEditing;
}

class MealsEditing : public QDialog
{
    Q_OBJECT

public:
    explicit MealsEditing(QWidget *parent = nullptr);
    ~MealsEditing();
    std::vector<Meal> meals;

private slots:
    void on_pushButton_addNewMeal_clicked();

    void on_pushButton_addNewDrinkSauce_clicked();

    void on_pushButton_editMeal_clicked();

    void on_pushButton_changeAvailabilityMeal_clicked();

    void on_pushButton_removeMeal_clicked();

    void on_pushButton_refresh_clicked();

private:
    Ui::MealsEditing *ui;
};

#endif // MEALSEDITING_H
