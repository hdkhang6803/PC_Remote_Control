/********************************************************************************
** Form generated from reading UI file 'connectDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNECTDIALOG_H
#define UI_CONNECTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_ConnectDialog
{
public:
    QDialogButtonBox *confirmButton;
    QLabel *serverIp;
    QLineEdit *serverPortBox;
    QLineEdit *IPinput;

    void setupUi(QDialog *ConnectDialog)
    {
        if (ConnectDialog->objectName().isEmpty())
            ConnectDialog->setObjectName("ConnectDialog");
        ConnectDialog->resize(400, 300);
        ConnectDialog->setStyleSheet(QString::fromUtf8("background: rgb(252, 255, 194);\n"
"border-radius: 5;"));
        confirmButton = new QDialogButtonBox(ConnectDialog);
        confirmButton->setObjectName("confirmButton");
        confirmButton->setGeometry(QRect(30, 240, 311, 31));
        confirmButton->setStyleSheet(QString::fromUtf8("font: 500 10pt \"UTM Avo\";\n"
"font-color: rgb(255, 255, 255);\n"
"background-color: rgb(255, 255, 127);"));
        confirmButton->setOrientation(Qt::Horizontal);
        confirmButton->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        serverIp = new QLabel(ConnectDialog);
        serverIp->setObjectName("serverIp");
        serverIp->setGeometry(QRect(60, 60, 41, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("UTM Avo")});
        font.setPointSize(12);
        font.setBold(false);
        font.setItalic(false);
        serverIp->setFont(font);
        serverIp->setStyleSheet(QString::fromUtf8("font: 500 12pt \"UTM Avo\";"));
        serverPortBox = new QLineEdit(ConnectDialog);
        serverPortBox->setObjectName("serverPortBox");
        serverPortBox->setGeometry(QRect(130, 110, 221, 41));
        serverPortBox->setStyleSheet(QString::fromUtf8("border: 2px solid rgb(126, 126, 126);\n"
"background-color: rgb(255, 255, 127);\n"
"border-radius: 5px;"));
        IPinput = new QLineEdit(ConnectDialog);
        IPinput->setObjectName("IPinput");
        IPinput->setGeometry(QRect(130, 60, 221, 41));
        IPinput->setStyleSheet(QString::fromUtf8("border: 2px solid rgb(126, 126, 126);\n"
"background-color: rgb(255, 255, 127);\n"
"border-radius: 5px;"));

        retranslateUi(ConnectDialog);
        QObject::connect(confirmButton, &QDialogButtonBox::accepted, ConnectDialog, qOverload<>(&QDialog::accept));
        QObject::connect(confirmButton, &QDialogButtonBox::rejected, ConnectDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(ConnectDialog);
    } // setupUi

    void retranslateUi(QDialog *ConnectDialog)
    {
        ConnectDialog->setWindowTitle(QCoreApplication::translate("ConnectDialog", "Connect to a server", nullptr));
        serverIp->setText(QCoreApplication::translate("ConnectDialog", "IP", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ConnectDialog: public Ui_ConnectDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECTDIALOG_H
