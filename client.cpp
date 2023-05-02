
#include "client.h"

#include <QDebug>

Client::Client(QObject *parent)
    : QObject(parent),
    tcpSocket(new QTcpSocket(this))
{
    connect(tcpSocket, &QTcpSocket::connected, this, &Client::connected);
    connect(tcpSocket, &QTcpSocket::disconnected, this, &Client::disconnected);
    connect(tcpSocket, &QAbstractSocket::errorOccurred, this, &Client::error);

    connect(tcpSocket, &QTcpSocket::readyRead, this, &Client::readMessage);
    in.setDevice(tcpSocket);
    in.setVersion(QDataStream::Qt_6_5);
}

void Client::connectToServer(const QString &serverIp, int port) {
    tcpSocket->connectToHost(serverIp, port);
    qDebug() << "Connected server.";
}

void Client::sendMessage(const QString &cmdNumber) {
//    QByteArray block;
//    QDataStream out(&block, QIODevice::WriteOnly);
//    out.setVersion(QDataStream::Qt_6_5);

//    out << cmdNumber;
    QByteArray block = cmdNumber.toUtf8();
    qDebug() << cmdNumber << " == " <<block.data();
    tcpSocket->write(block);
}

void Client::readMessage() {
    qDebug() << "A message just got to server!";
    in.startTransaction();

    QString message;
    in >> message;

    if (!in.commitTransaction())
        return;

    emit (readyRead(message));
}
