
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "connectDialog.h"
#include "server.h"

#include "functionwidget.h"

#include <iostream>

using std::cout;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{
    cout << "okay" << "\n";
    Server server;
    server.exec();
}

void MainWindow::on_pushButton_2_clicked()
{
    FunctionWidget *widget = new FunctionWidget;
    widget->show();
    widget->activateWindow();

}

