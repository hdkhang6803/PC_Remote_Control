/********************************************************************************
** Form generated from reading UI file 'audiorecorder.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUDIORECORDER_H
#define UI_AUDIORECORDER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_audiorecorder
{
public:
    QPushButton *stopButton;
    QLabel *timer;
    QPushButton *exitButton;

    void setupUi(QWidget *audiorecorder)
    {
        if (audiorecorder->objectName().isEmpty())
            audiorecorder->setObjectName("audiorecorder");
        audiorecorder->resize(900, 571);
        audiorecorder->setStyleSheet(QString::fromUtf8("border-radius: 5px;\n"
"background-color: #F2F6FC;"));
        stopButton = new QPushButton(audiorecorder);
        stopButton->setObjectName("stopButton");
        stopButton->setGeometry(QRect(320, 290, 121, 31));
        stopButton->setStyleSheet(QString::fromUtf8("font: 600 10pt \"UTM Avo\";\n"
"border: 1px solid rgb(194, 231, 255);\n"
"background-color: rgb(194, 231, 255);\n"
"border-radius: 10px;\n"
""));
        timer = new QLabel(audiorecorder);
        timer->setObjectName("timer");
        timer->setGeometry(QRect(260, 190, 401, 61));
        timer->setStyleSheet(QString::fromUtf8("font: 600 10pt \"UTM Avo\";\n"
"background-color: #ffffff;\n"
"border: 2px solid;\n"
"\n"
""));
        timer->setAlignment(Qt::AlignCenter);
        exitButton = new QPushButton(audiorecorder);
        exitButton->setObjectName("exitButton");
        exitButton->setGeometry(QRect(470, 290, 111, 31));
        exitButton->setStyleSheet(QString::fromUtf8("font: 600 10pt \"UTM Avo\";\n"
"border: 1px solid rgb(194, 231, 255);\n"
"background-color: #ffffff;\n"
"border-radius: 10px;\n"
""));

        retranslateUi(audiorecorder);

        QMetaObject::connectSlotsByName(audiorecorder);
    } // setupUi

    void retranslateUi(QWidget *audiorecorder)
    {
        audiorecorder->setWindowTitle(QCoreApplication::translate("audiorecorder", "Form", nullptr));
        stopButton->setText(QCoreApplication::translate("audiorecorder", "Stop", nullptr));
        timer->setText(QCoreApplication::translate("audiorecorder", "01:00", nullptr));
        exitButton->setText(QCoreApplication::translate("audiorecorder", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class audiorecorder: public Ui_audiorecorder {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUDIORECORDER_H
