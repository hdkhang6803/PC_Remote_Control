#include "screendisplayer.h"

screendisplayer::screendisplayer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::screendisplayer)
{
    ui->setupUi(this);
    connect(ui->startButton, &QPushButton::clicked, [=]{
        if (record_flag == 0){
            emit(start_stream());
            ui->startButton->setText(tr("Stop"));
            ui->startButton->setStyleSheet("border-radius: 10px;\nbox-shadow:  10px 5px 5px rgb(0, 0, 0);\nbackground: #cb0000;\nborder:  1px solid rgb(154, 154, 154);\ncolor: white\n\n");
            record_flag = 1;
        }
        else{
            emit(close_stream());
            ui->startButton->setText(tr("Start"));
            ui->startButton->setStyleSheet("border-radius: 10px;\nbox-shadow:  10px 5px 5px rgb(0, 0, 0);\nbackground: #C2E7FF;\nborder:  1px solid rgb(154, 154, 154);\ncolor: black\n\n");
            record_flag = 0;
        }

    });
    connect(ui->exitButton, &QPushButton::clicked, [=]{

        if(record_flag == 1){
            emit(close_stream());
            ui->startButton->setText(tr("Start"));
            ui->startButton->setStyleSheet("border-radius: 10px;\nbox-shadow:  10px 5px 5px rgb(0, 0, 0);\nbackground: #C2E7FF;\nborder:  1px solid rgb(154, 154, 154);\ncolor: black\n\n");
            record_flag = 0;
        }
        delete this;
    });

    this->show();
}

void screendisplayer::display_image(QByteArray& img_byte){
    QPixmap img;
    img.loadFromData(img_byte, "JPEG");
    ui->screenLabel->setPixmap(img);
    ui->screenLabel->setScaledContents( true );

    ui->screenLabel->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
}

screendisplayer::~screendisplayer()
{
    delete ui;
}
