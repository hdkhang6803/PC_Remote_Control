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
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_apps
{
public:
    QTabWidget *tabWidget;
    QWidget *runningProcessesTab;
    QTableView *processTable;
    QPushButton *reloadButton;
    QPushButton *stopButton;
    QPushButton *exitButton;
    QWidget *runningAppsTab;
    QTreeView *runningAppTree;
    QPushButton *startButton_2;
    QPushButton *stopButton_2;
    QPushButton *exitButton_2;
    QPushButton *reloadButton_2;
    QWidget *allAppsTab;
    QTreeView *appTree;
    QPushButton *startButton_3;
    QPushButton *reloadButton_3;
    QPushButton *exitButton_3;

    void setupUi(QWidget *apps)
    {
        if (apps->objectName().isEmpty())
            apps->setObjectName("apps");
        apps->resize(912, 573);
        apps->setStyleSheet(QString::fromUtf8("border-radius: 5px;\n"
"background-color: #F2F6FC;"));
        tabWidget = new QTabWidget(apps);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(0, 0, 901, 571));
        tabWidget->setStyleSheet(QString::fromUtf8("font: 500 10pt \"UTM Avo\";"));
        runningProcessesTab = new QWidget();
        runningProcessesTab->setObjectName("runningProcessesTab");
        processTable = new QTableView(runningProcessesTab);
        processTable->setObjectName("processTable");
        processTable->setGeometry(QRect(20, 20, 851, 451));
        reloadButton = new QPushButton(runningProcessesTab);
        reloadButton->setObjectName("reloadButton");
        reloadButton->setGeometry(QRect(220, 490, 121, 31));
        reloadButton->setStyleSheet(QString::fromUtf8("font: 600 10pt \"UTM Avo\";\n"
"border: 1px solid rgb(194, 231, 255);\n"
"background-color: #ffffff;\n"
"border-radius: 5px;\n"
""));
        stopButton = new QPushButton(runningProcessesTab);
        stopButton->setObjectName("stopButton");
        stopButton->setGeometry(QRect(370, 490, 151, 31));
        stopButton->setStyleSheet(QString::fromUtf8("font: 600 10pt \"UTM Avo\";\n"
"border: 1px solid rgb(194, 231, 255);\n"
"background-color: rgb(194, 231, 255);\n"
"border-radius: 10px;\n"
""));
        exitButton = new QPushButton(runningProcessesTab);
        exitButton->setObjectName("exitButton");
        exitButton->setGeometry(QRect(550, 490, 121, 31));
        exitButton->setStyleSheet(QString::fromUtf8("font: 600 10pt \"UTM Avo\";\n"
"border: 1px solid rgb(194, 231, 255);\n"
"background-color: #ffffff;\n"
"border-radius: 5px;\n"
""));
        tabWidget->addTab(runningProcessesTab, QString());
        runningAppsTab = new QWidget();
        runningAppsTab->setObjectName("runningAppsTab");
        runningAppTree = new QTreeView(runningAppsTab);
        runningAppTree->setObjectName("runningAppTree");
        runningAppTree->setGeometry(QRect(20, 20, 871, 451));
        startButton_2 = new QPushButton(runningAppsTab);
        startButton_2->setObjectName("startButton_2");
        startButton_2->setGeometry(QRect(310, 490, 121, 31));
        startButton_2->setStyleSheet(QString::fromUtf8("font: 600 10pt \"UTM Avo\";\n"
"border: 1px solid rgb(194, 231, 255);\n"
"background-color: rgb(194, 231, 255);\n"
"border-radius: 10px;\n"
""));
        stopButton_2 = new QPushButton(runningAppsTab);
        stopButton_2->setObjectName("stopButton_2");
        stopButton_2->setGeometry(QRect(460, 490, 121, 31));
        stopButton_2->setStyleSheet(QString::fromUtf8("font: 600 10pt \"UTM Avo\";\n"
"border: 1px solid rgb(194, 231, 255);\n"
"background-color: rgb(194, 231, 255);\n"
"border-radius: 10px;\n"
""));
        exitButton_2 = new QPushButton(runningAppsTab);
        exitButton_2->setObjectName("exitButton_2");
        exitButton_2->setGeometry(QRect(610, 490, 121, 31));
        exitButton_2->setStyleSheet(QString::fromUtf8("font: 600 10pt \"UTM Avo\";\n"
"border: 1px solid rgb(194, 231, 255);\n"
"background-color: #ffffff;\n"
"border-radius: 5px;\n"
""));
        reloadButton_2 = new QPushButton(runningAppsTab);
        reloadButton_2->setObjectName("reloadButton_2");
        reloadButton_2->setGeometry(QRect(160, 490, 121, 31));
        reloadButton_2->setStyleSheet(QString::fromUtf8("font: 600 10pt \"UTM Avo\";\n"
"border: 1px solid rgb(194, 231, 255);\n"
"background-color: #ffffff;\n"
"border-radius: 5px;\n"
""));
        tabWidget->addTab(runningAppsTab, QString());
        allAppsTab = new QWidget();
        allAppsTab->setObjectName("allAppsTab");
        appTree = new QTreeView(allAppsTab);
        appTree->setObjectName("appTree");
        appTree->setGeometry(QRect(20, 10, 871, 461));
        startButton_3 = new QPushButton(allAppsTab);
        startButton_3->setObjectName("startButton_3");
        startButton_3->setGeometry(QRect(400, 490, 121, 31));
        startButton_3->setStyleSheet(QString::fromUtf8("font: 600 10pt \"UTM Avo\";\n"
"border: 1px solid rgb(194, 231, 255);\n"
"background-color: rgb(194, 231, 255);\n"
"border-radius: 10px;\n"
""));
        reloadButton_3 = new QPushButton(allAppsTab);
        reloadButton_3->setObjectName("reloadButton_3");
        reloadButton_3->setGeometry(QRect(250, 490, 121, 31));
        reloadButton_3->setStyleSheet(QString::fromUtf8("font: 600 10pt \"UTM Avo\";\n"
"border: 1px solid rgb(194, 231, 255);\n"
"background-color: #ffffff;\n"
"border-radius: 5px;\n"
""));
        exitButton_3 = new QPushButton(allAppsTab);
        exitButton_3->setObjectName("exitButton_3");
        exitButton_3->setGeometry(QRect(550, 490, 121, 31));
        exitButton_3->setStyleSheet(QString::fromUtf8("font: 600 10pt \"UTM Avo\";\n"
"border: 1px solid rgb(194, 231, 255);\n"
"background-color: #ffffff;\n"
"border-radius: 5px;\n"
""));
        tabWidget->addTab(allAppsTab, QString());

        retranslateUi(apps);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(apps);
    } // setupUi

    void retranslateUi(QWidget *apps)
    {
        apps->setWindowTitle(QCoreApplication::translate("apps", "Form", nullptr));
        reloadButton->setText(QCoreApplication::translate("apps", "Reload", nullptr));
        stopButton->setText(QCoreApplication::translate("apps", " Kill process", nullptr));
        exitButton->setText(QCoreApplication::translate("apps", "Exit", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(runningProcessesTab), QCoreApplication::translate("apps", "Running Processes", nullptr));
        startButton_2->setText(QCoreApplication::translate("apps", "Start", nullptr));
        stopButton_2->setText(QCoreApplication::translate("apps", "Stop", nullptr));
        exitButton_2->setText(QCoreApplication::translate("apps", "Exit", nullptr));
        reloadButton_2->setText(QCoreApplication::translate("apps", "Reload", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(runningAppsTab), QCoreApplication::translate("apps", "Running applications", nullptr));
        startButton_3->setText(QCoreApplication::translate("apps", "Start", nullptr));
        reloadButton_3->setText(QCoreApplication::translate("apps", "Reload", nullptr));
        exitButton_3->setText(QCoreApplication::translate("apps", "Exit", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(allAppsTab), QCoreApplication::translate("apps", "All applications", nullptr));
    } // retranslateUi

};

namespace Ui {
    class apps: public Ui_apps {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPS_H
