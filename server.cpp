
#include "server.h"

#include <QDebug>
#include "audiorecorder.h"


Server::Server(QObject *parent)
    : QObject{parent}
{
    initServer();
    connect(tcpServer, &QTcpServer::newConnection, this, &Server::newConnection);
}

void Server::initServer()
{
    tcpServer = new QTcpServer(this);
    if (!tcpServer->listen()) {
//        QMessageBox::critical(this, tr("Fortune Server"),
//                              tr("Unable to start the server: %1.")
//                                  .arg(tcpServer->errorString()));
        qDebug() << "Unable to start server.";
        return;
    }

    const QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
    // use the first non-localhost IPv4 address
    for (const QHostAddress &entry : ipAddressesList) {
        if (entry != QHostAddress::LocalHost && entry.toIPv4Address()) {
            ipAddress = entry.toString();
            break;
        }
    }
    // if we did not find one, use IPv4 localhost
    if (ipAddress.isEmpty())
        ipAddress = QHostAddress(QHostAddress::LocalHost).toString();

    //! [1]
    port = QString::number(tcpServer->serverPort());
}

void Server::sendMessage(const QString &msg)
{
    if (!curClient) return;
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_5);

    out << msg;
    curClient->write(block);
}



void Server::readMessage() {
    qDebug() << "A message just got to server!";

    in.startTransaction();

    QByteArray message_bytes;
    in >> message_bytes;
    QString message = QString(message_bytes);
    qDebug() << message_bytes.data() << " == " << message;

    if (!in.commitTransaction())
        return;

//  statusLabel->setText(message);

    if (message == tr("list applications")) {
        sendMessage("here are the applications: ");
    }
    else if (message == tr("list processes")) {
        sendMessage("here are the processes: ");
    }
    else if (message == tr("recording")){
        if (recorder == nullptr)
            recorder = new AudioRecorder;
        recorder->show();

        recorder->auto_start();
    }
    else if (message == tr("stop_recording")){
        recorder->stop_by_msg();
        delete recorder;
    }

    emit(readyRead(message));
}

void Server::newConnection() {
    QTcpSocket *clientConnection = tcpServer->nextPendingConnection();
    connect(clientConnection, &QTcpSocket::readyRead, this, &Server::readMessage);

    curClient = clientConnection;
    in.setDevice(clientConnection);
    in.setVersion(QDataStream::Qt_6_5);
}
