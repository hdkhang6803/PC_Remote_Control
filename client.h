
#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QPixmap>
#include <QFileSystemModel>

class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject *parent = nullptr);

signals:
    void connected();
    void disconnected();
    void stringMessageReceived(const QString &message);
    void imageMessageReceived(const QPixmap &image);
    void fileStructReceived(const QFileSystemModel &model);
    void error(QAbstractSocket::SocketError socketError);
public slots:
    void connectToServer(const QString &serverIp, int port);
    void sendMessage(const QString &cmdNumber);
    void readMessage();
private:
    QTcpSocket *tcpSocket = nullptr;
    QDataStream in;
    QByteArray buffer;
};

#endif // CLIENT_H
