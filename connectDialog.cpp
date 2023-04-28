#include <QtWidgets>
#include <QtNetwork>
#include <QDebug>

#include "connectDialog.h"
#include "ui_connectDialog.h"

ConnectDialog::ConnectDialog(QWidget *parent) :
    QDialog(parent)
//    , ui(new Ui::ConnectDialog)
{
//    ui->setupUi(this);
//    populateIpAddresses();

//    ui->serverPortBox->setValidator(new QIntValidator(1, 65535, this));

    // ------------SETTING UP GUI ----------------------
    this->setModal(true);
    overallLayout = new QVBoxLayout;
    serverInfoWidget = new QWidget;
    buttonsWidget = new QWidget;

    // serverInfoWidget
    serverInfoLayout = new QFormLayout;
    ipLabel = new QLabel("IP:");
    portLabel = new QLabel("Port:");
    ipBox = new QLineEdit;
    portBox = new QLineEdit;
//    statusLabel = new QLabel("Status: ");
//    statusBox = new QLineEdit;
    serverInfoLayout->addRow(ipLabel, ipBox);
    serverInfoLayout->addRow(portLabel, portBox);
//    serverInfoLayout->addRow(statusLabel, statusBox);
    serverInfoWidget->setLayout(serverInfoLayout);
    overallLayout->addWidget(serverInfoWidget);

    // buttonsWidget
    buttonsLayout = new QHBoxLayout;
    dialogButtonBox = new QDialogButtonBox;
    okButton = new QPushButton("OK");
    dialogButtonBox->addButton(okButton, QDialogButtonBox::AcceptRole);
    cancelButton = new QPushButton("Cancel");
    dialogButtonBox->addButton(cancelButton, QDialogButtonBox::RejectRole);
    buttonsLayout->addWidget(dialogButtonBox);
    buttonsWidget->setLayout(buttonsLayout);
    overallLayout->addWidget(buttonsWidget);

    // set central widget
    this->setLayout(overallLayout);
    // -----------------------------------------------


    connect(dialogButtonBox, SIGNAL(accepted()), this, SLOT(on_buttonBox_accepted()));
    connect(dialogButtonBox, SIGNAL(rejected()), this, SLOT(on_buttonBox_rejected()));
}


void ConnectDialog::on_buttonBox_accepted()
{
    emit (connectToServer(ipBox->text(), portBox->text().toInt()));
    close();
}

void ConnectDialog::on_buttonBox_rejected()
{
    emit (exit());
    close();
}

