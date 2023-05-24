#ifndef CLIENTDETAILS_H
#define CLIENTDETAILS_H

#include <QDialog>
#include "../client/Client.h"
#include "../orders/Order.h"
#include <QListWidgetItem>

namespace Ui {
class ClientDetails;
}

class ClientDetails : public QDialog
{
    Q_OBJECT

public:
    explicit ClientDetails(Client client, QWidget *parent = nullptr);
    ~ClientDetails();
private slots:
    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);
private:
    Ui::ClientDetails *ui;
    Client client;
    std::vector<Order> orders;
};

#endif // CLIENTDETAILS_H
