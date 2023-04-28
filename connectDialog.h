#ifndef CONNECTDIALOG_H
#define CONNECTDIALOG_H

#include <QDataStream>
#include <QDialog>
//#include <QTcpSocket>

#include "client.h"

QT_BEGIN_NAMESPACE
class QLabel;
class QLineEdit;
class QPushButton;
class QTcpSocket;
class QHBoxLayout;
class QDialogButtonBox;
class QFormLayout;
class QVBoxLayout;
QT_END_NAMESPACE

//namespace Ui {
//class ConnectDialog;
//}

class ConnectDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ConnectDialog(QWidget *parent = nullptr);
//    ~ConnectDialog();

signals:
    void connectToServer(const QString &serverIp, int port);
    void exit();

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

private:
//    Ui::ConnectDialog *ui;
    QVBoxLayout *overallLayout = nullptr;
    QWidget *serverInfoWidget = nullptr;
    QWidget *buttonsWidget = nullptr;

    QFormLayout *serverInfoLayout = nullptr;
    QLabel *ipLabel = nullptr;
    QLabel *portLabel = nullptr;
    QLineEdit *ipBox = nullptr;
    QLineEdit *portBox = nullptr;
    QLabel *statusLabel = nullptr;/*
    QLineEdit *statusBox = nullptr;*/

    QHBoxLayout *buttonsLayout = nullptr;
    QDialogButtonBox *dialogButtonBox = nullptr;
    QPushButton *okButton = nullptr;
    QPushButton *cancelButton = nullptr;
};

#endif // CONNECTDIALOG_H
