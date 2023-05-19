#ifndef MEALDETAILS_H
#define MEALDETAILS_H

#include <QDialog>

namespace Ui {
class MealDetails;
}

class MealDetails : public QDialog
{
    Q_OBJECT

public:
    explicit MealDetails(QWidget *parent = nullptr);
    ~MealDetails();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MealDetails *ui;
};

#endif // MEALDETAILS_H
