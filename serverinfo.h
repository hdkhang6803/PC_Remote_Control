#ifndef SERVERINFO_H
#define SERVERINFO_H

#include <QMainWindow>

namespace Ui {
class serverInfo;
}

class serverInfo : public QMainWindow
{
    Q_OBJECT

public:
    explicit serverInfo(QWidget *parent = nullptr);
    ~serverInfo();

private:
    Ui::serverInfo *ui;
};

#endif // SERVERINFO_H
