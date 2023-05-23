/********************************************************************************
** Form generated from reading UI file 'keystroke.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KEYSTROKE_H
#define UI_KEYSTROKE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_keystroke
{
public:
    QTextEdit *textEdit;
    QLabel *label;
    QLabel *label_2;
    QTextEdit *textEdit_2;
    QPushButton *startButton;

    void setupUi(QWidget *keystroke)
    {
        if (keystroke->objectName().isEmpty())
            keystroke->setObjectName("keystroke");
        keystroke->resize(902, 572);
        keystroke->setStyleSheet(QString::fromUtf8("border-radius: 5px;\n"
"background-color: #F2F6FC;"));
        textEdit = new QTextEdit(keystroke);
        textEdit->setObjectName("textEdit");
        textEdit->setEnabled(false);
        textEdit->setGeometry(QRect(60, 90, 361, 381));
        textEdit->setStyleSheet(QString::fromUtf8("background-color: #ffffff;\n"
"border: 1px solid;\n"
"border-radius: 5px;\n"
"padding: 10px;\n"
"font:  500 10pt \"UTM Avo\";"));
        label = new QLabel(keystroke);
        label->setObjectName("label");
        label->setGeometry(QRect(210, 50, 63, 20));
        label->setStyleSheet(QString::fromUtf8("font: 600 10pt \"UTM Avo\";"));
        label_2 = new QLabel(keystroke);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(620, 50, 81, 20));
        label_2->setStyleSheet(QString::fromUtf8("font: 600 10pt \"UTM Avo\";"));
        textEdit_2 = new QTextEdit(keystroke);
        textEdit_2->setObjectName("textEdit_2");
        textEdit_2->setEnabled(false);
        textEdit_2->setGeometry(QRect(470, 90, 361, 381));
        textEdit_2->setStyleSheet(QString::fromUtf8("background-color: #ffffff;\n"
"border: 1px solid;\n"
"border-radius: 5px;\n"
"padding: 10px;\n"
"font: 500 10pt \"UTM Avo\";"));
        startButton = new QPushButton(keystroke);
        startButton->setObjectName("startButton");
        startButton->setGeometry(QRect(380, 500, 131, 31));
        startButton->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"font: 600 9pt \"UTM Avo\";\n"
"box-shadow:  10px 5px 5px rgb(0, 0, 0);\n"
"background: #C2E7FF;\n"
"border:  1px solid rgb(154, 154, 154);\n"
"\n"
""));

        retranslateUi(keystroke);

        QMetaObject::connectSlotsByName(keystroke);
    } // setupUi

    void retranslateUi(QWidget *keystroke)
    {
        keystroke->setWindowTitle(QCoreApplication::translate("keystroke", "Form", nullptr));
        textEdit->setHtml(QCoreApplication::translate("keystroke", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'UTM Avo'; font-size:10pt; font-weight:500; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Shift k</p></body></html>", nullptr));
        label->setText(QCoreApplication::translate("keystroke", "Keys", nullptr));
        label_2->setText(QCoreApplication::translate("keystroke", "Display", nullptr));
        textEdit_2->setHtml(QCoreApplication::translate("keystroke", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'UTM Avo'; font-size:10pt; font-weight:500; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">K</p></body></html>", nullptr));
        startButton->setText(QCoreApplication::translate("keystroke", "Stop", nullptr));
    } // retranslateUi

};

namespace Ui {
    class keystroke: public Ui_keystroke {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KEYSTROKE_H
