#ifndef CLIENTWINDOW_H
#define CLIENTWINDOW_H

#include <QMainWindow>
#include <vector>
using std::vector;

#include <QVBoxLayout>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGroupBox>
#include <QTreeView>
#include <QDesktopServices>

#include "client.h"
#include "clientInfo.h"
//#include "featureButton.h"
#include "include/ui_clientWindow.h"
#include "appswindow.h"

//QT_BEGIN_NAMESPACE
//class QLabel;
//class QLineEdit;
//class QPushButton;
//class QHBoxLayout;
//class QFormLayout;
//class QVBoxLayout;
//class QGroupBox;
//QT_END_NAMESPACE

namespace Ui {
class clientWindow;
}

const int numberOfFeat = 8;

class ClientWindow : public QMainWindow
{
    Q_OBJECT

    typedef void (ClientWindow::*featBtnFuncPointer)();
public:
    explicit ClientWindow(QWidget *parent = nullptr);
//    ~ClientWindow();

private:
    Ui::clientWindow *ui;

signals:
    void appear();

private slots:
    void receivedServerInfo(const QString &serverIp, int port);
    void connect_success();
    void connect_fail();

    void updateServerMsg(const QString &msg);
    void updateImage(const QPixmap &image);
    void updateFileStruct(QStandardItemModel* &model);
    void updateAllApps(QStandardItemModel* &model);
    void updateProcesses(QStandardItemModel* &model);

    void onTreeViewDoubleClicked(const QModelIndex &index);

private:

    Client *client = nullptr;
    clientInfo *client_info = nullptr;


    QLabel *_ipLabel = nullptr;
    QLabel *_portLabel = nullptr;
    QLabel *_ipBox = nullptr;
    QLabel *_portBox = nullptr;

    QPushButton *processButton = nullptr;
    QPushButton *appButton = nullptr;
    QPushButton *keystrButton = nullptr;
    QPushButton *screenButton = nullptr;
    QPushButton *fileButton = nullptr;
    QPushButton *streamButton = nullptr;
    QPushButton *audioButton = nullptr;
    QPushButton *contrButton = nullptr;
    QPushButton *exitButton = nullptr;

    appsWindow* appsWin = nullptr;

private slots:
    void on_pushButton_clicked_1();
    void on_pushButton_clicked_2();
    void on_pushButton_clicked_3();
    void on_pushButton_clicked_4();
    void on_pushButton_clicked_5();
    void on_pushButton_clicked_6();
    void on_pushButton_clicked_7();
    void on_pushButton_clicked_8();

};



#endif // CLIENTWINDOW_H


