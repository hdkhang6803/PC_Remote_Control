
#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QPixmap>
#include <QStandardItemModel>
#include <QFileInfo>
#include <QSettings>
#include <QFileIconProvider>

class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject *parent = nullptr);

signals:

    void m_connected();
    void m_unconnected();
    void m_connecting();

    void stringMessageReceived(const QString &message);
    void imageMessageReceived(const QPixmap &image);
    void fileStructReceived(QStringList &files);
    void directoryStructReceived(QStandardItemModel* &model);
    void allAppsReceived(QStandardItemModel* &model);
    void processesReceived(QStandardItemModel* &model);
    void runningAppsReceived(QStandardItemModel* &model);
    void error(QAbstractSocket::SocketError socketError);
//    void readySend();

    void audio_played();
public slots:
    void connectToServer(const QString &serverIp, int port);
    void sendMessage(const QString &cmdNumber);
    void sendFolderRequest(const QString &path);
    void sendAppTask(const QString &cmd, const QString &obj);
    void readMessage();
    void m_disconnected();

private:
    QTcpSocket *tcpSocket = nullptr;
    QDataStream in;
    QByteArray buffer;

//    bool sending = 0;
};

#endif // CLIENT_H
