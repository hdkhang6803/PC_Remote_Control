#ifndef APPSWINDOW_H
#define APPSWINDOW_H

#include <QWidget>
#include "include/ui_apps.h"

namespace Ui {
class apps;
}

class appsWindow : public QWidget
{
    Q_OBJECT

public:
    explicit appsWindow(QWidget *parent = nullptr);
    ~appsWindow();

public:
    Ui::apps *ui;

};

#endif // APPSWINDOW_H
