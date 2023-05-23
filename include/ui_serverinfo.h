/********************************************************************************
** Form generated from reading UI file 'serverinfo.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVERINFO_H
#define UI_SERVERINFO_H

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

class Ui_serverInfo
{
public:
    QWidget *centralwidget;
    QWidget *connectWidget;
    QLineEdit *IDinput;
    QLabel *IDlabel;
    QLabel *portLabel;
    QLineEdit *portInput;
    QPushButton *pushButton;
    QLineEdit *portInput_2;
    QLabel *portLabel_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *serverInfo)
    {
        if (serverInfo->objectName().isEmpty())
            serverInfo->setObjectName("serverInfo");
        serverInfo->resize(1303, 634);
        serverInfo->setStyleSheet(QString::fromUtf8("background-color: #ffffff;"));
        centralwidget = new QWidget(serverInfo);
        centralwidget->setObjectName("centralwidget");
        connectWidget = new QWidget(centralwidget);
        connectWidget->setObjectName("connectWidget");
        connectWidget->setGeometry(QRect(220, 80, 841, 461));
        connectWidget->setStyleSheet(QString::fromUtf8("border-radius: 5px;\n"
"background-color: #F2F6FC;"));
        IDinput = new QLineEdit(connectWidget);
        IDinput->setObjectName("IDinput");
        IDinput->setGeometry(QRect(130, 90, 561, 51));
        IDinput->setStyleSheet(QString::fromUtf8("background-color: #ffffff;\n"
"border: 1px #000000;\n"
"border-radius: 5px;\n"
"padding-left: 10px;"));
        IDlabel = new QLabel(connectWidget);
        IDlabel->setObjectName("IDlabel");
        IDlabel->setGeometry(QRect(130, 50, 251, 20));
        IDlabel->setStyleSheet(QString::fromUtf8("font: italic 600 10pt \"UTM Avo\";\n"
"border: none;"));
        portLabel = new QLabel(connectWidget);
        portLabel->setObjectName("portLabel");
        portLabel->setGeometry(QRect(130, 160, 251, 20));
        portLabel->setStyleSheet(QString::fromUtf8("font: italic 600 10pt \"UTM Avo\";\n"
"border: none;"));
        portInput = new QLineEdit(connectWidget);
        portInput->setObjectName("portInput");
        portInput->setGeometry(QRect(130, 200, 561, 51));
        portInput->setStyleSheet(QString::fromUtf8("background-color: #ffffff;\n"
"border: 1px #000000;\n"
"border-radius: 5px;\n"
"padding-left: 10px;"));
        pushButton = new QPushButton(connectWidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(360, 390, 93, 41));
        pushButton->setStyleSheet(QString::fromUtf8("font: 600 10pt \"UTM Avo\";\n"
"border: none;\n"
"background-color: rgb(0, 132, 255);\n"
"border-radius: 5px;"));
        portInput_2 = new QLineEdit(connectWidget);
        portInput_2->setObjectName("portInput_2");
        portInput_2->setGeometry(QRect(130, 310, 561, 51));
        portInput_2->setStyleSheet(QString::fromUtf8("background-color: #ffffff;\n"
"border: 1px #000000;\n"
"border-radius: 5px;\n"
"font: 500 10pt \"UTM Avo\";\n"
"padding-left: 9.5px;"));
        portLabel_2 = new QLabel(connectWidget);
        portLabel_2->setObjectName("portLabel_2");
        portLabel_2->setGeometry(QRect(130, 270, 251, 20));
        portLabel_2->setStyleSheet(QString::fromUtf8("font: italic 600 10pt \"UTM Avo\";\n"
"border: none;"));
        serverInfo->setCentralWidget(centralwidget);
        menubar = new QMenuBar(serverInfo);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1303, 26));
        serverInfo->setMenuBar(menubar);
        statusbar = new QStatusBar(serverInfo);
        statusbar->setObjectName("statusbar");
        serverInfo->setStatusBar(statusbar);

        retranslateUi(serverInfo);

        QMetaObject::connectSlotsByName(serverInfo);
    } // setupUi

    void retranslateUi(QMainWindow *serverInfo)
    {
        serverInfo->setWindowTitle(QCoreApplication::translate("serverInfo", "MainWindow", nullptr));
        IDinput->setText(QCoreApplication::translate("serverInfo", "172.80.2.17", nullptr));
        IDlabel->setText(QCoreApplication::translate("serverInfo", "Server's ID", nullptr));
        portLabel->setText(QCoreApplication::translate("serverInfo", "Server's Port", nullptr));
        portInput->setText(QCoreApplication::translate("serverInfo", "14326", nullptr));
        pushButton->setText(QCoreApplication::translate("serverInfo", "Exit", nullptr));
        portInput_2->setText(QCoreApplication::translate("serverInfo", "Server has been created successfully!", nullptr));
        portLabel_2->setText(QCoreApplication::translate("serverInfo", "Server's Status", nullptr));
    } // retranslateUi

};

namespace Ui {
    class serverInfo: public Ui_serverInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVERINFO_H
