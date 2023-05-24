#include "screenshot.h"
#include "include/ui_screenshot.h"

screenshot::screenshot(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::screenshot)
{
    ui->setupUi(this);
    connect(ui->captureButton, &QPushButton::clicked, this, &screenshot::on_captureButton_clicked);
    connect(ui->saveButton, &QPushButton::clicked, this, &screenshot::on_saveButton_clicked);
    connect(ui->exitButton, &QPushButton::clicked, this, &screenshot::on_exitButton_clicked);
    this->show();
}

screenshot::~screenshot()
{
    delete ui;
}

void screenshot::on_captureButton_clicked(){
    emit(capture());
    qDebug() << "capture clicked";
}

void screenshot::on_saveButton_clicked(){
    emit(save());
    qDebug() << "save clicked";
}

void screenshot::on_exitButton_clicked(){
    emit(end_session());
}

void screenshot::display_image(QByteArray& img_byte){
    QPixmap img;
    img.loadFromData(img_byte, "JPEG");
    ui->screenLabel->setPixmap(img);
    ui->screenLabel->setScaledContents( true );

    ui->screenLabel->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
}

