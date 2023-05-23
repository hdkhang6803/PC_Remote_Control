#include "serverWindow.h"


serverInfo::serverInfo(QWidget *parent) :
    QMainWindow(parent)
    , ui(new Ui::serverInfo)
{
    ui->setupUi(this);

    server = new Server;
//    myFileExplorer = new fileExplorer(server->getServer());

    connect(server, &Server::readyRead, this, &serverInfo::updateServerMsg);
    connect(server, &Server::display, this, &serverInfo::updatePic);

//    // ------------SETTING UP GUI ----------------------
    exitButton = ui->pushButton;
//    overallLayout = new QVBoxLayout;
//    serverInfoWidget = new QWidget;
//    buttonsWidget = new QWidget;

//    // serverInfoWidget
//    serverInfoLayout = new QFormLayout;
    _ipLabel = ui->IDlabel;
    _portLabel = ui->portLabel;
    _ipBox = ui->IDinput;
    _portBox = ui->portInput;
    statusLabel = ui->portLabel_2;
    statusBox = ui->portInput_2;
//    serverInfoLayout->addRow(ipLabel, ipBox);
//    serverInfoLayout->addRow(portLabel, portBox);
//    serverInfoLayout->addRow(statusLabel, statusBox);
//    serverInfoWidget->setLayout(serverInfoLayout);
//    overallLayout->addWidget(serverInfoWidget);

//    // buttonsWidget
//    buttonsLayout = new QHBoxLayout;
//    restartButton = new QPushButton("Restart");
//    exitButton = new QPushButton("Exit");
//    buttonsLayout->addWidget(restartButton);
//    buttonsLayout->addWidget(exitButton);
//    buttonsWidget->setLayout(buttonsLayout);
//    overallLayout->addWidget(buttonsWidget);

//    // set central widget
//    centralWidget = new QWidget;
//    centralWidget->setLayout(overallLayout);
//    setCentralWidget(centralWidget);

    connect(exitButton, SIGNAL(clicked()), this, SLOT(close()));

    statusBox->setText(tr("The server is running now."));

    _ipBox->setText(server->ipAddress);
    _portBox->setText(server->port);
}

void serverInfo::updateServerMsg(const QString &msg) {
    statusBox->setText(msg);
}

void serverInfo::updatePic(const QPixmap &screenshot) {
    qDebug() << "display picture?";
    QLabel *screenshotLabel = new QLabel();
    screenshotLabel->setPixmap(screenshot);
//    buttonsLayout->addWidget(screenshotLabel);
}
