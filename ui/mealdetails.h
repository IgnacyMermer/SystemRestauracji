#ifndef MEALDETAILS_H
#define MEALDETAILS_H

#include <QDialog>
#include "../meals/Meal.h"

namespace Ui {
class MealDetails;
}

class MealDetails : public QDialog
{
    Q_OBJECT

public:
    explicit MealDetails(Meal meal, QWidget *parent = nullptr);
    ~MealDetails();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MealDetails *ui;
    Meal meal;
};

#endif // MEALDETAILS_H
