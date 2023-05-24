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
<<<<<<< HEAD
=======
    QPushButton *exitButton;
>>>>>>> 0bcd9ef0c187252ff7022416289f373dd0043275

    void setupUi(QWidget *screenshot)
    {
        if (screenshot->objectName().isEmpty())
            screenshot->setObjectName("screenshot");
        screenshot->resize(904, 572);
        screenshot->setStyleSheet(QString::fromUtf8("border-radius: 5px;\n"
"background-color: #F2F6FC;"));
        screenLabel = new QLabel(screenshot);
        screenLabel->setObjectName("screenLabel");
<<<<<<< HEAD
        screenLabel->setGeometry(QRect(20, 20, 861, 491));
        screenLabel->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"border: 2px solid;\n"
"padding-left: 370px;\n"
=======
        screenLabel->setGeometry(QRect(10, 10, 881, 501));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(screenLabel->sizePolicy().hasHeightForWidth());
        screenLabel->setSizePolicy(sizePolicy);
        screenLabel->setMaximumSize(QSize(16777215, 16777215));
        screenLabel->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"border: 2px solid;\n"
>>>>>>> 0bcd9ef0c187252ff7022416289f373dd0043275
"font: 500 9pt \"UTM Avo\";\n"
"\n"
""));
        screenLabel->setTextFormat(Qt::RichText);
<<<<<<< HEAD
        captureButton = new QPushButton(screenshot);
        captureButton->setObjectName("captureButton");
        captureButton->setGeometry(QRect(290, 520, 131, 31));
=======
        screenLabel->setPixmap(QPixmap(QString::fromUtf8("C:/Users/LENOVO/Downloads/CLINIC.drawio.png")));
        screenLabel->setScaledContents(true);
        screenLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        screenLabel->setWordWrap(false);
        screenLabel->setIndent(0);
        captureButton = new QPushButton(screenshot);
        captureButton->setObjectName("captureButton");
        captureButton->setGeometry(QRect(220, 520, 131, 31));
>>>>>>> 0bcd9ef0c187252ff7022416289f373dd0043275
        captureButton->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"font: 600 9pt \"UTM Avo\";\n"
"box-shadow:  10px 5px 5px rgb(0, 0, 0);\n"
"background: #C2E7FF;\n"
"border:  1px solid rgb(154, 154, 154);\n"
"\n"
""));
        saveButton = new QPushButton(screenshot);
        saveButton->setObjectName("saveButton");
<<<<<<< HEAD
        saveButton->setGeometry(QRect(470, 520, 131, 31));
=======
        saveButton->setGeometry(QRect(380, 520, 131, 31));
>>>>>>> 0bcd9ef0c187252ff7022416289f373dd0043275
        saveButton->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"font: 600 9pt \"UTM Avo\";\n"
"box-shadow:  10px 5px 5px rgb(0, 0, 0);\n"
"background: #C2E7FF;\n"
"border:  1px solid rgb(154, 154, 154);\n"
"\n"
""));
<<<<<<< HEAD
=======
        exitButton = new QPushButton(screenshot);
        exitButton->setObjectName("exitButton");
        exitButton->setGeometry(QRect(540, 520, 121, 31));
        exitButton->setStyleSheet(QString::fromUtf8("font: 600 10pt \"UTM Avo\";\n"
"border: 1px solid rgb(194, 231, 255);\n"
"background-color: #ffffff;\n"
"border-radius: 10px;\n"
""));
>>>>>>> 0bcd9ef0c187252ff7022416289f373dd0043275

        retranslateUi(screenshot);

        QMetaObject::connectSlotsByName(screenshot);
    } // setupUi

    void retranslateUi(QWidget *screenshot)
    {
        screenshot->setWindowTitle(QCoreApplication::translate("screenshot", "Form", nullptr));
<<<<<<< HEAD
        screenLabel->setText(QCoreApplication::translate("screenshot", "No screenshot", nullptr));
        captureButton->setText(QCoreApplication::translate("screenshot", "Capture", nullptr));
        saveButton->setText(QCoreApplication::translate("screenshot", "Save", nullptr));
=======
        screenLabel->setText(QString());
        captureButton->setText(QCoreApplication::translate("screenshot", "Capture", nullptr));
        saveButton->setText(QCoreApplication::translate("screenshot", "Save", nullptr));
        exitButton->setText(QCoreApplication::translate("screenshot", "Exit", nullptr));
>>>>>>> 0bcd9ef0c187252ff7022416289f373dd0043275
    } // retranslateUi

};

namespace Ui {
    class screenshot: public Ui_screenshot {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCREENSHOT_H
