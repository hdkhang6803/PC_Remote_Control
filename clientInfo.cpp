#include <QtWidgets>
#include <QtNetwork>
#include <QDebug>

#include "clientInfo.h"
#include "clientWindow.h"


clientInfo::clientInfo(QWidget *parent) :
    QMainWindow(parent)
    , ui(new Ui::clientInfo)
{
    ui->setupUi(this);
//    populateIpAddresses();

//    ui->serverPortBox->setValidator(new QIntValidator(1, 65535, this));

    // ------------SETTING UP GUI ----------------------

    ipLabel = ui->IDlabel;
    ipBox = ui->IDinput;
    portLabel = ui->portLabel;
    portBox = ui->portInput;
    ui->failLabel->setVisible(false);
    connectButton = ui->pushButton;
    exitButton = ui->pushButton_2;

    // -----------------------------------------------


    connect(connectButton, &QPushButton::clicked, this, &clientInfo::on_buttonBox_accepted);
    connect(exitButton, &QPushButton::clicked, this, &clientInfo::on_buttonBox_rejected);
}


void clientInfo::on_buttonBox_accepted()
{
    ui->failLabel->setText("Connecting...");
    ui->failLabel->show();
    emit (connectToServer(ipBox->text(), portBox->text().toInt()));

}
void clientInfo::fail_mess_display(){
    ui->failLabel->setText("Connect unsuccessfully! Try again.");
    ui->failLabel->setVisible(true);
}
void clientInfo::on_buttonBox_rejected()
{
    emit (exit());
    close();
}

