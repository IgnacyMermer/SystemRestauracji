#ifndef YOURCLIENTS_H
#define YOURCLIENTS_H

#include <QDialog>

namespace Ui {
class YourClients;
}

class YourClients : public QDialog
{
    Q_OBJECT

public:
    explicit YourClients(QWidget *parent = nullptr);
    ~YourClients();

private slots:
    void on_pushButton_clicked();

private:
    Ui::YourClients *ui;
};

#endif // YOURCLIENTS_H
