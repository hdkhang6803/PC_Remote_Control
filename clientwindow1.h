#ifndef CLIENTWINDOW1_H
#define CLIENTWINDOW1_H

#include <QMainWindow>
#include "ui_clientwindow1.h"

namespace Ui {
class clientWindow1;
}

class clientWindow1 : public QMainWindow
{
    Q_OBJECT

public:
    explicit clientWindow1(QWidget *parent = nullptr);
    ~clientWindow1();

private:
    Ui::clientWindow1 *ui;
};

#endif // CLIENTWINDOW1_H
