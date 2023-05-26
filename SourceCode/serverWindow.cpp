#include "serverWindow.h"
//#include "D:\UltimateDownload\_Yr2Sem2\mmt\socket project\include\include\ui_serverinfo.h"

serverInfo::serverInfo(QWidget *parent) :
    QMainWindow(parent)
    , ui(new Ui::serverInfo)
{
    ui->setupUi(this);

    server = new Server;

    connect(server, &Server::displayMsg, this, &serverInfo::updateServerMsg);
    connect(server, &Server::display, this, &serverInfo::updatePic);

//    // ------------SETTING UP GUI ----------------------
    exitButton = ui->exitButton;
    _ipLabel = ui->IDlabel;
    _portLabel = ui->portLabel;
    _ipBox = ui->IPInput;
    _portBox = ui->portInput;
    statusLabel = ui->statusLabel;
    statusBox = ui->statusText;

    connect(exitButton, SIGNAL(clicked()), this, SLOT(close()));

    statusBox->clear();
    updateServerMsg(tr("The server is running now."));

    _ipBox->clear();

    for (int i = 0; i < server->adapterNamesList.size(); i++) {
        QString adapter = server->adapterNamesList.at(i);
        if (adapter.contains("Wireless")) {
            _ipBox->append("Wifi: ");
        }
        else if (adapter.contains("Ethernet")) {
            _ipBox->append("Ethernet: ");
        }
        QString ipAddress = server->ipAddressList.at(i);
        if (ipAddress != "0.0.0.0") {
//        _ipBox->append(ipAddress);
        _ipBox->moveCursor(QTextCursor::End); // Move the cursor to the end of the text
        _ipBox->insertPlainText(ipAddress + "\n");

        }
//        _ipBox->setText(ipAddress);
    }
    _portBox->setText(server->port);
    _portBox->setReadOnly(true);
}

void serverInfo::updateServerMsg(const QString &msg) {
//    statusBox->setText(msg);
    statusBox->moveCursor(QTextCursor::End);
    statusBox->insertPlainText(">>" + msg + "\n");
}

void serverInfo::updatePic(const QPixmap &screenshot) {
    qDebug() << "display picture?";
    QLabel *screenshotLabel = new QLabel();
    screenshotLabel->setPixmap(screenshot);
}
