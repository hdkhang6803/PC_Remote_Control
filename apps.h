#ifndef APPS_H
#define APPS_H

#include <QWidget>

namespace Ui {
class apps;
}

class apps : public QWidget
{
    Q_OBJECT

public:
    explicit apps(QWidget *parent = nullptr);
    ~apps();

private:
    Ui::apps *ui;
};

#endif // APPS_H
