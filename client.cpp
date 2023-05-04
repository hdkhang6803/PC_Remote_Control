
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

void Client::connected() {
    qDebug() << "Client: Client connected";
}

void Client::disconnected() {
    qDebug() << "Client: Client disconnected";
}

void Client::connectToServer(const QString &serverIp, int port) {
    tcpSocket->connectToHost(serverIp, port);
    qDebug() << "Connected server.";
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
    QString code;
    in >> code;
    in >> byteArray;
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
//    else if (code == tr("file model")) {
//        qDebug("file structure incoming");
////        QFileSystemModel model;
////        QDataStream dataStream(&byteArray, QIODevice::ReadOnly);
////        dataStream >> model;

//        // Deserialize the QVariantList from the QByteArray
//        QVariantList modelData;
//        QDataStream dataStream(&byteArray, QIODevice::ReadOnly);
//        dataStream >> modelData;

//        QFileSystemModel model;
//        QString rootPath = modelData.takeFirst().toString(); // Get the root path from the first item
//        model.setRootPath(rootPath);
//        for (const QVariant &rowData : modelData) {
//            QVariantMap map = rowData.toMap();
//            QString fileName = map["fileName"].toString();
//            QString filePath = map["filePath"].toString();
//            qint64 fileSize = map["fileSize"].toLongLong();
//            QFileSystemModel::FileInfo::Type fileType = static_cast<QFileSystemModel::Type>(map["fileType"].toInt());
//            QDateTime fileDateTime = map["fileDateTime"].toDateTime();
//            QModelIndex parentIndex = model.index(map["parentRow"].toInt(), 0);
//            model.insertRow(model.rowCount(parentIndex), parentIndex);
//            QModelIndex index = model.index(model.rowCount(parentIndex) - 1, 0, parentIndex);
//            model.setData(index, fileName, Qt::DisplayRole);
//            model.setData(index, filePath, Qt::UserRole);
//            model.setData(index, fileSize, Qt::SizeHintRole);
//            model.setData(index, fileType, QFileSystemModel::FileTypeRole);
//            model.setData(index, fileDateTime, Qt::UserRole + 1);
//        }

//        emit (fileStructReceived(model));
//    }
}

//void Client::readMessage() {
//    qDebug() << "Received a response from the server!";

//    QByteArray data = tcpSocket->readAll();  // read all available data
//    buffer += data;  // add the new data to the buffer

//    while (true) {
//        int index = buffer.indexOf('\n');  // find the newline delimiter
//        if (index == -1) {
//            break;  // the delimiter was not found, so we can't extract a complete message yet
//        }

//        QByteArray messageData = buffer.left(index);  // extract the message data
//        buffer = buffer.mid(index + 1);  // remove the message data and the delimiter from the buffer

//        QString message = QString::fromUtf8(messageData);// convert the message data to a QString
//        qDebug() << message << "\n";

//        QStringList parts = message.split(' ');  // split the message into parts using the space character as a separator

//        if (parts.size() >= 2) {
//            QString messageType = parts[0];
//            QByteArray messagePayload = messageData.mid(messageType.length() + 1);  // extract the message payload after the separator character

//            if (messageType == "string") {
//                QString stringMessage = QString::fromUtf8(messagePayload);
//                emit stringMessageReceived(stringMessage);
//            }
//            else if (messageType == "image") {
//                QPixmap pixmap;
//                pixmap.loadFromData(messagePayload);
//                emit imageMessageReceived(pixmap);
//            }
//            // add more message type checks here for other types of messages
//        }
//    }
//}

//void Client::readMessage() {
//    qDebug() << "Received a response from the server!";

//    QByteArray data = tcpSocket->readAll();  // read all available data
//    buffer.append(data);  // add the new data to the buffer

//    // Keep processing messages until the buffer is empty
//    while (buffer.size() > 0) {
//        QDataStream in(buffer);
//        in.setVersion(QDataStream::Qt_6_5);

//        QString header;
//        in >> header;

//        // Check if we have enough data for the entire message
//        int dataSize = buffer.size() - sizeof(header);
//        if (dataSize < 0) {
//            // Wait for more data to arrive
//            break;
//        }

//        if (header == "string") {
//            QString msg;
//            in >> msg;
//            emit stringMessageReceived(msg);
//        } else if (header == "image") {
//            QByteArray imageData;
//            in >> imageData;
//            QPixmap pixmap;
//            pixmap.loadFromData(imageData, "PNG");
//            emit imageMessageReceived(pixmap);
//        } else {
//            qWarning() << "Unknown message format";
//        }

//        // Remove the processed message from the buffer
//        buffer = buffer.right(buffer.size() - sizeof(header) - dataSize);
//    }
//}
