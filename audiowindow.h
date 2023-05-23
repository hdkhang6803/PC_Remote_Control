#ifndef AUDIOWINDOW_H
#define AUDIOWINDOW_H

#include <QWidget>
#include "include/ui_audiorecorder.h"
#include <QDateTime>
#include <QTimer>

namespace Ui {
class audiorecorder;
}

class audioWindow : public QWidget
{
    Q_OBJECT

public:
    explicit audioWindow(QWidget *parent = nullptr);
    ~audioWindow();

public slots:
    void set_time();
private slots:
    void on_stopButton_clicked();

signals:
    void click_stop();
private:
    Ui::audiorecorder *ui;
};

#endif // AUDIOWINDOW_H
