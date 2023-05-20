
#include "client.h"
#include "clientWindow.h"

#include <QDebug>

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
    tcpSocket->waitForConnected(2000);
    qDebug() << tcpSocket->state();
    if(tcpSocket->state() == QTcpSocket::ConnectedState)
        emit(m_connected());
    else if(tcpSocket->state() == QTcpSocket::UnconnectedState || tcpSocket->state() == QTcpSocket::ConnectingState)
        emit(m_unconnected());
}

void Client::sendMessage(const QString &cmdNumber) {
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_5);

    out << cmdNumber;

    tcpSocket->write(block);
}

void Client::readMessage() {

    in.startTransaction();

//    QString message = "";
    QByteArray byteArray;
    QStringList strList;
    QString code;
    in >> code;
    if (code == tr("string") || code == tr("image")) {
        in >> byteArray;
    }
//    else if (code == tr("image")) {
//        in >>;
//    }
    else if (code == tr("file") || code == tr("list processes")
             || code == tr("list applications")
             ) {
        in >> strList;
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
        qDebug("just sending text");
        emit (stringMessageReceived(QString(byteArray)));
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
        QStringList lines = strList;
        QStandardItemModel *model = new QStandardItemModel;
        QStandardItem *rootItem = model->invisibleRootItem();
        for (QString line : lines) {
            qDebug() << line;
            QStandardItem *item = new QStandardItem(line);
            rootItem->appendRow(item);
        }
//        treeView->setModel(&model);
        emit (fileStructReceived(model));
    }
    else if (code == tr("list processes")) {
        QStringList lines = strList;
        QStandardItemModel *model = new QStandardItemModel;
        QStandardItem *rootItem = model->invisibleRootItem();
        foreach (QString line, lines) {
            QList<QString>info  = line.split(' ', Qt::SkipEmptyParts);
            if (info.size() > 1) {
                qDebug() << info[0] << info[1];
                QStandardItem *item = new QStandardItem(info[0]);
                rootItem->appendRow(item);
    //        qDebug() << line;
            }
        }
        emit (fileStructReceived(model));
    }
    else if (code == tr("list applications")) {
        QStringList applications = strList;
        QStandardItemModel *model = new QStandardItemModel;
        QStandardItem *rootItem = model->invisibleRootItem();
//        for (QString appPath : applications) {
//            qDebug() << appPath;
////            QStandardItem *item = new QStandardItem(appPath);
////            rootItem->appendRow(item);

//            // chat gpt
//            QFileInfo fileInfo(appPath);
//            QString appName = fileInfo.baseName(); // Get app name from appPath
//            QStandardItem *item = new QStandardItem(appName);

//            // Add app icon and name from appPath
//            if (fileInfo.isFile() && (fileInfo.suffix() == "exe" || fileInfo.suffix() == "lnk")) {
//                QSettings settings(appPath, QSettings::NativeFormat);
//                QString iconPath = settings.value("icon").toString();
//                if (!iconPath.isEmpty()) {
//                    int index = iconPath.indexOf(",");
//                    if (index != -1) {
//                        iconPath = iconPath.left(index);
//                    }
//                    QIcon icon(iconPath);
//                    item->setIcon(icon);
//                }
//            }
//            item->setData(appPath, Qt::UserRole);

//            rootItem->appendRow(item);


//        }
        QFileIconProvider iconProvider;

        for (QString appPath : applications) {
            QFileInfo fileInfo(appPath);
            QIcon appIcon = iconProvider.icon(fileInfo);
            QString appName = fileInfo.baseName();

            qDebug() << appName;
            QStandardItem *item = new QStandardItem(appIcon, appName);
            item->setData(appPath, Qt::UserRole); // store appPath in the item's user role
            rootItem->appendRow(item);
        }
        //        treeView->setModel(&model);
        emit (fileStructReceived(model));
    }
}
