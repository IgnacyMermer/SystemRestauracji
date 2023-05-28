#ifndef ADDINGREDIENT_H
#define ADDINGREDIENT_H

#include <QDialog>

namespace Ui {
class AddIngredient;
}

class AddIngredient : public QDialog
{
    Q_OBJECT

public:
    explicit AddIngredient(QWidget *parent = nullptr);
    ~AddIngredient();

private slots:
    void on_pushButton_clicked();

private:
    Ui::AddIngredient *ui;
};

#endif // ADDINGREDIENT_H
