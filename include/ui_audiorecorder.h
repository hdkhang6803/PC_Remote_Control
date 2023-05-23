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

    void setupUi(QWidget *audiorecorder)
    {
        if (audiorecorder->objectName().isEmpty())
            audiorecorder->setObjectName("audiorecorder");
        audiorecorder->resize(900, 571);
        audiorecorder->setStyleSheet(QString::fromUtf8("border-radius: 5px;\n"
"background-color: #F2F6FC;"));
        stopButton = new QPushButton(audiorecorder);
        stopButton->setObjectName("stopButton");
        stopButton->setGeometry(QRect(330, 270, 131, 41));
        stopButton->setStyleSheet(QString::fromUtf8("border-radius: 20px;\n"
"font: 600 9pt \"UTM Avo\";\n"
"box-shadow:  10px 5px 5px rgb(0, 0, 0);\n"
"background: #C2E7FF;\n"
"border:  1px solid rgb(154, 154, 154);\n"
"\n"
""));
        timer = new QLabel(audiorecorder);
        timer->setObjectName("timer");
        timer->setGeometry(QRect(530, 270, 121, 41));
        timer->setStyleSheet(QString::fromUtf8("font: 600 10pt \"UTM Avo\";\n"
"\n"
""));

        retranslateUi(audiorecorder);

        QMetaObject::connectSlotsByName(audiorecorder);
    } // setupUi

    void retranslateUi(QWidget *audiorecorder)
    {
        audiorecorder->setWindowTitle(QCoreApplication::translate("audiorecorder", "Form", nullptr));
        stopButton->setText(QCoreApplication::translate("audiorecorder", "Stop", nullptr));
        timer->setText(QCoreApplication::translate("audiorecorder", "01:00", nullptr));
    } // retranslateUi

};

namespace Ui {
    class audiorecorder: public Ui_audiorecorder {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUDIORECORDER_H
