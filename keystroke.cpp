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
        ui->startButton->setStyleSheet("border-radius: 10px;\nbackground: #cb0000;\nborder:  1px solid rgb(154, 154, 154);\ncolor: white\n\n");
        is_running_flag = 1;
        emit(start_hook());
    }
    else{
        ui->startButton->setText(tr("Start"));
        ui->startButton->setStyleSheet("border-radius: 10px;\nbackground: #C2E7FF;\ncolor: black;\nborder:  1px solid rgb(154, 154, 154)\n\n");
        is_running_flag = 0;
        emit(end_hook());
    }
}

void keystroke::m_on_exit_clicked(){
    emit(end_session_stroke());
}

void keystroke::display_stroke(QString str){
    if(this != nullptr){

        (str.replace(tr("\\u0000"), tr(""))).replace(tr("\\r"), tr(""));
        qDebug() << "||" <<str << "||";
        if(str.indexOf(tr(" * ")) < 0)
            ui->textEdit->append(str);
        else{
            QString chopped_str = str.mid(3, str.length() - 1);
            ui->textEdit_2->append(chopped_str);
        }
    }

}
