
#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>

class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject *parent = nullptr);

signals:
    void connected();
    void disconnected();
    void readyRead(const QString &cmdNumber);
    void error(QAbstractSocket::SocketError socketError);
public slots:
    void connectToServer(const QString &serverIp, int port);
    void sendMessage(const QString &cmdNumber);
    void readMessage();
private:
    QTcpSocket *tcpSocket = nullptr;
    QDataStream in;
};

#endif // CLIENT_H
