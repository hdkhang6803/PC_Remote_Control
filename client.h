
#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QPixmap>
#include <QStandardItemModel>
#include <QFileInfo>
#include <QSettings>
#include <QFileIconProvider>

class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject *parent = nullptr);

signals:

    void m_connected();
    void m_unconnected();

    void stringMessageReceived(const QString &message);
    void imageMessageReceived(const QPixmap &image);
    void fileStructReceived(QStandardItemModel* &model);
    void error(QAbstractSocket::SocketError socketError);
public slots:
    void connectToServer(const QString &serverIp, int port);
    void sendMessage(const QString &cmdNumber);
    void readMessage();
    void m_disconnected();

private:
    QTcpSocket *tcpSocket = nullptr;
    QDataStream in;
    QByteArray buffer;
};

#endif // CLIENT_H
