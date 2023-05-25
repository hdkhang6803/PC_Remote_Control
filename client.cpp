
#include "client.h"
#include "clientWindow.h"

#include <QDebug>
#include <QMediaPlayer>
#include <QMediaDevices>
#include <QAudioOutput>
#include <QAudioDevice>
#include <QBuffer>
#include <QElapsedTimer>

Client::Client(QObject *parent)
    : QObject(parent),
    tcpSocket(new QTcpSocket(this))
{
//    connect(tcpSocket, &QTcpSocket::connected, this, &Client::_connected);
    connect(tcpSocket, &QTcpSocket::disconnected, this, &Client::m_disconnected);
    connect(tcpSocket, &QAbstractSocket::errorOccurred, this, &Client::error);

    connect(tcpSocket, &QTcpSocket::readyRead, this, &Client::readMessage);
    in.setDevice(tcpSocket);
    in.setVersion(QDataStream::Qt_6_5);
}

void Client::m_disconnected() {
    qDebug() << "Client: Client disconnected";
}


void Client::connectToServer(const QString &serverIp, int port) {
    tcpSocket->connectToHost(serverIp, port);
    emit(m_connecting());
    tcpSocket->waitForConnected(2000);
    qDebug() << tcpSocket->state();
    if(tcpSocket->state() == QTcpSocket::ConnectedState)
        emit(m_connected());
    else if(tcpSocket->state() == QTcpSocket::UnconnectedState || tcpSocket->state() == QTcpSocket::ConnectingState)
        emit(m_unconnected());
}

void Client::sendMessage(const QString &msg) {
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_5);

    out << msg;

    tcpSocket->write(block);
}

void Client::sendFolderRequest(const QString &path) {
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_5);

    out << QString("ls") << path;

    tcpSocket->write(block);
}

void Client::sendAppTask(const QString &cmd, const QString &obj) {
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_5);

    out << cmd << obj;

    tcpSocket->write(block);
}

void populateModelRecursively(QStandardItem *parentItem, const QString &basePath, int levels, const QStringList &directoryList)
{
    if (levels <= 0) {
        return;
    }

    for (const QString &absolutePath : directoryList) {
        qDebug() << absolutePath << "trong de quy ne";
        QFileInfo info(absolutePath);
        QString name = info.fileName();
        if (name == ".") continue;
        if (name == "..") continue;
        QStandardItem *item = new QStandardItem(name);
        item->setData(absolutePath, Qt::UserRole);
        parentItem->appendRow(item);

//        QDir nestedDir(absolutePath);
//        QStringList nestedDirectories = nestedDir.entryList(QDir::Dirs | QDir::NoDotAndDotDot);


        QDir dir(absolutePath);
        QStringList entries = dir.entryList();

        QStringList directories;

        for (const QString& entry : entries) {
            QString fullPath = dir.absoluteFilePath(entry);
            if (QFileInfo(fullPath).isDir()) {
                directories.append(fullPath);
            }
        }

        populateModelRecursively(item, absolutePath, levels - 1, directories);

    }
}

