#include "clientinfo.h"
#include "ui_clientinfo.h"

clientInfo::clientInfo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::clientInfo)
{
    ui->setupUi(this);
}

clientInfo::~clientInfo()
{
    delete ui;
}
