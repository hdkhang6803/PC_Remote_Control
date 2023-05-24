/********************************************************************************
** Form generated from reading UI file 'screendisplayer.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCREENDISPLAYER_H
#define UI_SCREENDISPLAYER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_screendisplayer
{
public:
    QLabel *screenLabel;
    QPushButton *startButton;
    QPushButton *exitButton;

    void setupUi(QWidget *screendisplayer)
    {
        if (screendisplayer->objectName().isEmpty())
            screendisplayer->setObjectName("screendisplayer");
        screendisplayer->resize(903, 573);
        screendisplayer->setStyleSheet(QString::fromUtf8("border-radius: 5px;\n"
"background-color: #F2F6FC;"));
        screenLabel = new QLabel(screendisplayer);
        screenLabel->setObjectName("screenLabel");
        screenLabel->setGeometry(QRect(10, 50, 881, 461));
        screenLabel->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"border: 2px solid;\n"
"padding-left: 370px;\n"
"font: 500 9pt \"UTM Avo\";\n"
"\n"
""));
        screenLabel->setTextFormat(Qt::RichText);
        startButton = new QPushButton(screendisplayer);
        startButton->setObjectName("startButton");
        startButton->setGeometry(QRect(300, 520, 131, 31));
        startButton->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"font: 600 9pt \"UTM Avo\";\n"
"box-shadow:  10px 5px 5px rgb(0, 0, 0);\n"
"background: #C2E7FF;\n"
"border:  1px solid rgb(154, 154, 154);\n"
"\n"
""));
        exitButton = new QPushButton(screendisplayer);
        exitButton->setObjectName("exitButton");
        exitButton->setGeometry(QRect(460, 520, 121, 31));
        exitButton->setStyleSheet(QString::fromUtf8("font: 600 10pt \"UTM Avo\";\n"
"border: 1px solid rgb(194, 231, 255);\n"
"background-color: #ffffff;\n"
"border-radius: 10px;\n"
""));

        retranslateUi(screendisplayer);

        QMetaObject::connectSlotsByName(screendisplayer);
    } // setupUi

    void retranslateUi(QWidget *screendisplayer)
    {
        screendisplayer->setWindowTitle(QCoreApplication::translate("screendisplayer", "Form", nullptr));
        screenLabel->setText(QCoreApplication::translate("screendisplayer", "No screenstream", nullptr));
        startButton->setText(QCoreApplication::translate("screendisplayer", "Start", nullptr));
        exitButton->setText(QCoreApplication::translate("screendisplayer", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class screendisplayer: public Ui_screendisplayer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCREENDISPLAYER_H
