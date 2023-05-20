#ifndef KEYSTROKE_H
#define KEYSTROKE_H

#include <QWidget>

namespace Ui {
class keystroke;
}

class keystroke : public QWidget
{
    Q_OBJECT

public:
    explicit keystroke(QWidget *parent = nullptr);
    ~keystroke();

private:
    Ui::keystroke *ui;
};

#endif // KEYSTROKE_H
