/********************************************************************************
** Form generated from reading UI file 'apps.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APPS_H
#define UI_APPS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_apps
{
public:
    QTabWidget *tabWidget;
    QWidget *runningProcessesTab;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QWidget *runningAppsTab;
    QTableView *runningAppTable;
    QWidget *allAppsTab;
    QTableView *appTable;
    QPushButton *exitButton;

    void setupUi(QWidget *apps)
    {
        if (apps->objectName().isEmpty())
            apps->setObjectName("apps");
        apps->resize(912, 573);
        apps->setStyleSheet(QString::fromUtf8("border-radius: 5px;\n"
"background-color: #F2F6FC;"));
        tabWidget = new QTabWidget(apps);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(0, 0, 901, 521));
        tabWidget->setStyleSheet(QString::fromUtf8("font: 500 10pt \"UTM Avo\";"));
        runningProcessesTab = new QWidget();
        runningProcessesTab->setObjectName("runningProcessesTab");
        scrollArea = new QScrollArea(runningProcessesTab);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(20, 20, 851, 471));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 851, 471));
        scrollArea->setWidget(scrollAreaWidgetContents);
        tabWidget->addTab(runningProcessesTab, QString());
        runningAppsTab = new QWidget();
        runningAppsTab->setObjectName("runningAppsTab");
        runningAppTable = new QTableView(runningAppsTab);
        runningAppTable->setObjectName("runningAppTable");
        runningAppTable->setGeometry(QRect(20, 20, 851, 451));
        tabWidget->addTab(runningAppsTab, QString());
        allAppsTab = new QWidget();
        allAppsTab->setObjectName("allAppsTab");
        appTable = new QTableView(allAppsTab);
        appTable->setObjectName("appTable");
        appTable->setGeometry(QRect(20, 20, 851, 451));
        tabWidget->addTab(allAppsTab, QString());
        exitButton = new QPushButton(apps);
        exitButton->setObjectName("exitButton");
        exitButton->setGeometry(QRect(400, 530, 111, 31));
        exitButton->setStyleSheet(QString::fromUtf8("font: 600 10pt \"UTM Avo\";\n"
"border: 1px solid rgb(194, 231, 255);\n"
"background-color: #ffffff;\n"
"border-radius: 5px;\n"
""));

        retranslateUi(apps);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(apps);
    } // setupUi

    void retranslateUi(QWidget *apps)
    {
        apps->setWindowTitle(QCoreApplication::translate("apps", "Form", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(runningProcessesTab), QCoreApplication::translate("apps", "Running Processes", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(runningAppsTab), QCoreApplication::translate("apps", "Running applications", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(allAppsTab), QCoreApplication::translate("apps", "All applications", nullptr));
        exitButton->setText(QCoreApplication::translate("apps", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class apps: public Ui_apps {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPS_H
