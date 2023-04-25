#include "functionwidget.h"
#include "ui_functionwidget.h"


FunctionWidget::FunctionWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FunctionWidget)
{
    ui->setupUi(this);

    client = new Client;
    connectDialog = new ConnectDialog;
    connectDialog->exec();

    connect(connectDialog, &ConnectDialog::connectToServer, this, &FunctionWidget::receivedServerInfo);
}

FunctionWidget::~FunctionWidget()
{
    delete ui;
}

void FunctionWidget::receivedServerInfo(const QString &serverIp, int port) {
    client->connectToServer(serverIp, port);
}

void FunctionWidget::on_pushButton_clicked()
{
    client->sendMessage("are you threre");
}

