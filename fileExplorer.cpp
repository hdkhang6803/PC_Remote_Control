#include "fileExplorer.h"
//#include "D:\UltimateDownload\_Yr2Sem2\mmt\socket project\include\include\ui_fileExplorer.h"

fileExplorer::fileExplorer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::fileExplorer)
{
    ui->setupUi(this);

//    connect(ui->exitButton, )

//    server = parServer;
////    server->listen(QHostAddress::Any, 8888);
//    qDebug() << server->serverAddress() << " " << server->serverPort();
//    clients = QList<QTcpSocket*>();
//    connect(server, &QTcpServer::newConnection, this, &fileExplorer::handleNewConnection);
}

fileExplorer::~fileExplorer()
{
    delete ui;
}
