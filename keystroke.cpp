#include "keystroke.h"
#include "ui_keystroke.h"

keystroke::keystroke(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::keystroke)
{
    ui->setupUi(this);
}

keystroke::~keystroke()
{
    delete ui;
}