void Client::readMessage() {
    in.startTransaction();

//    QString message = "";
    QByteArray byteArray;
    QStringList strList[4];
    QStringList fileStructList, directoryList;
    QString code;
    int num;
    in >> code;
    qDebug() << code << "CODE NE\n";
    if (code == tr("string") || code == tr("image") || code ==tr("audio")) {
        in >> byteArray;
    }
//    else if (code == tr("image")) {
//        in >>;
//    }
    else if (code == tr("file")) {
        in >> fileStructList >> directoryList;
    }
    else if (code == tr("list processes")||
            code == tr("list applications") ||
            code == tr("list running applications")
             ) {
        in >> num;
        in >> strList[num];
        qDebug() << "Hello hoho\n";
    }

//    in >> byteArray;
//    while (!in.atEnd()) {
//        QString tmp;
//        in >> tmp;
//        message += tmp;
//    }
//    >> message;


    if (!in.commitTransaction())
        return;
    qDebug() << "A full message just got to server!";
    qDebug() << "type: " << code << "\n";
    if (code == tr("string")) {
        qDebug() << "just sending text" << QString(byteArray);
//        emit (stringMessageReceived(QString(byteArray)));
    }
    else if (code == tr("image")) {
        qDebug("image incoming");
        QPixmap pixmap;
        // fill array with image
        if(pixmap.loadFromData(byteArray,"PNG"))
        {
            // do something with pixmap
            emit (imageMessageReceived(pixmap));
        }
    }
    else if (code == tr("file")) {
        qDebug() << "file struct incoming";
//        QString response = QString(byteArray);
//        qDebug() << response;
//        QStringList lines = response.split("\n");
//        fileStructList, directoryList
        QStandardItemModel *model = new QStandardItemModel;
        QStandardItem *rootItem = model->invisibleRootItem();
//        for (QString fullPath : directoryList) {
//            QFileInfo fileInfo(fullPath);
//            QString name = fileInfo.fileName();
//            qDebug() << name;
//            QStandardItem *item = new QStandardItem(name);
//            rootItem->appendRow(item);
//        }
        int levels = 3;

        populateModelRecursively(rootItem, "", levels, directoryList);


//        treeView->setModel(&model);
        emit (directoryStructReceived(model));
        emit (fileStructReceived(fileStructList));
    }
    else if (code == tr("audio")){
        qDebug() << "Audio incoming";

        QMediaPlayer *player = new QMediaPlayer();

        QBuffer *buffer = new QBuffer(player);
        buffer->setData(byteArray);
        buffer->open(QIODevice::ReadOnly);
        buffer->seek(qint64(0));

        QAudioDevice dev;
        for (auto device : QMediaDevices::audioOutputs()){
            qDebug() << device.description();
            dev = device;
        }
        if (dev.isNull()){
            qDebug() << "No audio output device";
            return;
        }
        QAudioOutput out;
        out.setDevice(dev);
        out.setVolume(100);
        player->setAudioOutput(&out);
        player->setSourceDevice(buffer);


        QElapsedTimer timer;
        timer.start();
        player->play();
        while(!timer.hasExpired(player->duration())){
            //            qDebug() << player->playbackState() << " " << player->duration() << " " << timer.elapsed();
        }
        player->stop();
        qDebug() << "Audio stopped";
        emit(audio_played());
    }
    else if (code == tr("list processes")) {
        QStringList lines = strList[1];
        QStandardItemModel *model = new QStandardItemModel;
        QStandardItem *rootItem = model->invisibleRootItem();
        for (int i = 0; i + 1 < lines.size(); i+=2) {
            QString process_name = lines[i];
            QString process_pid = lines[i+1];

            QList<QStandardItem*> rowItems;
            QStandardItem* nameItem = new QStandardItem(process_name);
            QStandardItem* pidItem = new QStandardItem(process_pid);
            rowItems << nameItem << pidItem;

            rootItem->appendRow(rowItems);
//            qDebug() << process_name << process_pid;
        }
        emit (processesReceived(model));
    }
    else if (code == tr("list applications")) {
        QStringList applications = strList[2];
        QStandardItemModel *model = new QStandardItemModel;
        QStandardItem *rootItem = model->invisibleRootItem();

        QFileIconProvider iconProvider;

        for (int i = 0; i + 1 < applications.size(); i+=2) {
            QString appName = applications[i];
            QString appPath = applications[i+1];
            QFileInfo fileInfo(appPath);
            QIcon appIcon = iconProvider.icon(fileInfo);
            //            QString appName = fileInfo.baseName();

//            qDebug() << appName << ' ' << appPath;
            QStandardItem *item = new QStandardItem(appName);
            item->setData(appPath, Qt::UserRole); // store appPath in the item's user role
            rootItem->appendRow(item);
        }
        //        treeView->setModel(&model);
        emit (allAppsReceived(model));
    }
    else if (code == tr("list running applications")) {
        qDebug() << "client: list running applications";
        QStringList applications = strList[3];
        QStandardItemModel *model = new QStandardItemModel;
        QStandardItem *rootItem = model->invisibleRootItem();

        QFileIconProvider iconProvider;

        for (int i = 0; i + 1 < applications.size(); i+=2) {
            QString appName = applications[i];
            QString appPath = applications[i+1];
            QFileInfo fileInfo(appPath);
            QIcon appIcon = iconProvider.icon(fileInfo);
//            QString appName = fileInfo.baseName();

//            qDebug() << appName;
            QStandardItem *item = new QStandardItem(appName);
            item->setData(appPath, Qt::UserRole); // store appPath in the item's user role
            rootItem->appendRow(item);
        }
        //        treeView->setModel(&model);
        qDebug() << "Emitting receive signals" << applications.size();
        emit (runningAppsReceived(model));
    }

}
