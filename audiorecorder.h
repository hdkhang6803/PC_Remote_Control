#ifndef AUDIORECORDER_H
#define AUDIORECORDER_H

#include <QWidget>

namespace Ui {
class audiorecorder;
}

class audiorecorder : public QWidget
{
    Q_OBJECT

public:
    explicit audiorecorder(QWidget *parent = nullptr);
    ~audiorecorder();

private:
    Ui::audiorecorder *ui;
};

#endif // AUDIORECORDER_H
