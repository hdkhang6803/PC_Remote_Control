#ifndef SCREENDISPLAYER_H
#define SCREENDISPLAYER_H

#include <QWidget>
#include "include/ui_screendisplayer.h"

namespace Ui {
class screendisplayer;
}

class screendisplayer : public QWidget
{
    Q_OBJECT

signals:
    void start_stream();
    void close_stream();
public:
    explicit screendisplayer(QWidget *parent = nullptr);
    ~screendisplayer();

    void display_image(QByteArray& img_byte);

private:
    Ui::screendisplayer *ui;
    bool record_flag = 0;
};

#endif // SCREENDISPLAYER_H
