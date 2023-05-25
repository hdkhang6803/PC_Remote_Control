#include "keystroke.h"
#include "include/ui_keystroke.h"

keystroke::keystroke(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::keystroke)
{
    ui->setupUi(this);
    ui->startButton->setText(tr("Start"));
    connect(ui->clearButton, &QPushButton::clicked, this, &keystroke::m_on_clear_clicked);
    connect(ui->exitButton, &QPushButton::clicked, this, &keystroke::m_on_exit_clicked);
    connect(ui->startButton, &QPushButton::clicked, this, &keystroke::m_on_start_clicked);
    ui->textEdit->clear();
    ui->textEdit_2->clear();
    ui->textEdit->setEnabled(true);
    ui->textEdit_2->setEnabled(true);
    ui->textEdit->setReadOnly(true);
    ui->textEdit_2->setReadOnly(true);
    this->show();
}

keystroke::~keystroke()
{
    delete ui;
}

void keystroke::m_on_clear_clicked(){
    ui->textEdit->clear();
    ui->textEdit_2->clear();
}

void keystroke::m_on_start_clicked(){
    if(is_running_flag == 0){
        ui->startButton->setText(tr("Stop"));
        ui->startButton->setStyleSheet("border-radius: 10px;\nfont: 600 9pt \"UTM Avo\";\nbackground: #cb0000;\nborder:  1px solid rgb(154, 154, 154);\ncolor: white\n\n");
        is_running_flag = 1;
        emit(start_hook());
    }
    else{
        ui->startButton->setText(tr("Start"));
        ui->startButton->setStyleSheet("border-radius: 10px;\nfont: 600 9pt \"UTM Avo\";\nbackground: #C2E7FF;\ncolor: black;\nborder:  1px solid rgb(154, 154, 154)\n\n");
        is_running_flag = 0;
        emit(end_hook());
    }
}

void keystroke::m_on_exit_clicked(){
    if(is_running_flag==1){
        ui->startButton->setText(tr("Start"));
        ui->startButton->setStyleSheet("border-radius: 10px;\nfont: 600 9pt \"UTM Avo\";\nbackground: #C2E7FF;\ncolor: black;\nborder:  1px solid rgb(154, 154, 154)\n\n");
        is_running_flag = 0;
        emit(end_hook());
    }
    emit(end_session_stroke());
}

void keystroke::display_stroke(QString& str1, QString& str2){
    if(this != nullptr){
        qDebug() << "display: " << str1 << "||" <<str2;
        if(str1 != "")
            ui->textEdit->append(str1);
        if(str2 != "")
            ui->textEdit_2->append(str2);
    }

}
