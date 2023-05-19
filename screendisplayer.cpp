#include "screendisplayer.h"
#include "ui_screendisplayer.h"

screendisplayer::screendisplayer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::screendisplayer)
{
    ui->setupUi(this);
}

screendisplayer::~screendisplayer()
{
    delete ui;
}
