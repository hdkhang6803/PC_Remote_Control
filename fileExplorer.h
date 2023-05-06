#ifndef FILEEXPLORER_H
#define FILEEXPLORER_H

#include <QWidget>
#include <QtNetwork>
#include <QDebug>
#include <QDir>

namespace Ui {
class fileExplorer;
}

class fileExplorer : public QWidget
{
    Q_OBJECT

public:
    explicit fileExplorer(QWidget *parent = nullptr);
    ~fileExplorer();

private:
    Ui::fileExplorer *ui;

private slots:
    void handleNewConnection();
    void handleReadyRead();
    void handleClientDisconnected();
private:
    void sendMessage(QTcpSocket* sender, const QStringList &msg);

private:
    QTcpServer *server;
    QList<QTcpSocket*> clients;
};

#endif // FILEEXPLORER_H
