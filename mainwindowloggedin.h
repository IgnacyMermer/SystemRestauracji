#ifndef MAINWINDOWLOGGEDIN_H
#define MAINWINDOWLOGGEDIN_H

#include <QDialog>

namespace Ui {
class mainwindowloggedin;
}

class mainwindowloggedin : public QDialog
{
    Q_OBJECT

public:
    explicit mainwindowloggedin(QWidget *parent = nullptr);
    ~mainwindowloggedin();

private:
    Ui::mainwindowloggedin *ui;
};

#endif // MAINWINDOWLOGGEDIN_H
