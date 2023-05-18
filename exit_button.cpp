#include "exit_button.h"
#include "ui_exit_button.h"
#include <QPushButton>
#include "client.h"

exit_button::exit_button(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::exit_button)
{
    ui->setupUi(this);
}

exit_button::~exit_button()
{
    delete ui;
}
void exit_button::on_pushButton_clicked()
{
//    connect(this, &QPushButton::clicked,  ,&Client::send_stop_record_msg);
//    close();
}

