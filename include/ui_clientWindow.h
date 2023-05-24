/********************************************************************************
** Form generated from reading UI file 'clientWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTWINDOW_H
#define UI_CLIENTWINDOW_H

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

class Ui_clientWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QGroupBox *groupBox;
    QLabel *ipLabel;
    QLabel *portLabel;
    QLabel *portBox;
    QLabel *ipBox;
    QPushButton *processButton_2;
    QPushButton *processButton_3;
    QPushButton *processButton_4;
    QPushButton *processButton_5;
    QPushButton *processButton_6;
    QPushButton *processButton_7;
    QPushButton *processButton_8;
    QPushButton *exitButton;
    QWidget *widget_2;
    QFrame *line;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *clientWindow)
    {
        if (clientWindow->objectName().isEmpty())
            clientWindow->setObjectName("clientWindow");
        clientWindow->resize(1351, 686);
        clientWindow->setStyleSheet(QString::fromUtf8("background-color: #ffffff;"));
        centralwidget = new QWidget(clientWindow);
        centralwidget->setObjectName("centralwidget");
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(20, 10, 301, 571));
        widget->setStyleSheet(QString::fromUtf8("background-color: #F2F6FC;\n"
"border-radius: 7px;"));
        groupBox = new QGroupBox(widget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(20, 40, 261, 91));
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
        processButton_2 = new QPushButton(widget);
        processButton_2->setObjectName("processButton_2");
        processButton_2->setGeometry(QRect(20, 170, 251, 30));
        processButton_2->setStyleSheet(QString::fromUtf8("font: 600 9pt \"UTM Avo\" ;\n"
"background: #C2E7FF;\n"
"border:  1px solid rgb(154, 154, 154);\n"
"border-radius: 5px;"));
        processButton_3 = new QPushButton(widget);
        processButton_3->setObjectName("processButton_3");
        processButton_3->setGeometry(QRect(20, 220, 121, 30));
        processButton_3->setStyleSheet(QString::fromUtf8("font: 600 9pt \"UTM Avo\" ;\n"
"background: #C2E7FF;\n"
"border:  1px solid rgb(154, 154, 154);\n"
"border-radius: 5px;"));
        processButton_4 = new QPushButton(widget);
        processButton_4->setObjectName("processButton_4");
        processButton_4->setGeometry(QRect(150, 220, 121, 30));
        processButton_4->setStyleSheet(QString::fromUtf8("font: 600 9pt \"UTM Avo\" ;\n"
"background: #C2E7FF;\n"
"border:  1px solid rgb(154, 154, 154);\n"
"border-radius: 5px;"));
        processButton_5 = new QPushButton(widget);
        processButton_5->setObjectName("processButton_5");
        processButton_5->setGeometry(QRect(20, 270, 251, 30));
        processButton_5->setStyleSheet(QString::fromUtf8("font: 600 9pt \"UTM Avo\" ;\n"
"background: #C2E7FF;\n"
"border:  1px solid rgb(154, 154, 154);\n"
"border-radius: 5px;"));
        processButton_6 = new QPushButton(widget);
        processButton_6->setObjectName("processButton_6");
        processButton_6->setGeometry(QRect(20, 320, 251, 30));
        processButton_6->setStyleSheet(QString::fromUtf8("font: 600 9pt \"UTM Avo\";\n"
"background: rgb(194, 231, 255);\n"
"border:  1px solid rgb(154, 154, 154);\n"
"border-radius: 5px;"));
        processButton_7 = new QPushButton(widget);
        processButton_7->setObjectName("processButton_7");
        processButton_7->setGeometry(QRect(20, 370, 251, 30));
        processButton_7->setStyleSheet(QString::fromUtf8("font: 600 9pt \"UTM Avo\" ;\n"
"background: #C2E7FF;\n"
"border:  1px solid rgb(154, 154, 154);\n"
"border-radius: 5px;"));
        processButton_8 = new QPushButton(widget);
        processButton_8->setObjectName("processButton_8");
        processButton_8->setGeometry(QRect(20, 420, 251, 30));
        processButton_8->setStyleSheet(QString::fromUtf8("font: 600 9pt \"UTM Avo\" ;\n"
"background: #C2E7FF;\n"
"border:  1px solid rgb(154, 154, 154);\n"
"border-radius: 5px;"));
        exitButton = new QPushButton(widget);
        exitButton->setObjectName("exitButton");
        exitButton->setGeometry(QRect(110, 500, 83, 29));
        exitButton->setStyleSheet(QString::fromUtf8("font: 600 9pt \"UTM Avo\" ;\n"
"background-color: rgb(0, 132, 255);\n"
"border-radius: 5px;\n"
"color: #ffffff;"));
        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(360, 10, 901, 571));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy);
        widget_2->setStyleSheet(QString::fromUtf8("border-radius: 5px;\n"
"background-color: #F2F6FC;"));
        line = new QFrame(centralwidget);
        line->setObjectName("line");
        line->setGeometry(QRect(330, 10, 20, 571));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        clientWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(clientWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1351, 26));
        clientWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(clientWindow);
        statusbar->setObjectName("statusbar");
        clientWindow->setStatusBar(statusbar);

        retranslateUi(clientWindow);

        QMetaObject::connectSlotsByName(clientWindow);
    } // setupUi

    void retranslateUi(QMainWindow *clientWindow)
    {
        clientWindow->setWindowTitle(QCoreApplication::translate("clientWindow", "MainWindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("clientWindow", "Server info", nullptr));
        ipLabel->setText(QCoreApplication::translate("clientWindow", "IP    ", nullptr));
        portLabel->setText(QCoreApplication::translate("clientWindow", "Port ", nullptr));
        portBox->setText(QCoreApplication::translate("clientWindow", "Port number", nullptr));
        ipBox->setText(QCoreApplication::translate("clientWindow", "IP address", nullptr));
        processButton_2->setText(QCoreApplication::translate("clientWindow", "Applications and Processes", nullptr));
        processButton_3->setText(QCoreApplication::translate("clientWindow", "Key Stroke", nullptr));
        processButton_4->setText(QCoreApplication::translate("clientWindow", "Screenshot", nullptr));
        processButton_5->setText(QCoreApplication::translate("clientWindow", "File Explorer", nullptr));
        processButton_6->setText(QCoreApplication::translate("clientWindow", "Screen Streaming", nullptr));
        processButton_7->setText(QCoreApplication::translate("clientWindow", "Audio Streaming", nullptr));
        processButton_8->setText(QCoreApplication::translate("clientWindow", "Keyboard + Mouse control", nullptr));
        exitButton->setText(QCoreApplication::translate("clientWindow", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class clientWindow: public Ui_clientWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTWINDOW_H
