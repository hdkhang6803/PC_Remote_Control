
#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QString>
#include <QList>
#include <QtNetwork>
#include "audiorecorder.h"

class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = nullptr);

signals:
    void connected();
    void disconnected();
    void readyRead(const QString &cmdNumber);
    void error(QAbstractSocket::SocketError socketError);
private slots:
    void sendMessage(const QString &cmdNumber);
    void readMessage();
    void newConnection();
private:
    void initServer();

public:
    QString ipAddress;
    QString port;
private:
    QTcpServer *tcpServer = nullptr;
    QTcpSocket *curClient = nullptr;
    QDataStream in;
    AudioRecorder * recorder = nullptr;

};

#endif // SERVER_H
