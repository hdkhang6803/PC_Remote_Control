#include "screenshot.h"
#include "include/ui_screenshot.h"

screenshot::screenshot(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::screenshot)
{
    ui->setupUi(this);
    connect(ui->captureButton, &QPushButton::clicked, this, &screenshot::m_on_captureButton_clicked);
    connect(ui->saveButton, &QPushButton::clicked, this, &screenshot::m_on_saveButton_clicked);
    connect(ui->exitButton, &QPushButton::clicked, this, &screenshot::m_on_exitButton_clicked);
    ui->saveButton->setDisabled(true);
    this->show();
}

screenshot::~screenshot()
{
    delete ui;
}

void screenshot::m_on_captureButton_clicked(){
    qDebug() << "capture clicked";
    ui->saveButton->setEnabled(true);
    ui->saveButton->setText(tr("Save"));
    emit(capture());
}

void screenshot::m_on_saveButton_clicked(){
    qDebug() << "save clicked";
    emit(save());
    ui->saveButton->setText(tr("Saved"));
    ui->saveButton->setDisabled(true);
}

void screenshot::m_on_exitButton_clicked(){
    emit(end_session());
}

void screenshot::display_image(QByteArray& img_byte){
    if(this != nullptr){
        QPixmap img;
        img.loadFromData(img_byte, "JPEG");
        ui->screenLabel->setPixmap(img);
        ui->screenLabel->setScaledContents( true );

        ui->screenLabel->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
    }
}

