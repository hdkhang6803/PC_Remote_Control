#include <QtWidgets>
#include <QtNetwork>

#include "connectDialog.h"
#include "ui_connectDialog.h"

ConnectDialog::ConnectDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConnectDialog)
{
    ui->setupUi(this);
    populateIpAddresses();

    ui->serverPortBox->setValidator(new QIntValidator(1, 65535, this));

//    connect(tcpSocket, &QIODevice::readyRead, this, &ConnectDialog::readFortune);
}

ConnectDialog::~ConnectDialog()
{
    delete ui;
}

void ConnectDialog::populateIpAddresses() {
    QComboBox *comboBox = ui->serverIpBox;

    // find out IP addresses of this machine
    const QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
    // add non-localhost addresses
    for (const QHostAddress &entry : ipAddressesList) {
        if (!entry.isLoopback())
            comboBox->addItem(entry.toString());
    }
    // add localhost addresses
    for (const QHostAddress &entry : ipAddressesList) {
        if (entry.isLoopback())
            comboBox->addItem(entry.toString());
    }
}


void ConnectDialog::on_buttonBox_accepted()
{
    emit (connectToServer(ui->serverIpBox->currentText(), ui->serverPortBox->text().toInt()));
}

