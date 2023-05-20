#include "processes.h"
#include "ui_processes.h"

processes::processes(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::processes)
{
    ui->setupUi(this);
}

processes::~processes()
{
    delete ui;
}
