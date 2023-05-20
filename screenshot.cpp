#include "screenshot.h"
#include "ui_screenshot.h"

screenshot::screenshot(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::screenshot)
{
    ui->setupUi(this);
}

screenshot::~screenshot()
{
    delete ui;
}
