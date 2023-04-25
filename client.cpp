
#include "client.h"

Client::Client(QObject *parent)
    : QObject(parent),
    tcpSocket(new QTcpSocket(this))
{
    connect(tcpSocket, &QTcpSocket::connected, this, &Client::connected);
    connect(tcpSocket, &QTcpSocket::disconnected, this, &Client::disconnected);
    connect(tcpSocket, &QTcpSocket::readyRead, this, &Client::readyRead);
    connect(tcpSocket, &QAbstractSocket::errorOccurred, this, &Client::error);

}

void Client::connectToServer(const QString &serverIp, int port) {
    tcpSocket->connectToHost(serverIp, port);
}

void Client::sendMessage(const QString &cmtNumber) {
    tcpSocket->write(cmtNumber.toUtf8());
}
