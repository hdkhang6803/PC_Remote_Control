#include "audiowindow.h"
#include "include/ui_audiorecorder.h"

audioWindow::audioWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::audiorecorder)
{
    ui->setupUi(this);
    connect(ui->stopButton, &QPushButton::clicked, this, &audioWindow::on_stopButton_clicked);
    ui->timer->setVisible(false);
    m_timer = new QTimer(this);
}

audioWindow::~audioWindow()
{
    delete ui;
    delete m_timer;
}

void audioWindow::on_stopButton_clicked(){
    emit(click_stop());
}

void audioWindow::set_time(){
    qDebug() << "recording timer start";
    QDateTime startTime = QDateTime::currentDateTime();


    connect(m_timer, &QTimer::timeout, [=]() {
        qDebug() << "timer count";
        QDateTime currentTime = QDateTime::currentDateTime();
        qint64 elapsedSeconds = startTime.secsTo(currentTime);
        QString timeText = QString("%1:%2:%3")
                               .arg(elapsedSeconds / 3600, 2, 10, QLatin1Char('0')) // Hours
                               .arg((elapsedSeconds % 3600) / 60, 2, 10, QLatin1Char('0')) // Minutes
                               .arg(elapsedSeconds % 60, 2, 10, QLatin1Char('0')); // Seconds
         ui->timer->setText(timeText);
         ui->timer->setVisible(true);

    });
    m_timer->start(1000);
}
