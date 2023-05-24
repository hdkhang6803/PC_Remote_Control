/********************************************************************************
** Form generated from reading UI file 'clientwindow1.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTWINDOW1_H
#define UI_CLIENTWINDOW1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_clientWindow1
{
public:
    QWidget *centralwidget;
    QFrame *line;
    QWidget *widget;
    QGroupBox *groupBox;
    QLabel *ipLabel;
    QLabel *portLabel;
    QLabel *portBox;
    QLabel *ipBox;
    QPushButton *processButton_1;
    QPushButton *processButton_3;
    QPushButton *processButton_4;
    QPushButton *processButton_5;
    QPushButton *processButton_6;
    QPushButton *processButton_7;
    QPushButton *exitButton;
    QWidget *widget_2;
    QPushButton *exitButton_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *clientWindow1)
    {
        if (clientWindow1->objectName().isEmpty())
            clientWindow1->setObjectName("clientWindow1");
        clientWindow1->resize(1245, 647);
        clientWindow1->setStyleSheet(QString::fromUtf8("background-color: #ffffff;"));
        centralwidget = new QWidget(clientWindow1);
        centralwidget->setObjectName("centralwidget");
        line = new QFrame(centralwidget);
        line->setObjectName("line");
        line->setGeometry(QRect(300, 0, 20, 611));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 0, 301, 611));
        widget->setStyleSheet(QString::fromUtf8("background-color: #F2F6FC;\n"
"border-radius: 7px;"));
        groupBox = new QGroupBox(widget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(20, 30, 261, 91));
        groupBox->setStyleSheet(QString::fromUtf8("font: 600 12pt \"UTM Avo\";\n"
"border: 2px solid rgb(194, 231, 255);\n"
"color: #fffff;"));
        ipLabel = new QLabel(groupBox);
        ipLabel->setObjectName("ipLabel");
        ipLabel->setGeometry(QRect(20, 30, 34, 28));
        ipLabel->setStyleSheet(QString::fromUtf8("font: 570 9pt \"UTM Avo\";\n"
"border: none;"));
        portLabel = new QLabel(groupBox);
        portLabel->setObjectName("portLabel");
        portLabel->setGeometry(QRect(20, 50, 38, 36));
        portLabel->setStyleSheet(QString::fromUtf8("font: 600 9pt \"UTM Avo\";\n"
"border: none;"));
        portBox = new QLabel(groupBox);
        portBox->setObjectName("portBox");
        portBox->setGeometry(QRect(80, 30, 171, 24));
        portBox->setStyleSheet(QString::fromUtf8("font: italic 500 9pt \"UTM Avo\";\n"
"border: none;\n"
"font-color: rgb(255, 255, 255);"));
        ipBox = new QLabel(groupBox);
        ipBox->setObjectName("ipBox");
        ipBox->setGeometry(QRect(80, 60, 91, 21));
        ipBox->setStyleSheet(QString::fromUtf8("font: italic 500 9pt \"UTM Avo\";\n"
"border: none;"));
        processButton_1 = new QPushButton(widget);
        processButton_1->setObjectName("processButton_1");
        processButton_1->setGeometry(QRect(20, 160, 251, 30));
        processButton_1->setStyleSheet(QString::fromUtf8("font: 600 9pt \"UTM Avo\" ;\n"
"background: #C2E7FF;\n"
"border:  1px solid rgb(154, 154, 154);\n"
"border-radius: 5px;"));
        processButton_3 = new QPushButton(widget);
        processButton_3->setObjectName("processButton_3");
        processButton_3->setGeometry(QRect(20, 210, 251, 30));
        processButton_3->setStyleSheet(QString::fromUtf8("font: 600 9pt \"UTM Avo\" ;\n"
"background: #C2E7FF;\n"
"border:  1px solid rgb(154, 154, 154);\n"
"border-radius: 5px;"));
        processButton_4 = new QPushButton(widget);
        processButton_4->setObjectName("processButton_4");
        processButton_4->setGeometry(QRect(20, 260, 251, 30));
        processButton_4->setStyleSheet(QString::fromUtf8("font: 600 9pt \"UTM Avo\" ;\n"
"background: #C2E7FF;\n"
"border:  1px solid rgb(154, 154, 154);\n"
"border-radius: 5px;"));
        processButton_5 = new QPushButton(widget);
        processButton_5->setObjectName("processButton_5");
        processButton_5->setGeometry(QRect(20, 310, 251, 30));
        processButton_5->setStyleSheet(QString::fromUtf8("font: 600 9pt \"UTM Avo\" ;\n"
"background: #C2E7FF;\n"
"border:  1px solid rgb(154, 154, 154);\n"
"border-radius: 5px;"));
        processButton_6 = new QPushButton(widget);
        processButton_6->setObjectName("processButton_6");
        processButton_6->setGeometry(QRect(20, 360, 251, 30));
        processButton_6->setStyleSheet(QString::fromUtf8("font: 600 9pt \"UTM Avo\";\n"
"background: rgb(194, 231, 255);\n"
"border:  1px solid rgb(154, 154, 154);\n"
"border-radius: 5px;"));
        processButton_7 = new QPushButton(widget);
        processButton_7->setObjectName("processButton_7");
        processButton_7->setGeometry(QRect(20, 410, 251, 30));
        processButton_7->setStyleSheet(QString::fromUtf8("font: 600 9pt \"UTM Avo\" ;\n"
"background: #C2E7FF;\n"
"border:  1px solid rgb(154, 154, 154);\n"
"border-radius: 5px;"));
        exitButton = new QPushButton(widget);
        exitButton->setObjectName("exitButton");
        exitButton->setGeometry(QRect(80, 500, 121, 31));
        exitButton->setStyleSheet(QString::fromUtf8("font: 600 10pt \"UTM Avo\";\n"
"border: 1px solid rgb(194, 231, 255);\n"
"background-color: #ffffff;\n"
"border-radius: 10px;\n"
""));
        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(320, 0, 911, 611));
        widget_2->setStyleSheet(QString::fromUtf8("background-color: #F2F6FC;"));
        exitButton_2 = new QPushButton(widget_2);
        exitButton_2->setObjectName("exitButton_2");
        exitButton_2->setGeometry(QRect(870, 10, 31, 29));
        exitButton_2->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 0, 0);\n"
"color: #ffffff;\n"
"border: solid 2px;\n"
"font: 800;\n"
"border-radius: 5px;"));
        clientWindow1->setCentralWidget(centralwidget);
        menubar = new QMenuBar(clientWindow1);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1245, 26));
        clientWindow1->setMenuBar(menubar);
        statusbar = new QStatusBar(clientWindow1);
        statusbar->setObjectName("statusbar");
        clientWindow1->setStatusBar(statusbar);

        retranslateUi(clientWindow1);

        QMetaObject::connectSlotsByName(clientWindow1);
    } // setupUi

    void retranslateUi(QMainWindow *clientWindow1)
    {
        clientWindow1->setWindowTitle(QCoreApplication::translate("clientWindow1", "MainWindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("clientWindow1", "Server info", nullptr));
        ipLabel->setText(QCoreApplication::translate("clientWindow1", "IP    ", nullptr));
        portLabel->setText(QCoreApplication::translate("clientWindow1", "Port ", nullptr));
        portBox->setText(QCoreApplication::translate("clientWindow1", "Port number", nullptr));
        ipBox->setText(QCoreApplication::translate("clientWindow1", "IP address", nullptr));
        processButton_1->setText(QCoreApplication::translate("clientWindow1", "Processes and Applications", nullptr));
        processButton_3->setText(QCoreApplication::translate("clientWindow1", "Key Stroke", nullptr));
        processButton_4->setText(QCoreApplication::translate("clientWindow1", "Screenshot", nullptr));
        processButton_5->setText(QCoreApplication::translate("clientWindow1", "File Explorer", nullptr));
        processButton_6->setText(QCoreApplication::translate("clientWindow1", "Screen Streaming", nullptr));
        processButton_7->setText(QCoreApplication::translate("clientWindow1", "Audio Streaming", nullptr));
        exitButton->setText(QCoreApplication::translate("clientWindow1", "Exit", nullptr));
        exitButton_2->setText(QCoreApplication::translate("clientWindow1", "X", nullptr));
    } // retranslateUi

};

namespace Ui {
    class clientWindow1: public Ui_clientWindow1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTWINDOW1_H
