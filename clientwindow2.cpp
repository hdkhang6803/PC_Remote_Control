#include "clientwindow2.h"
#include "ui_clientwindow2.h"

ClientWindow2::ClientWindow2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ClientWindow2)
{
    ui->setupUi(this);
}

ClientWindow2::~ClientWindow2()
{
    delete ui;
}
