#ifndef FUNCTIONWIDGET_H
#define FUNCTIONWIDGET_H

#include <QWidget>

#include "client.h"
#include "connectDialog.h"

namespace Ui {
class FunctionWidget;
}

class FunctionWidget : public QWidget
{
    Q_OBJECT

public:
    explicit FunctionWidget(QWidget *parent = nullptr);
    ~FunctionWidget();

private slots:
    void receivedServerInfo(const QString &serverIp, int port);

    void on_pushButton_clicked();

private:
    Ui::FunctionWidget *ui;

    Client *client = nullptr;
    ConnectDialog *connectDialog = nullptr;
};

#endif // FUNCTIONWIDGET_H
