#ifndef YOURDATA_H
#define YOURDATA_H

#include <QDialog>

namespace Ui {
class YourData;
}

class YourData : public QDialog
{
    Q_OBJECT

public:
    explicit YourData(QWidget *parent = nullptr);
    ~YourData();

private slots:
    void on_pushButton_changePassword_clicked();

private:
    Ui::YourData *ui;
};

#endif // YOURDATA_H
