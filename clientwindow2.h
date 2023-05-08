#ifndef CLIENTWINDOW2_H
#define CLIENTWINDOW2_H

#include <QMainWindow>

namespace Ui {
class ClientWindow2;
}

class ClientWindow2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit ClientWindow2(QWidget *parent = nullptr);
    ~ClientWindow2();

private:
    Ui::ClientWindow2 *ui;
};

#endif // CLIENTWINDOW2_H
