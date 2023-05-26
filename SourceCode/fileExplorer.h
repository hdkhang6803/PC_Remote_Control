#ifndef FILEEXPLORER_H
#define FILEEXPLORER_H

#include <QWidget>
#include <QtNetwork>
#include <QDebug>
#include <QDir>
#include "include\ui_fileExplorer.h"
#include "FileNavButton.h"
#include <vector>
#include <QStandardItemModel>
using std::vector;

namespace Ui {
class fileExplorer;
}

class fileExplorer : public QWidget
{
    Q_OBJECT

public:
//    explicit fileExplorer(QTcpServer *parServer, QWidget *parent = nullptr);
    explicit fileExplorer(QWidget *parent = nullptr);
    ~fileExplorer();

    vector<QLabel*> fileNameLabels;
    vector<FileNavButton*> fileNavList;
    vector<QVBoxLayout*> vboxList;


signals:
    void sendFolderRequest(const QString &path);

public slots:
    void updateFolderStruct(QStandardItemModel* &model);
    void updateFilesWindow(QStringList files);
    void onItemClicked(const QModelIndex& index);

public:
    Ui::fileExplorer *ui;
    QString getName(const QString& path);

//public slots:
//    void handleReadyRead();
//private slots:
//    void handleNewConnection();

//    void handleClientDisconnected();
//private:
//    void sendMessage(QTcpSocket* sender, const QStringList &msg);

//private:
//    QTcpServer *server;
//    QList<QTcpSocket*> clients;
};

#endif // FILEEXPLORER_H
