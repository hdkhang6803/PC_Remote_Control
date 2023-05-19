#include "clientwindow.h"
#include "ui_clientwindow.h"

clientWindow::clientWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::clientWindow)
{
    ui->setupUi(this);
}

clientWindow::~clientWindow()
{
    delete ui;
}
