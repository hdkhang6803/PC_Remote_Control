#include "serverWindow.h"
#include "ui_serverWindow.h"

ServerWindow::ServerWindow(QWidget *parent) :
    QMainWindow(parent)
//    , ui(new Ui::ServerWindow)
{
//    ui->setupUi(this);

    server = new Server;

    connect(server, &Server::readyRead, this, &ServerWindow::updateServerMsg);

    // ------------SETTING UP GUI ----------------------
    overallLayout = new QVBoxLayout;
    serverInfoWidget = new QWidget;
    buttonsWidget = new QWidget;

    // serverInfoWidget
    serverInfoLayout = new QFormLayout;
    ipLabel = new QLabel("IP:");
    portLabel = new QLabel("Port:");
    ipBox = new QLineEdit;
    portBox = new QLineEdit;
    statusLabel = new QLabel("Status: ");
    statusBox = new QLineEdit;
    serverInfoLayout->addRow(ipLabel, ipBox);
    serverInfoLayout->addRow(portLabel, portBox);
    serverInfoLayout->addRow(statusLabel, statusBox);
    serverInfoWidget->setLayout(serverInfoLayout);
    overallLayout->addWidget(serverInfoWidget);

    // buttonsWidget
    buttonsLayout = new QHBoxLayout;
    restartButton = new QPushButton("Restart");
    exitButton = new QPushButton("Exit");
    buttonsLayout->addWidget(restartButton);
    buttonsLayout->addWidget(exitButton);
    buttonsWidget->setLayout(buttonsLayout);
    overallLayout->addWidget(buttonsWidget);

    // set central widget
    centralWidget = new QWidget;
    centralWidget->setLayout(overallLayout);
    setCentralWidget(centralWidget);

    connect(exitButton, SIGNAL(clicked()), this, SLOT(close()));

    statusBox->setText(tr("The server is running now."));

    ipBox->setText(server->ipAddress);
    portBox->setText(server->port);
}

void ServerWindow::updateServerMsg(const QString &msg) {
    statusBox->setText(msg);
}
