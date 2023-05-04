#ifndef SERVERWINDOW_H
#define SERVERWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

#include <QPixmap>

#include "server.h"

//namespace Ui {
//class ServerWindow;
//}

class ServerWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ServerWindow(QWidget *parent = nullptr);
//    ~ServerWindow();

private slots:
    void updateServerMsg(const QString &msg);
    void updatePic(const QPixmap &pic);

private:
//    Ui::ServerWindow *ui;

    Server *server = nullptr;

    // GUI ele
    QVBoxLayout *overallLayout = nullptr;
    QWidget *serverInfoWidget = nullptr;
    QWidget *buttonsWidget = nullptr;

    QFormLayout *serverInfoLayout = nullptr;
    QLabel *ipLabel = nullptr;
    QLabel *portLabel = nullptr;
    QLineEdit *ipBox = nullptr;
    QLineEdit *portBox = nullptr;
    QLabel *statusLabel = nullptr;
    QLineEdit *statusBox = nullptr;

    QHBoxLayout *buttonsLayout = nullptr;
    QPushButton *restartButton = nullptr;
    QPushButton *exitButton = nullptr;

    QWidget *centralWidget = nullptr;


};

#endif // SERVERWINDOW_H
