#ifndef SCREENSHOT_H
#define SCREENSHOT_H

#include <QWidget>

namespace Ui {
class screenshot;
}

class screenshot : public QWidget
{
    Q_OBJECT

public:
    explicit screenshot(QWidget *parent = nullptr);
    ~screenshot();

private:
    Ui::screenshot *ui;
};

#endif // SCREENSHOT_H
