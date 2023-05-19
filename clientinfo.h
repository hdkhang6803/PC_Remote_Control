#ifndef CLIENTINFO_H
#define CLIENTINFO_H

#include <QMainWindow>

namespace Ui {
class clientInfo;
}

class clientInfo : public QMainWindow
{
    Q_OBJECT

public:
    explicit clientInfo(QWidget *parent = nullptr);
    ~clientInfo();

private:
    Ui::clientInfo *ui;
};

#endif // CLIENTINFO_H
