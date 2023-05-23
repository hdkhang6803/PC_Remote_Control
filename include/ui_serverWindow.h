/********************************************************************************
** Form generated from reading UI file 'serverWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVERWINDOW_H
#define UI_SERVERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ServerWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_2;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *ipLabel;
    QLineEdit *ipBox;
    QLabel *portLabel;
    QLineEdit *portBox;
    QLabel *statusLabel;
    QLabel *statusBox;
    QWidget *widget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *restartButton;
    QPushButton *exitButton;

    void setupUi(QMainWindow *ServerWindow)
    {
        if (ServerWindow->objectName().isEmpty())
            ServerWindow->setObjectName("ServerWindow");
        ServerWindow->resize(843, 488);
        centralwidget = new QWidget(ServerWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(580, 280, 160, 80));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayoutWidget_2 = new QWidget(centralwidget);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(110, 30, 411, 371));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget_2 = new QWidget(verticalLayoutWidget_2);
        widget_2->setObjectName("widget_2");
        formLayoutWidget = new QWidget(widget_2);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(0, 20, 321, 161));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        ipLabel = new QLabel(formLayoutWidget);
        ipLabel->setObjectName("ipLabel");
        QFont font;
        font.setPointSize(9);
        ipLabel->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, ipLabel);

        ipBox = new QLineEdit(formLayoutWidget);
        ipBox->setObjectName("ipBox");
        ipBox->setFont(font);
        ipBox->setReadOnly(true);

        formLayout->setWidget(0, QFormLayout::FieldRole, ipBox);

        portLabel = new QLabel(formLayoutWidget);
        portLabel->setObjectName("portLabel");
        portLabel->setFont(font);

        formLayout->setWidget(1, QFormLayout::LabelRole, portLabel);

        portBox = new QLineEdit(formLayoutWidget);
        portBox->setObjectName("portBox");
        portBox->setFont(font);

        formLayout->setWidget(1, QFormLayout::FieldRole, portBox);

        statusLabel = new QLabel(formLayoutWidget);
        statusLabel->setObjectName("statusLabel");
        statusLabel->setFont(font);

        formLayout->setWidget(2, QFormLayout::LabelRole, statusLabel);

        statusBox = new QLabel(formLayoutWidget);
        statusBox->setObjectName("statusBox");
        QFont font1;
        font1.setPointSize(12);
        statusBox->setFont(font1);

        formLayout->setWidget(2, QFormLayout::FieldRole, statusBox);


        verticalLayout_2->addWidget(widget_2);

        widget = new QWidget(verticalLayoutWidget_2);
        widget->setObjectName("widget");
        horizontalLayoutWidget = new QWidget(widget);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(0, 20, 169, 80));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        restartButton = new QPushButton(horizontalLayoutWidget);
        restartButton->setObjectName("restartButton");
        restartButton->setFont(font);

        horizontalLayout->addWidget(restartButton);

        exitButton = new QPushButton(horizontalLayoutWidget);
        exitButton->setObjectName("exitButton");
        exitButton->setFont(font);

        horizontalLayout->addWidget(exitButton);


        verticalLayout_2->addWidget(widget);

        ServerWindow->setCentralWidget(centralwidget);

        retranslateUi(ServerWindow);

        QMetaObject::connectSlotsByName(ServerWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ServerWindow)
    {
        ServerWindow->setWindowTitle(QCoreApplication::translate("ServerWindow", "MainWindow", nullptr));
        ipLabel->setText(QCoreApplication::translate("ServerWindow", "IP", nullptr));
        portLabel->setText(QCoreApplication::translate("ServerWindow", "Port", nullptr));
        statusLabel->setText(QCoreApplication::translate("ServerWindow", "Status", nullptr));
        statusBox->setText(QString());
        restartButton->setText(QCoreApplication::translate("ServerWindow", "Restart", nullptr));
        exitButton->setText(QCoreApplication::translate("ServerWindow", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ServerWindow: public Ui_ServerWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVERWINDOW_H
