#include "audiorecorder.h"
#include "ui_audiorecorder.h"

audiorecorder::audiorecorder(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::audiorecorder)
{
    ui->setupUi(this);
}

audiorecorder::~audiorecorder()
{
    delete ui;
}
