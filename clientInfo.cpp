#include <QtWidgets>
#include <QtNetwork>
#include <QDebug>

#include "clientInfo.h"
#include "clientWindow.h"
#include "D:\University\Year_2\HK2\MMT\Project_3\include\ui_clientInfo.h"

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
////    statusLabel = new QLabel("Status: ");
////    statusBox = new QLineEdit;
//    serverInfoLayout->addRow(ipLabel, ipBox);
//    serverInfoLayout->addRow(portLabel, portBox);
////    serverInfoLayout->addRow(statusLabel, statusBox);
//    serverInfoWidget->setLayout(serverInfoLayout);
//    overallLayout->addWidget(serverInfoWidget);

//    // buttonsWidget
//    buttonsLayout = new QHBoxLayout;
//    dialogButtonBox = new QDialogButtonBox;
    connectButton = ui->pushButton;
//    dialogButtonBox->addButton(okButton, QDialogButtonBox::AcceptRole);
    exitButton = ui->pushButton_2;
//    dialogButtonBox->addButton(cancelButton, QDialogButtonBox::RejectRole);
//    buttonsLayout->addWidget(dialogButtonBox);
//    buttonsWidget->setLayout(buttonsLayout);
//    overallLayout->addWidget(buttonsWidget);

//    // set central widget
//    this->setLayout(overallLayout);
    // -----------------------------------------------


    connect(connectButton, &QPushButton::clicked, this, &clientInfo::on_buttonBox_accepted);
    connect(exitButton, &QPushButton::clicked, this, &clientInfo::on_buttonBox_rejected);
}


void clientInfo::on_buttonBox_accepted()
{
    emit (connectToServer(ipBox->text(), portBox->text().toInt()));
    close(); //Can phai close clientinfo truoc khi tao client window

}

void clientInfo::on_buttonBox_rejected()
{
    emit (exit());
    close();
}

