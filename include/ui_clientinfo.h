/********************************************************************************
** Form generated from reading UI file 'clientinfo.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTINFO_H
#define UI_CLIENTINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_clientInfo
{
public:
    QWidget *centralwidget;
    QWidget *connectWidget;
    QLineEdit *IDinput;
    QLabel *IDlabel;
    QLabel *portLabel;
    QLineEdit *portInput;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *failLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *clientInfo)
    {
        if (clientInfo->objectName().isEmpty())
            clientInfo->setObjectName("clientInfo");
<<<<<<< HEAD
        clientInfo->resize(333, 347);
=======
        clientInfo->resize(334, 436);
>>>>>>> 0bcd9ef0c187252ff7022416289f373dd0043275
        clientInfo->setStyleSheet(QString::fromUtf8("background-color: #ffffff;"));
        centralwidget = new QWidget(clientInfo);
        centralwidget->setObjectName("centralwidget");
        connectWidget = new QWidget(centralwidget);
        connectWidget->setObjectName("connectWidget");
<<<<<<< HEAD
        connectWidget->setGeometry(QRect(0, 0, 331, 301));
=======
        connectWidget->setGeometry(QRect(0, 0, 331, 391));
>>>>>>> 0bcd9ef0c187252ff7022416289f373dd0043275
        connectWidget->setStyleSheet(QString::fromUtf8("border-radius: 5px;\n"
"background-color: #F2F6FC;"));
        IDinput = new QLineEdit(connectWidget);
        IDinput->setObjectName("IDinput");
<<<<<<< HEAD
        IDinput->setGeometry(QRect(40, 60, 251, 41));
        IDinput->setStyleSheet(QString::fromUtf8("background-color: #ffffff;\n"
"border: 1px #000000;\n"
"border-radius: 5px;\n"
"padding: 10px;"));
        IDlabel = new QLabel(connectWidget);
        IDlabel->setObjectName("IDlabel");
        IDlabel->setGeometry(QRect(40, 30, 251, 20));
=======
        IDinput->setGeometry(QRect(40, 100, 251, 41));
        IDinput->setStyleSheet(QString::fromUtf8("background-color: #ffffff;\n"
"border: 1px #000000;\n"
"border-radius: 5px;\n"
"padding-left: 10px;"));
        IDinput->setReadOnly(false);
        IDlabel = new QLabel(connectWidget);
        IDlabel->setObjectName("IDlabel");
        IDlabel->setGeometry(QRect(40, 60, 251, 20));
>>>>>>> 0bcd9ef0c187252ff7022416289f373dd0043275
        IDlabel->setStyleSheet(QString::fromUtf8("font: italic 600 10pt \"UTM Avo\";\n"
"border: none;"));
        portLabel = new QLabel(connectWidget);
        portLabel->setObjectName("portLabel");
<<<<<<< HEAD
        portLabel->setGeometry(QRect(40, 110, 251, 20));
=======
        portLabel->setGeometry(QRect(40, 160, 251, 20));
>>>>>>> 0bcd9ef0c187252ff7022416289f373dd0043275
        portLabel->setStyleSheet(QString::fromUtf8("font: italic 600 10pt \"UTM Avo\";\n"
"border: none;"));
        portInput = new QLineEdit(connectWidget);
        portInput->setObjectName("portInput");
<<<<<<< HEAD
        portInput->setGeometry(QRect(40, 140, 251, 41));
        portInput->setStyleSheet(QString::fromUtf8("background-color: #ffffff;\n"
"border: 1px #000000;\n"
"border-radius: 5px;\n"
"padding: 10px;"));
        pushButton = new QPushButton(connectWidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(40, 240, 111, 31));
=======
        portInput->setGeometry(QRect(40, 200, 251, 41));
        portInput->setStyleSheet(QString::fromUtf8("background-color: #ffffff;\n"
"border: 1px #000000;\n"
"border-radius: 5px;\n"
"padding-left: 10px;"));
        pushButton = new QPushButton(connectWidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(40, 310, 111, 31));
>>>>>>> 0bcd9ef0c187252ff7022416289f373dd0043275
        pushButton->setStyleSheet(QString::fromUtf8("font: 600 10pt \"UTM Avo\";\n"
"border: 1px solid rgb(7, 7, 248);\n"
"background-color: rgb(0, 132, 255);\n"
"border-radius: 5px;\n"
"color: #ffffff;"));
        pushButton_2 = new QPushButton(connectWidget);
        pushButton_2->setObjectName("pushButton_2");
<<<<<<< HEAD
        pushButton_2->setGeometry(QRect(180, 240, 111, 31));
=======
        pushButton_2->setGeometry(QRect(180, 310, 111, 31));
>>>>>>> 0bcd9ef0c187252ff7022416289f373dd0043275
        pushButton_2->setStyleSheet(QString::fromUtf8("font: 600 10pt \"UTM Avo\";\n"
"border: 1px solid rgb(194, 231, 255);\n"
"background-color: #ffffff;\n"
"border-radius: 5px;\n"
""));
        failLabel = new QLabel(connectWidget);
        failLabel->setObjectName("failLabel");
<<<<<<< HEAD
        failLabel->setGeometry(QRect(60, 190, 361, 41));
        failLabel->setStyleSheet(QString::fromUtf8("font: italic 600 9pt \"UTM Avo\";\n"
"border: none;\n"
"text-align: justify;\n"
"color: rgb(170, 0, 0);\n"
""));
        clientInfo->setCentralWidget(centralwidget);
        menubar = new QMenuBar(clientInfo);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 333, 26));
=======
        failLabel->setGeometry(QRect(40, 260, 321, 31));
        failLabel->setStyleSheet(QString::fromUtf8("font: bold 600 9pt \"UTM Avo\";\n"
"color: rgb(170, 0, 0);\n"
"border: none;\n"
"text-align: justify;"));
        clientInfo->setCentralWidget(centralwidget);
        menubar = new QMenuBar(clientInfo);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 334, 26));
>>>>>>> 0bcd9ef0c187252ff7022416289f373dd0043275
        clientInfo->setMenuBar(menubar);
        statusbar = new QStatusBar(clientInfo);
        statusbar->setObjectName("statusbar");
        clientInfo->setStatusBar(statusbar);

        retranslateUi(clientInfo);

        QMetaObject::connectSlotsByName(clientInfo);
    } // setupUi

    void retranslateUi(QMainWindow *clientInfo)
    {
        clientInfo->setWindowTitle(QCoreApplication::translate("clientInfo", "MainWindow", nullptr));
        IDlabel->setText(QCoreApplication::translate("clientInfo", "Server's ID", nullptr));
        portLabel->setText(QCoreApplication::translate("clientInfo", "Server's Port", nullptr));
        pushButton->setText(QCoreApplication::translate("clientInfo", "Connect", nullptr));
        pushButton_2->setText(QCoreApplication::translate("clientInfo", "Exit", nullptr));
        failLabel->setText(QCoreApplication::translate("clientInfo", "Connect unsuccessfully. Try again!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class clientInfo: public Ui_clientInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTINFO_H
