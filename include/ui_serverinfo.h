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
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_serverInfo
{
public:
    QWidget *centralwidget;
    QWidget *connectWidget;
    QLabel *IDlabel;
    QLabel *portLabel;
    QLineEdit *portInput;
    QPushButton *exitButton;
    QLabel *statusLabel;
    QTextEdit *statusText;
<<<<<<< HEAD
    QTextEdit *IDInput;
=======
    QTextEdit *IPInput;
>>>>>>> 0bcd9ef0c187252ff7022416289f373dd0043275
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *serverInfo)
    {
        if (serverInfo->objectName().isEmpty())
            serverInfo->setObjectName("serverInfo");
<<<<<<< HEAD
        serverInfo->resize(332, 422);
=======
        serverInfo->resize(332, 489);
>>>>>>> 0bcd9ef0c187252ff7022416289f373dd0043275
        serverInfo->setStyleSheet(QString::fromUtf8("background-color: #ffffff;"));
        centralwidget = new QWidget(serverInfo);
        centralwidget->setObjectName("centralwidget");
        connectWidget = new QWidget(centralwidget);
        connectWidget->setObjectName("connectWidget");
<<<<<<< HEAD
        connectWidget->setGeometry(QRect(0, 0, 331, 391));
=======
        connectWidget->setGeometry(QRect(0, 0, 331, 431));
>>>>>>> 0bcd9ef0c187252ff7022416289f373dd0043275
        connectWidget->setStyleSheet(QString::fromUtf8("border-radius: 5px;\n"
"background-color: #F2F6FC;"));
        IDlabel = new QLabel(connectWidget);
        IDlabel->setObjectName("IDlabel");
<<<<<<< HEAD
        IDlabel->setGeometry(QRect(40, 10, 251, 20));
=======
        IDlabel->setGeometry(QRect(40, 20, 251, 20));
>>>>>>> 0bcd9ef0c187252ff7022416289f373dd0043275
        IDlabel->setStyleSheet(QString::fromUtf8("font: italic 600 10pt \"UTM Avo\";\n"
"border: none;"));
        portLabel = new QLabel(connectWidget);
        portLabel->setObjectName("portLabel");
<<<<<<< HEAD
        portLabel->setGeometry(QRect(40, 110, 251, 20));
=======
        portLabel->setGeometry(QRect(40, 140, 251, 20));
>>>>>>> 0bcd9ef0c187252ff7022416289f373dd0043275
        portLabel->setStyleSheet(QString::fromUtf8("font: italic 600 10pt \"UTM Avo\";\n"
"border: none;"));
        portInput = new QLineEdit(connectWidget);
        portInput->setObjectName("portInput");
<<<<<<< HEAD
        portInput->setGeometry(QRect(40, 140, 251, 41));
=======
        portInput->setEnabled(true);
        portInput->setGeometry(QRect(40, 170, 251, 41));
>>>>>>> 0bcd9ef0c187252ff7022416289f373dd0043275
        portInput->setStyleSheet(QString::fromUtf8("background-color: #ffffff;\n"
"border: 1px #000000;\n"
"border-radius: 5px;\n"
"padding-left: 10px;"));
<<<<<<< HEAD
        exitButton = new QPushButton(connectWidget);
        exitButton->setObjectName("exitButton");
        exitButton->setGeometry(QRect(110, 340, 93, 31));
=======
        portInput->setReadOnly(true);
        exitButton = new QPushButton(connectWidget);
        exitButton->setObjectName("exitButton");
        exitButton->setGeometry(QRect(110, 380, 93, 31));
>>>>>>> 0bcd9ef0c187252ff7022416289f373dd0043275
        exitButton->setStyleSheet(QString::fromUtf8("font: 600 10pt \"UTM Avo\";\n"
"border: none;\n"
"background-color: rgb(0, 132, 255);\n"
"border-radius: 5px;"));
        statusLabel = new QLabel(connectWidget);
        statusLabel->setObjectName("statusLabel");
<<<<<<< HEAD
        statusLabel->setGeometry(QRect(40, 190, 251, 20));
=======
        statusLabel->setGeometry(QRect(40, 220, 251, 20));
>>>>>>> 0bcd9ef0c187252ff7022416289f373dd0043275
        statusLabel->setStyleSheet(QString::fromUtf8("font: italic 600 10pt \"UTM Avo\";\n"
"border: none;"));
        statusText = new QTextEdit(connectWidget);
        statusText->setObjectName("statusText");
        statusText->setEnabled(false);
<<<<<<< HEAD
        statusText->setGeometry(QRect(40, 220, 251, 111));
=======
        statusText->setGeometry(QRect(40, 250, 251, 111));
>>>>>>> 0bcd9ef0c187252ff7022416289f373dd0043275
        statusText->setStyleSheet(QString::fromUtf8("background-color: #ffffff;\n"
"border: 1px #000000;\n"
"border-radius: 5px;\n"
"padding: 10px;"));
<<<<<<< HEAD
        IDInput = new QTextEdit(connectWidget);
        IDInput->setObjectName("IDInput");
        IDInput->setEnabled(false);
        IDInput->setGeometry(QRect(40, 40, 251, 61));
        IDInput->setStyleSheet(QString::fromUtf8("background-color: #ffffff;\n"
"border: 1px #000000;\n"
"border-radius: 5px;\n"
"padding: 10px;"));
=======
        IPInput = new QTextEdit(connectWidget);
        IPInput->setObjectName("IPInput");
        IPInput->setEnabled(true);
        IPInput->setGeometry(QRect(40, 50, 251, 81));
        IPInput->setStyleSheet(QString::fromUtf8("background-color: #ffffff;\n"
"border: 1px #000000;\n"
"border-radius: 5px;\n"
"padding: 10px;"));
        IPInput->setUndoRedoEnabled(true);
        IPInput->setReadOnly(true);
>>>>>>> 0bcd9ef0c187252ff7022416289f373dd0043275
        serverInfo->setCentralWidget(centralwidget);
        menubar = new QMenuBar(serverInfo);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 332, 26));
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
        IDlabel->setText(QCoreApplication::translate("serverInfo", "Server's IP", nullptr));
        portLabel->setText(QCoreApplication::translate("serverInfo", "Server's Port", nullptr));
        portInput->setText(QCoreApplication::translate("serverInfo", "14326", nullptr));
        exitButton->setText(QCoreApplication::translate("serverInfo", "Exit", nullptr));
        statusLabel->setText(QCoreApplication::translate("serverInfo", "Server's Status", nullptr));
        statusText->setHtml(QCoreApplication::translate("serverInfo", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Server has been created successfully!</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Server has been created successfully!</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Server has been created successfully!</p>\n"
"<p style=\" margin-top:0"
                        "px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Server has been created successfully!</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Server has been created successfully!</p></body></html>", nullptr));
<<<<<<< HEAD
        IDInput->setHtml(QCoreApplication::translate("serverInfo", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
=======
        IPInput->setHtml(QCoreApplication::translate("serverInfo", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
>>>>>>> 0bcd9ef0c187252ff7022416289f373dd0043275
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
<<<<<<< HEAD
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">172.80.2.17</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">172.80.2.17</p></body></html>", nullptr));
=======
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">192.1.2.45</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">192.1.2.45</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">192.1.2.45</p></body></html>", nullptr));
>>>>>>> 0bcd9ef0c187252ff7022416289f373dd0043275
    } // retranslateUi

};

namespace Ui {
    class serverInfo: public Ui_serverInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVERINFO_H
