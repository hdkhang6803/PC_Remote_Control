#include "initialwindow.h"
#include "ui_initialwindow.h"

initialWindow::initialWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::initialWindow)
{
    ui->setupUi(this);
}

initialWindow::~initialWindow()
{
    delete ui;
}
