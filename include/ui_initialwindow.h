/********************************************************************************
** Form generated from reading UI file 'initialwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INITIALWINDOW_H
#define UI_INITIALWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_initialWindow
{
public:
    QWidget *centralwidget;
    QWidget *connectWidget_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *initialWindow)
    {
        if (initialWindow->objectName().isEmpty())
            initialWindow->setObjectName("initialWindow");
        initialWindow->resize(1308, 641);
        initialWindow->setStyleSheet(QString::fromUtf8("background-color: #ffffff;"));
        centralwidget = new QWidget(initialWindow);
        centralwidget->setObjectName("centralwidget");
        connectWidget_2 = new QWidget(centralwidget);
        connectWidget_2->setObjectName("connectWidget_2");
        connectWidget_2->setGeometry(QRect(300, 110, 441, 381));
        connectWidget_2->setStyleSheet(QString::fromUtf8("border-radius: 5px;\n"
"background-color: #F2F6FC;"));
        pushButton_2 = new QPushButton(connectWidget_2);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(110, 90, 231, 91));
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: rgb(194, 231, 255);\n"
"font:  600 10pt \"UTM Avo\";\n"
"border-radius: 5px;\n"
"border: 2px solid;\n"
"box-shadow: 5px 5px;"));
        pushButton_3 = new QPushButton(connectWidget_2);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(110, 220, 231, 91));
        pushButton_3->setStyleSheet(QString::fromUtf8("background-color: rgb(194, 231, 255);\n"
"font:  600 10pt \"UTM Avo\";\n"
"border-radius: 5px;\n"
"border: 2px solid;\n"
""));
        initialWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(initialWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1308, 26));
        initialWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(initialWindow);
        statusbar->setObjectName("statusbar");
        initialWindow->setStatusBar(statusbar);

        retranslateUi(initialWindow);

        QMetaObject::connectSlotsByName(initialWindow);
    } // setupUi

    void retranslateUi(QMainWindow *initialWindow)
    {
        initialWindow->setWindowTitle(QCoreApplication::translate("initialWindow", "MainWindow", nullptr));
        pushButton_2->setText(QCoreApplication::translate("initialWindow", "Create a Server", nullptr));
        pushButton_3->setText(QCoreApplication::translate("initialWindow", "Connect to a Server", nullptr));
    } // retranslateUi

};

namespace Ui {
    class initialWindow: public Ui_initialWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INITIALWINDOW_H
