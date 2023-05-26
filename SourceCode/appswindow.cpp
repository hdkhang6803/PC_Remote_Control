#include "appswindow.h"
//#include "ui_apps.h"

appsWindow::appsWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::apps)
{
    ui->setupUi(this);
}

appsWindow::~appsWindow()
{
    delete ui;
}
