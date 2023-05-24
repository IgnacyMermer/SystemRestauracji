#ifndef CLIENTDETAILS_H
#define CLIENTDETAILS_H

#include <QDialog>

namespace Ui {
class ClientDetails;
}

class ClientDetails : public QDialog
{
    Q_OBJECT

public:
    explicit ClientDetails(QWidget *parent = nullptr);
    ~ClientDetails();

private:
    Ui::ClientDetails *ui;
};

#endif // CLIENTDETAILS_H
