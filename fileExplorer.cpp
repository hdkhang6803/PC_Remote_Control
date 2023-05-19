#include "fileExplorer.h"
#include "D:\University\Year_2\HK2\MMT\Project_3\include\ui_fileExplorer.h"

fileExplorer::fileExplorer(QTcpServer *parServer, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::fileExplorer)
{
    ui->setupUi(this);

    server = parServer;
//    server->listen(QHostAddress::Any, 8888);
    qDebug() << server->serverAddress() << " " << server->serverPort();
    clients = QList<QTcpSocket*>();
    connect(server, &QTcpServer::newConnection, this, &fileExplorer::handleNewConnection);
}

fileExplorer::~fileExplorer()
{
    delete ui;
}

void fileExplorer::handleNewConnection()
{
    qDebug() << "File explorer: Incoming connection.";
    QTcpSocket *clientSocket = server->nextPendingConnection();
    connect(clientSocket, &QTcpSocket::readyRead, this, &fileExplorer::handleReadyRead);
    connect(clientSocket, &QTcpSocket::disconnected, this, &fileExplorer::handleClientDisconnected);
    clients.append(clientSocket);
}

void fileExplorer::sendMessage(QTcpSocket* sender, const QStringList &msg)
{
    //    QTcpSocket *clientSocket = static_cast<QTcpSocket*>(sender());
    //    if (clientSocket != nullptr) {
    //        qDebug() << "send message client connection not null";
    //    }
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_5);

    out << tr("file") << msg;
    sender->write(block);
}

void fileExplorer::handleReadyRead()
{
    qDebug() << "Received a message from client. Processing.";
    QTcpSocket *clientSocket = static_cast<QTcpSocket*>(sender());

    QDataStream in;
    in.setDevice(clientSocket);
    in.setVersion(QDataStream::Qt_6_5);
    in.startTransaction();

    QString message;
    in >> message;

    if (!in.commitTransaction())
        return;
    if (message == "ls") {
//        QString dirPath = args.size() > 1 ? args[1] : ".";
        QString dirPath = ".";
        QDir dir(dirPath);
        QStringList entries = dir.entryList();
        QString response = entries.join("\n");
        sendMessage(clientSocket, entries);
        qDebug() << entries << "\n";
//        clientSocket->flush();
    }
}

void fileExplorer::handleClientDisconnected()
{
    QTcpSocket *clientSocket = static_cast<QTcpSocket*>(sender());
    clients.removeOne(clientSocket);
}
