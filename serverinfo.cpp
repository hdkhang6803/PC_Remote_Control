#include "serverinfo.h"
#include "ui_serverinfo.h"

serverInfo::serverInfo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::serverInfo)
{
    ui->setupUi(this);
}

serverInfo::~serverInfo()
{
    delete ui;
}
