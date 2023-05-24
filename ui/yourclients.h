#ifndef YOURCLIENTS_H
#define YOURCLIENTS_H

#include <QDialog>
#include "../client/Client.h"

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
    std::vector<Client> clients;
};

#endif // YOURCLIENTS_H
