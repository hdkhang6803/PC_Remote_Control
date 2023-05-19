#ifndef INITIALWINDOW_H
#define INITIALWINDOW_H

#include <QMainWindow>

namespace Ui {
class initialWindow;
}

class initialWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit initialWindow(QWidget *parent = nullptr);
    ~initialWindow();

private:
    Ui::initialWindow *ui;
};

#endif // INITIALWINDOW_H
