#include "clientWindow.h"
#include "audiowindow.h"
#include "screenshot.h"
#include "client.h"
#include <QDebug>
#include <QTimer>
#include <QDateTime>

ClientWindow::ClientWindow(QWidget *parent) :
    QMainWindow(parent)
    , ui(new Ui::clientWindow1)
{
    ui->setupUi(this);

    client = new Client;
    client_info = new clientInfo;


    connect(client_info, &clientInfo::connectToServer, this, &ClientWindow::receivedServerInfo);
//    connect(client_info, &clientInfo::exit, this, &ClientWindow::close);
    connect(client, &Client::stringMessageReceived, this, &ClientWindow::updateServerMsg);
//    connect(client, &Client::imageMessageReceived, this, &ClientWindow::updateImage);
    connect(client, &Client::fileStructReceived, this, &ClientWindow::updateFileStruct);



//    // ------------SETTING UP GUI --------------------

    _ipLabel = ui->ipLabel;
    _portLabel = ui->portLabel;
    _ipBox = ui->ipBox;
    _portBox = ui->portBox;



    PAButton = ui->processButton_1;

    keystrButton =  ui->processButton_3;
    screenButton = ui->processButton_4;
    fileButton = ui->processButton_5;
    streamButton = ui->processButton_6;
    audioButton = ui->processButton_7;
    exitButton = ui->exitButton;
    connect(PAButton, &QPushButton::clicked, this, &ClientWindow::on_pushButton_clicked_1);
    connect(keystrButton, &QPushButton::clicked, this, &ClientWindow::on_pushButton_clicked_3);
    connect(screenButton, &QPushButton::clicked, this, &ClientWindow::on_pushButton_clicked_4);
    connect(fileButton, &QPushButton::clicked, this, &ClientWindow::on_pushButton_clicked_5);
    connect(streamButton, &QPushButton::clicked, this, &ClientWindow::on_pushButton_clicked_6);
    connect(audioButton, &QPushButton::clicked, this, &ClientWindow::on_pushButton_clicked_7);

    connect(exitButton, SIGNAL(clicked()), this, SLOT(close()));

    // -----------------------------------------------


    client_info->show();
}

void ClientWindow::receivedServerInfo(const QString &serverIp, int port) {
    connect(client, &Client::m_connected, this, &ClientWindow::connect_success);
    connect(client, &Client::m_unconnected, this, &ClientWindow::connect_fail);
    client->connectToServer(serverIp, port);
    _ipBox->setText(serverIp);
    _portBox->setText(QString::number(port));
}
void ClientWindow::connect_success(){
    this->show();
    client_info->close();
    qDebug() << "success";
}
void ClientWindow::connect_fail(){
    client_info->fail_mess_display();
    qDebug() << "fail";
}

void ClientWindow::updateServerMsg(const QString &msg) {
//    serverMsgBox->setText(msg);
}

void ClientWindow::updateImage(const QPixmap &image) {
//    qDebug() << "display picture?";
//    if (screenshotLabel == nullptr) {
//        screenshotLabel = new QLabel();
//        screenshotLabel->setPixmap(image);
//        rightPanelLayout->addWidget(screenshotLabel);
//    }
//    else {
//        screenshotLabel->setPixmap(image);
//    }
}

void ClientWindow::updateFileStruct(QStandardItemModel* &model) {
//    qDebug() << "display file struct";
//    QTreeView *treeView = new QTreeView;
////    treeView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
//    treeView->setModel(model);
//    treeView->setHeaderHidden(true);
//    treeView->setSelectionMode(QAbstractItemView::ExtendedSelection);
//    treeView->setAnimated(true);
//    treeView->setIndentation(20);
//    treeView->setSortingEnabled(true);
//    treeView->setContextMenuPolicy(Qt::CustomContextMenu);
//    treeView->setExpandsOnDoubleClick(true);
//    treeView->setStyleSheet("QTreeView::item { height: 26px; }");
//    connect(treeView, &QTreeView::doubleClicked, this, &ClientWindow::onTreeViewDoubleClicked);
////    treeView->show();
////    treeView->setFixedSize(200, 200); // Set a minimum size for the tree view
//    rightPanelLayout->addWidget(treeView);
}

void ClientWindow::onTreeViewDoubleClicked(const QModelIndex &index)
{
//    // get the file path from the user role of the clicked item
//    QString filePath = index.data(Qt::UserRole).toString();

//    // open the file using QDesktopServices::openUrl()
//    QDesktopServices::openUrl(QUrl::fromLocalFile(filePath));
}

void ClientWindow::on_pushButton_clicked_1(){
    client->sendMessage(tr("list processes"));

}
void ClientWindow::on_pushButton_clicked_2(){
    client->sendMessage(tr("list applications"));
}
void ClientWindow::on_pushButton_clicked_3(){
    client->sendMessage(tr("keyboard track"));

}
void ClientWindow::on_pushButton_clicked_4(){
    qDebug() << "screenshot clicked";
    screenshot_wind = new screenshot(ui->widget_2);
    connect(screenshot_wind, &screenshot::capture, [=](){
        client->sendMessage(tr("take screenshot"));
        qDebug() << "capture signal sent";
    });
    connect(screenshot_wind, &screenshot::end_session, [=](){
        delete screenshot_wind;
        screenshot_wind = nullptr;
    });
    connect(screenshot_wind, &screenshot::save, [=](){
        QDateTime date = QDateTime::currentDateTime();
        QString formattedTime = date.toString("ddMMyyyy_hh_mm_ss");
        QByteArray formattedTimeMsg = formattedTime.toLocal8Bit();

        QFile file("screen_" + formattedTime + ".jpg");
        file.open(QIODevice::WriteOnly);
        QPixmap img;
        img.loadFromData(client->rcv_bitmap, "JPEG");
        img.save(&file, "JPEG");
    });
    connect(client, &Client::imageMessageReceived, [=]{
        screenshot_wind->display_image(client->rcv_bitmap);
    });


}
void ClientWindow::on_pushButton_clicked_5(){
    client->sendMessage(tr("ls"));
}
void ClientWindow::on_pushButton_clicked_6(){
    qDebug() << "Stream button clicked";
    stream_win = new screendisplayer(ui->widget_2);
    connect(stream_win, &screendisplayer::start_stream, [=]{
        client->sendMessage(tr("stream screen"));
    });
    connect(stream_win, &screendisplayer::close_stream, [=]{
        client->sendMessage(tr("stop_stream"));
    });
    connect(client, &Client::streamMessageReceived, [=]{
        stream_win->display_image(client->rcv_bitmap);
    });

}
void ClientWindow::on_pushButton_clicked_7(){
    client->sendMessage(tr("recording"));

    audioWindow* audio_w = new audioWindow(ui->widget_2);
    audio_w->set_time();
    audio_w->show();
    connect(audio_w, &audioWindow::click_stop, [=](){
        client->sendMessage(tr("stop_recording"));
        audio_w->m_timer->stop();
        delete audio_w;
    });


}
void ClientWindow::on_pushButton_clicked_8(){

}
