#include "clientWindow.h"
#include "ui_clientWindow.h"

#include <QDebug>

ClientWindow::ClientWindow(QWidget *parent) :
    QMainWindow(parent)
//    , ui(new Ui::ClientWindow)
{
//    ui->setupUi(this);

    client = new Client;
    connectDialog = new ConnectDialog;

    connect(connectDialog, &ConnectDialog::connectToServer, this, &ClientWindow::receivedServerInfo);
    connect(connectDialog, &ConnectDialog::exit, this, &ClientWindow::close);
    connect(client, &Client::stringMessageReceived, this, &ClientWindow::updateServerMsg);
    connect(client, &Client::imageMessageReceived, this, &ClientWindow::updateImage);
//    connect(client, &Client::fileStructReceived, this, &ClientWindow::updateFileStruct);


    // ------------SETTING UP GUI --------------------
//    const QSize windowSize = QSize(900, 600);
//    const QSize rightPanelSize = QSize (600, 600);

//    this->resize(windowSize);
    overallLayout = new QHBoxLayout;
    leftPanelWidget = new QWidget;
    rightPanelWidget = new QWidget;
//    rightPanelWidget->setFixedSize(rightPanelSize);

    // leftPanelWidget
    leftPanelLayout = new QVBoxLayout;

    const QSize serverInfoBoxSize = QSize (100, 200);
    serverInfoBox = new QGroupBox("Server info");
    serverInfoLayout = new QFormLayout;
    ipLabel = new QLabel("IP:");
    portLabel = new QLabel("Port:");
    ipBox = new QLabel;
    portBox = new QLabel;
    serverInfoLayout->addRow(ipLabel, ipBox);
    serverInfoLayout->addRow(portLabel, portBox);
    serverInfoBox->setLayout(serverInfoLayout);
    serverInfoBox->setFixedSize(serverInfoBoxSize);

    const QSize featureButtonSize = QSize(90, 60);
    featureWidget = new QWidget;
    featureLayout = new QVBoxLayout;
    featureButtons = new vector<FeatureButton*>;

    for (int i = 0; i < 4; i++) {
//        FeatureButton *button = new FeatureButton(featureNames[i]);
        FeatureButton *button = new FeatureButton;
        button->setText(featureNames[i]);
        button->setNumber(i);
//        button->setFixedSize(featureButtonSize);
        //connect(button, SIGNAL(clicked()), this, featureFuncs[i]);
        connect(button, &FeatureButton::clickedNumber, this, &ClientWindow::on_pushButton_clicked);

        featureButtons->push_back(button);
        featureLayout->addWidget(button);
    }
//    featureLayout->addItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::MinimumExpanding));

    featureWidget->setLayout(featureLayout);

    const QSize exitButtonSize = QSize(90, 60);
    exitButton = new QPushButton("Exit");
//    exitButton->setFixedSize(exitButtonSize);
    connect(exitButton, SIGNAL(clicked()), this, SLOT(close()));

    leftPanelLayout->addWidget(serverInfoBox);
    leftPanelLayout->addWidget(featureWidget);
    leftPanelLayout->addWidget(exitButton);

    // rightPanelWidget
    rightPanelLayout = new QVBoxLayout;
    serverMsgBox = new QLineEdit;
    rightPanelLayout->addWidget(serverMsgBox);

    // central
    leftPanelWidget->setLayout(leftPanelLayout);
    rightPanelWidget->setLayout(rightPanelLayout);
    overallLayout->addWidget(leftPanelWidget);
    overallLayout->addWidget(rightPanelWidget);

    centralWidget = new QWidget;
    centralWidget->setLayout(overallLayout);
    setCentralWidget(centralWidget);
    // -----------------------------------------------
    connectDialog->show();


}

void ClientWindow::receivedServerInfo(const QString &serverIp, int port) {
    client->connectToServer(serverIp, port);
    ipBox->setText(serverIp);
    portBox->setText(QString::number(port));
}

void ClientWindow::updateServerMsg(const QString &msg) {
    serverMsgBox->setText(msg);
}

void ClientWindow::updateImage(const QPixmap &image) {
    qDebug() << "display picture?";
    if (screenshotLabel == nullptr) {
        screenshotLabel = new QLabel();
        screenshotLabel->setPixmap(image);
        rightPanelLayout->addWidget(screenshotLabel);
    }
    else {
        screenshotLabel->setPixmap(image);
    }
}

void ClientWindow::updateFileStruct(QFileSystemModel &model) {
    qDebug() << "display file struct";
    QTreeView *treeView = new QTreeView;
//    treeView->setModel(model);
    rightPanelLayout->addWidget(treeView);
}

void ClientWindow::on_pushButton_clicked(int num)
{
    qDebug() << "message sent";
    switch (num) {
    case 0:
        client->sendMessage(tr("keyboard track"));
        break;
    case 1:
        client->sendMessage(tr("list processes"));
        break;
    case 2:
        client->sendMessage(tr("take screenshot"));
        break;
    case 3:
        client->sendMessage(tr("recording"));
        break;
    default:
        client->sendMessage(tr("just saying hello"));
    }


}
