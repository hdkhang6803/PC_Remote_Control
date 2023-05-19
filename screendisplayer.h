#ifndef SCREENDISPLAYER_H
#define SCREENDISPLAYER_H

#include <QWidget>

namespace Ui {
class screendisplayer;
}

class screendisplayer : public QWidget
{
    Q_OBJECT

public:
    explicit screendisplayer(QWidget *parent = nullptr);
    ~screendisplayer();

private:
    Ui::screendisplayer *ui;
};

#endif // SCREENDISPLAYER_H
