
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QVBoxLayout>
#include <QPushButton>
#include "clientWindow.h"
#include "serverWindow.h"

//QT_BEGIN_NAMESPACE
namespace Ui { class initialWindow; }
//QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
//    ~MainWindow();

private slots:
    void on_CreateServerButton_clicked();

    void on_ConnectServerButton_clicked();

private:
    Ui::initialWindow *ui;
    QHBoxLayout *buttonLayout = nullptr;
    QPushButton *createServerButton = nullptr;
    QPushButton *connectServerButton = nullptr;

    QWidget *buttonWidget = nullptr;

    QVBoxLayout *overallLayout = nullptr;
    QWidget *logoWidget = nullptr;

    QWidget *centralWidget = nullptr;

private:
    ClientWindow* client_window = nullptr;
    serverInfo * server_info = nullptr;
};

#endif // MAINWINDOW_H
