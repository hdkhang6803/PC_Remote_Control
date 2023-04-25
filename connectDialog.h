#ifndef CONNECTDIALOG_H
#define CONNECTDIALOG_H

#include <QDataStream>
#include <QDialog>
#include <QTcpSocket>

#include "client.h"

QT_BEGIN_NAMESPACE
class QComboBox;
class QLabel;
class QLineEdit;
class QPushButton;
class QTcpSocket;
QT_END_NAMESPACE

namespace Ui {
class ConnectDialog;
}

class ConnectDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ConnectDialog(QWidget *parent = nullptr);
    ~ConnectDialog();

signals:
    void connectToServer(const QString &serverIp, int port);

private slots:
    void on_buttonBox_accepted();

private:
    Ui::ConnectDialog *ui;

private:
    void populateIpAddresses();
};

#endif // CONNECTDIALOG_H
