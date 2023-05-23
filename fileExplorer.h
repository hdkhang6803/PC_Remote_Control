#ifndef FILEEXPLORER_H
#define FILEEXPLORER_H

#include <QWidget>
#include <QtNetwork>
#include <QDebug>
#include <QDir>
#include "include\ui_fileExplorer.h"

namespace Ui {
class fileExplorer;
}

class fileExplorer : public QWidget
{
    Q_OBJECT

public:
    explicit fileExplorer(QTcpServer *parServer, QWidget *parent = nullptr);
    ~fileExplorer();

private:
    Ui::fileExplorer *ui;

public slots:
    void handleReadyRead();
private slots:
    void handleNewConnection();

    void handleClientDisconnected();
private:
    void sendMessage(QTcpSocket* sender, const QStringList &msg);

private:
    QTcpServer *server;
    QList<QTcpSocket*> clients;
};

#endif // FILEEXPLORER_H
