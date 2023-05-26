#ifndef ADDNEWMEAL_H
#define ADDNEWMEAL_H

#include <QDialog>
#include "../meals/Ingredient.h"


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

    void on_pushButton_addIngredientToDB_clicked();

    void on_pushButton_refreshIngredients_clicked();

    void on_pushButton_removeIngredient_clicked();

    void on_pushButton_confirm_clicked();

private:
    vector<Ingredient> ingredients;
    vector<Ingredient> chosenIngredients;
    Ui::AddNewMeal *ui;
};

#endif // ADDNEWMEAL_H
