#include "clientwindow1.h"
#include "ui_clientwindow1.h"

clientWindow1::clientWindow1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::clientWindow1)
{
    ui->setupUi(this);
}

clientWindow1::~clientWindow1()
{
    delete ui;
}
