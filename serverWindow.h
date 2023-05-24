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
#include "include\ui_serverinfo.h"
//#include "fileExplorer.h"

namespace Ui {
class serverInfo;
}

class serverInfo : public QMainWindow
{
    Q_OBJECT

public:
    explicit serverInfo(QWidget *parent = nullptr);
//    ~ServerWindow();

private slots:
    void updateServerMsg(const QString &msg);
    void updatePic(const QPixmap &pic);

private:
    Ui::serverInfo *ui;

    Server *server = nullptr;
//    fileExplorer *myFileExplorer = nullptr;

//    // GUI ele
//    QVBoxLayout *overallLayout = nullptr;
//    QWidget *serverInfoWidget = nullptr;
//    QWidget *buttonsWidget = nullptr;

//    QFormLayout *serverInfoLayout = nullptr;
    QLabel *_ipLabel = nullptr;
    QLabel *_portLabel = nullptr;
    QTextEdit *_ipBox = nullptr;
    QLineEdit *_portBox = nullptr;
    QLabel *statusLabel = nullptr;
    QTextEdit *statusBox = nullptr;

//    QHBoxLayout *buttonsLayout = nullptr;
//    QPushButton *restartButton = nullptr;
    QPushButton *exitButton = nullptr;

//    QWidget *centralWidget = nullptr;


};

#endif // SERVERWINDOW_H
