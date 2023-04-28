
#include "mainWindow.h"
#include "./ui_mainWindow.h"

#include "serverWindow.h"
#include "clientWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
//    , ui(new Ui::MainWindow)
{
//    ui->setupUi(this);
    // ------------SETTING UP GUI ----------------------
    const QSize btnSize = QSize(150, 100);
    const QSize logoSize = QSize(300, 300);
    buttonLayout = new QHBoxLayout;
    createServerButton = new QPushButton("Create a server");
    connectServerButton = new QPushButton("Connect to a server");
    createServerButton->setFixedSize(btnSize);
    connectServerButton->setFixedSize(btnSize);
    buttonLayout->addWidget(createServerButton);
    buttonLayout->addWidget(connectServerButton);
    buttonWidget = new QWidget;
    buttonWidget->setLayout(buttonLayout);

    overallLayout = new QVBoxLayout;
    logoWidget = new QWidget;
    logoWidget->setFixedSize(logoSize);
    overallLayout->addWidget(logoWidget);
    overallLayout->addWidget(buttonWidget);

    centralWidget = new QWidget;
    centralWidget->setLayout(overallLayout);
    setCentralWidget(centralWidget);

    connect(createServerButton, SIGNAL(clicked()), this, SLOT(on_CreateServerButton_clicked()));
    connect(connectServerButton, SIGNAL(clicked()), this, SLOT(on_ConnectServerButton_clicked()));
    // -----------------------------------------------
}

void MainWindow::on_CreateServerButton_clicked()
{
//    serverWindow->show();
    ServerWindow *serverWindow = new ServerWindow(this);
    serverWindow->show();
//    QWidget *serverWidget = serverWindow->findChild<QWidget*>("centralwidget");
//    ui->widgetContainer->setLayout(new QVBoxLayout);
//    ui->widgetContainer->layout()->addWidget(serverWidget);
}


void MainWindow::on_ConnectServerButton_clicked()
{
    ClientWindow *clientWindow = new ClientWindow(this);
    clientWindow->show();
//    QWidget *clientWidget = clientWindow->findChild<QWidget*>("centralwidget");
//    ui->widgetContainer->setLayout(new QVBoxLayout);
//    ui->widgetContainer->layout()->addWidget(clientWidget);
}

