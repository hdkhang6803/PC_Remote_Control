
#include "mainWindow.h"
//#include "D:\UltimateDownload\_Yr2Sem2\mmt\socket project\include\include\ui_initialwindow.h"

#include "serverWindow.h"
#include "clientWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::initialWindow)
{
    ui->setupUi(this);
    createServerButton = ui->pushButton_2;
    connectServerButton = ui->pushButton_3;

    connect(createServerButton, SIGNAL(clicked()), this, SLOT(on_CreateServerButton_clicked()));
    connect(connectServerButton, SIGNAL(clicked()), this, SLOT(on_ConnectServerButton_clicked()));
}

void MainWindow::on_CreateServerButton_clicked()
{
    server_info = new serverInfo(this);
    server_info->show();
}


void MainWindow::on_ConnectServerButton_clicked()
{
    ClientWindow *clientWindow = new ClientWindow(this);
}

