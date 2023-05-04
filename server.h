
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

#include "audiorecorder.h"

class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = nullptr);

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
    void processData();
private:
    void initServer();
    void stream(QTcpSocket* clientConnection);
    void sendMessage(QTcpSocket* sender, const QString &cmdNumber);
    void sendScreenshot(QTcpSocket* sender, const QPixmap &screenshot);
    void sendFileStructure(QTcpSocket* sender, const QFileSystemModel &model);
public:
    QString ipAddress;
    QString port;
private:
    QTcpServer *tcpServer = nullptr;
    QDataStream in;

    QProcess *m_process;
    AudioRecorder *recorder = nullptr;
    QList<QTcpSocket*> clients;

//    HHOOK mouseHook;

//static    LRESULT CALLBACK MouseHookProc(int nCode, WPARAM wParam, LPARAM lParam);
//    void startHook();
//    void stopHook();
};

#endif // SERVER_H
