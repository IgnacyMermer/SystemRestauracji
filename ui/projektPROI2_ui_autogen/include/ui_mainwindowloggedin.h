/********************************************************************************
** Form generated from reading UI file 'mainwindowloggedin.ui'
**
** Created by: Qt User Interface Compiler version 5.15.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOWLOGGEDIN_H
#define UI_MAINWINDOWLOGGEDIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainwindowloggedin
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_YourData;
    QPushButton *pushButton_YourClients;
    QPushButton *pushButton_closeRestaurant;
    QPushButton *pushButton_changeAvailabilityMeals;
    QPushButton *pushButton_changeAvailabilityIngredients;
    QListWidget *listWidget;
    QPushButton *pushButton_confirmOrder;

    void setupUi(QDialog *mainwindowloggedin)
    {
        if (mainwindowloggedin->objectName().isEmpty())
            mainwindowloggedin->setObjectName(QString::fromUtf8("mainwindowloggedin"));
        mainwindowloggedin->resize(1039, 586);
        widget = new QWidget(mainwindowloggedin);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(50, 30, 941, 511));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton_YourData = new QPushButton(widget);
        pushButton_YourData->setObjectName(QString::fromUtf8("pushButton_YourData"));

        horizontalLayout->addWidget(pushButton_YourData);

        pushButton_YourClients = new QPushButton(widget);
        pushButton_YourClients->setObjectName(QString::fromUtf8("pushButton_YourClients"));

        horizontalLayout->addWidget(pushButton_YourClients);

        pushButton_closeRestaurant = new QPushButton(widget);
        pushButton_closeRestaurant->setObjectName(QString::fromUtf8("pushButton_closeRestaurant"));

        horizontalLayout->addWidget(pushButton_closeRestaurant);

        pushButton_changeAvailabilityMeals = new QPushButton(widget);
        pushButton_changeAvailabilityMeals->setObjectName(QString::fromUtf8("pushButton_changeAvailabilityMeals"));

        horizontalLayout->addWidget(pushButton_changeAvailabilityMeals);

        pushButton_changeAvailabilityIngredients = new QPushButton(widget);
        pushButton_changeAvailabilityIngredients->setObjectName(QString::fromUtf8("pushButton_changeAvailabilityIngredients"));

        horizontalLayout->addWidget(pushButton_changeAvailabilityIngredients);


        verticalLayout->addLayout(horizontalLayout);

        listWidget = new QListWidget(widget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        verticalLayout->addWidget(listWidget);

        pushButton_confirmOrder = new QPushButton(widget);
        pushButton_confirmOrder->setObjectName(QString::fromUtf8("pushButton_confirmOrder"));

        verticalLayout->addWidget(pushButton_confirmOrder);


        retranslateUi(mainwindowloggedin);

        pushButton_YourData->setDefault(false);


        QMetaObject::connectSlotsByName(mainwindowloggedin);
    } // setupUi

    void retranslateUi(QDialog *mainwindowloggedin)
    {
        mainwindowloggedin->setWindowTitle(QCoreApplication::translate("mainwindowloggedin", "Dialog", nullptr));
        pushButton_YourData->setText(QCoreApplication::translate("mainwindowloggedin", "Twoje dane", nullptr));
        pushButton_YourClients->setText(QCoreApplication::translate("mainwindowloggedin", "Twoi klienci", nullptr));
        pushButton_closeRestaurant->setText(QCoreApplication::translate("mainwindowloggedin", "Zamknij restauracje", nullptr));
        pushButton_changeAvailabilityMeals->setText(QCoreApplication::translate("mainwindowloggedin", "Zmie\305\204 dost\304\231pno\305\233\304\207 da\305\204", nullptr));
        pushButton_changeAvailabilityIngredients->setText(QCoreApplication::translate("mainwindowloggedin", "Zmie\305\204 dost\304\231pno\305\233\304\207 produkt\303\263w", nullptr));
        pushButton_confirmOrder->setText(QCoreApplication::translate("mainwindowloggedin", "Wybierz", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mainwindowloggedin: public Ui_mainwindowloggedin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOWLOGGEDIN_H
