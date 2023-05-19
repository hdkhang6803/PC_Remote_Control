#include "fileexplorer.h"
#include "ui_fileexplorer.h"

fileExplorer::fileExplorer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::fileExplorer)
{
    ui->setupUi(this);
}

fileExplorer::~fileExplorer()
{
    delete ui;
}
