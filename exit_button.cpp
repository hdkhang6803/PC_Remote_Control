#include "exit_button.h"
#include "ui_exit_button.h"


exit_button::exit_button(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::exit_button)
{
    ui->setupUi(this);
    sock = new QTcpSocket;
}

exit_button::~exit_button()
{
    delete ui;
}
void exit_button::connectServer(const QString &serverIp, int port){
    qDebug() << serverIp;
    sock->connectToHost(serverIp, port);
    qDebug() << "button connected";
}
void exit_button::on_pushButton_clicked()
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_5);

    out << "stop_recording";

    sock->write(block);
    qDebug() << "stop button pressed";
}

