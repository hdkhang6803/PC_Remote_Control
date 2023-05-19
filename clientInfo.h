#ifndef CONNECTDIALOG_H
#define CONNECTDIALOG_H

#include <QDataStream>
#include <QDialog>
//#include <QTcpSocket>

#include "client.h"
#include <QMainWindow>

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

namespace Ui {
class clientInfo;
}

class clientInfo : public QMainWindow
{
    Q_OBJECT

public:
    explicit clientInfo(QWidget *parent = nullptr);
//    ~ConnectDialog();

signals:
    void connectToServer(const QString &serverIp, int port);
    void exit();

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

private:
    Ui::clientInfo *ui;
    QLabel *ipLabel = nullptr;
    QLabel *portLabel = nullptr;
    QLineEdit *ipBox = nullptr;
    QLineEdit *portBox = nullptr;
    QLabel *statusLabel = nullptr;
    QLineEdit *statusBox = nullptr;

    QPushButton *connectButton = nullptr;
    QPushButton *exitButton = nullptr;
};

#endif // CONNECTDIALOG_H
