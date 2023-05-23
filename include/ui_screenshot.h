/********************************************************************************
** Form generated from reading UI file 'screenshot.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCREENSHOT_H
#define UI_SCREENSHOT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_screenshot
{
public:
    QLabel *screenLabel;
    QPushButton *captureButton;
    QPushButton *saveButton;

    void setupUi(QWidget *screenshot)
    {
        if (screenshot->objectName().isEmpty())
            screenshot->setObjectName("screenshot");
        screenshot->resize(904, 572);
        screenshot->setStyleSheet(QString::fromUtf8("border-radius: 5px;\n"
"background-color: #F2F6FC;"));
        screenLabel = new QLabel(screenshot);
        screenLabel->setObjectName("screenLabel");
        screenLabel->setGeometry(QRect(20, 20, 861, 491));
        screenLabel->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"border: 2px solid;\n"
"padding-left: 370px;\n"
"font: 500 9pt \"UTM Avo\";\n"
"\n"
""));
        screenLabel->setTextFormat(Qt::RichText);
        captureButton = new QPushButton(screenshot);
        captureButton->setObjectName("captureButton");
        captureButton->setGeometry(QRect(290, 520, 131, 31));
        captureButton->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"font: 600 9pt \"UTM Avo\";\n"
"box-shadow:  10px 5px 5px rgb(0, 0, 0);\n"
"background: #C2E7FF;\n"
"border:  1px solid rgb(154, 154, 154);\n"
"\n"
""));
        saveButton = new QPushButton(screenshot);
        saveButton->setObjectName("saveButton");
        saveButton->setGeometry(QRect(470, 520, 131, 31));
        saveButton->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"font: 600 9pt \"UTM Avo\";\n"
"box-shadow:  10px 5px 5px rgb(0, 0, 0);\n"
"background: #C2E7FF;\n"
"border:  1px solid rgb(154, 154, 154);\n"
"\n"
""));

        retranslateUi(screenshot);

        QMetaObject::connectSlotsByName(screenshot);
    } // setupUi

    void retranslateUi(QWidget *screenshot)
    {
        screenshot->setWindowTitle(QCoreApplication::translate("screenshot", "Form", nullptr));
        screenLabel->setText(QCoreApplication::translate("screenshot", "No screenshot", nullptr));
        captureButton->setText(QCoreApplication::translate("screenshot", "Capture", nullptr));
        saveButton->setText(QCoreApplication::translate("screenshot", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class screenshot: public Ui_screenshot {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCREENSHOT_H
