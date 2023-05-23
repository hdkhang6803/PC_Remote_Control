#include "audiowindow.h"
#include "include/ui_audiorecorder.h"

audioWindow::audioWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::audiorecorder)
{
    ui->setupUi(this);
    connect(ui->stopButton, &QPushButton::clicked, this, &audioWindow::on_stopButton_clicked);

}

audioWindow::~audioWindow()
{
    delete ui;
}

void audioWindow::on_stopButton_clicked(){
    emit(click_stop());
}

void audioWindow::set_time(){
    qDebug() << "recording timer start";
    QDateTime startTime = QDateTime::currentDateTime();
    QLabel* timer_txt = ui->timer;
    QTimer timer;
    connect(&timer, &QTimer::timeout, [=]() {
        QDateTime currentTime = QDateTime::currentDateTime();
        qint64 elapsedSeconds = startTime.secsTo(currentTime);
        QString timeText = QString("%1:%2:%3")
                               .arg(elapsedSeconds / 3600, 2, 10, QLatin1Char('0')) // Hours
                               .arg((elapsedSeconds % 3600) / 60, 2, 10, QLatin1Char('0')) // Minutes
                               .arg(elapsedSeconds % 60, 2, 10, QLatin1Char('0')); // Seconds
        timer_txt->setText(timeText);
        timer_txt->show();
        qDebug() << "timer count";
    });
    timer.start(1000); // Update every 1 second (1000 ms)
}
