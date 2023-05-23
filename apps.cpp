#include "apps.h"
#include "ui_apps.h"

apps::apps(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::apps)
{
    ui->setupUi(this);
}

apps::~apps()
{
    delete ui;
}
