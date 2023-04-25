
#ifndef SERVER_H
#define SERVER_H

#include <QDialog>
#include <QString>
#include <QList>

QT_BEGIN_NAMESPACE
class QLabel;
class QTcpServer;
QT_END_NAMESPACE


class Server : public QDialog
{
    Q_OBJECT

public:
    explicit Server(QWidget *parent = nullptr);

private slots:
    void sendMessage();
    void readMessage();

private:
    void initServer();

    QString ipAddress;
    QString port;
    QTcpServer *tcpServer = nullptr;
    QLabel *statusLabel = nullptr;
};

#endif // SERVER_H
