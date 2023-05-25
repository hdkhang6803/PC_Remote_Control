#include "clientWindow.h"
//#include "D:\UltimateDownload\_Yr2Sem2\mmt\socket project\include\include\ui_clientWindow.h"

// #include "include/ui_clientWindow.h"
#include "audiowindow.h"


#include "client.h"
#include <QDebug>
#include <QTimer>
#include <QDateTime>

ClientWindow::ClientWindow(QWidget *parent) :
    QMainWindow(parent)
    , ui(new Ui::clientWindow)
{
    ui->setupUi(this);

    client = new Client;
    client_info = new clientInfo;


    connect(client_info, &clientInfo::connectToServer, this, &ClientWindow::receivedServerInfo);
//    connect(client_info, &clientInfo::exit, this, &ClientWindow::close);
    connect(client, &Client::stringMessageReceived, this, &ClientWindow::updateServerMsg);
    connect(client, &Client::imageMessageReceived, this, &ClientWindow::updateImage);
    connect(client, &Client::directoryStructReceived, this, &ClientWindow::updateFileStruct);
    connect(client, &Client::fileStructReceived, this, &ClientWindow::updateFilesWindow);
    connect(client, &Client::allAppsReceived, this, &ClientWindow::updateAllApps);
    connect(client, &Client::processesReceived, this, &ClientWindow::updateProcesses);
    connect(client, &Client::runningAppsReceived, this, &ClientWindow::updateRunningApps);



//    // ------------SETTING UP GUI --------------------

    _ipLabel = ui->ipLabel;
    _portLabel = ui->portLabel;
    _ipBox = ui->ipBox;
    _portBox = ui->portBox;



    processButton = ui->processButton_2;
//    appButton = ui->processButton_2;
    keystrButton =  ui->processButton_3;
    screenButton = ui->processButton_4;
    fileButton = ui->processButton_5;
    streamButton = ui->processButton_6;
    audioButton = ui->processButton_7;
    contrButton = ui->processButton_8;
    exitButton = ui->exitButton;
    connect(processButton, &QPushButton::clicked, this, &ClientWindow::on_pushButton_clicked_1);
//    connect(processButton, &QPushButton::clicked, this, &ClientWindow::on_pushButton_clicked_2);
    connect(keystrButton, &QPushButton::clicked, this, &ClientWindow::on_pushButton_clicked_3);
    connect(screenButton, &QPushButton::clicked, this, &ClientWindow::on_pushButton_clicked_4);
    connect(fileButton, &QPushButton::clicked, this, &ClientWindow::on_pushButton_clicked_5);
    connect(streamButton, &QPushButton::clicked, this, &ClientWindow::on_pushButton_clicked_6);
    connect(audioButton, &QPushButton::clicked, this, &ClientWindow::on_pushButton_clicked_7);
    connect(contrButton, &QPushButton::clicked, this, &ClientWindow::on_pushButton_clicked_8);

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


void ClientWindow::updateFilesWindow(QStringList files) {
    if (fileExp == nullptr) {
        qDebug() << "Error: not found file explorer window";
        return;
    }

    QGridLayout *layout = fileExp->ui->DirectoryGrid;

    int numColumns = 7;
    int rowIndex = 0;
    int colIndex = 0;

//    for (int i = 0; i < 100; ++i) {

//        // Calculate the row and column positions
//        rowIndex = i / numColumns;
//        colIndex = i % numColumns;
//        qDebug() << rowIndex << colIndex;

//        // Check if a widget already exists in the target cell
//        QLayoutItem *existingItem = layout->itemAtPosition(rowIndex, colIndex);
//        if (existingItem) {
//            QWidget *existingWidget = existingItem->widget();
//            layout->removeWidget(existingWidget);
//            delete existingWidget;
//        }
//    }
    for (auto x : fileExp->fileNameLabels) {
        delete x;
    }
    fileExp->fileNameLabels.clear();
    for (auto x : fileExp->fileNavList) {
        delete x;
    }
    fileExp->fileNavList.clear();
    layout->update();

    numColumns = 7;
    rowIndex = 0;
    colIndex = 0;

    QStringList sortedFiles = files;
    std::sort(sortedFiles.begin(), sortedFiles.end(), [](const QString &a, const QString &b) {
        QFileInfo fileInfoA(a);
        QFileInfo fileInfoB(b);
        if (fileInfoA.isDir() == fileInfoB.isDir())
            return a < b;
        return fileInfoA.isDir();
    });

    fileExp->ui->Path->setText(sortedFiles[0]);


    for (int i = 0; i < sortedFiles.size(); ++i) {
        QString filePath = sortedFiles[i];
        QFileInfo fileInfo(filePath);
        QString name = fileInfo.fileName();
        QLabel *label = new QLabel(name);
        fileExp->fileNameLabels.push_back(label);
        qDebug() << filePath;

        // Calculate the row and column positions
        rowIndex = i / numColumns;
        colIndex = i % numColumns;
        qDebug() << rowIndex << colIndex;

        FileNavButton *button = new FileNavButton();
        fileExp->fileNavList.push_back(button);
        button->setStyleSheet("background-color: transparent;");
//        button->setStyleSheet("QPushButton {"
//                              "  background-color: transparent;"
//                              "  border: none;"
//                              "  padding: 0px;"
//                              "}");

        // Determine if it's a directory or file

//        bool isDirectory = QFileInfo(filePath).isDir();

        connect(button, FileNavButton::doubleClicked, [filePath, this]() {
//            MyPushButton *button = static_cast<MyPushButton*>(sender());
            bool isDirectory = QFileInfo(filePath).isDir();
            if (isDirectory) {
                qDebug() << "Directory double-clicked!";
                this->client->sendFolderRequest(filePath);
            } else {
                qDebug() << "File double-clicked!";
            }
//            button->deleteLater();
        });

        // Add the QLabel to the layout
        layout->addWidget(label, rowIndex, colIndex);
        layout->addWidget(button, rowIndex, colIndex);

//        colIndex++;
    }
}

void ClientWindow::updateFileStruct(QStandardItemModel* &model) {
    qDebug() << "display file struct";
    if (fileExp == nullptr) {
        qDebug() << "Error: not found file explorer window";
        return;
    }
    QTreeView *treeView = fileExp->ui->treeView;
//    QTreeView *treeView = treeWidget->treeView();
//    treeView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    treeView->setModel(model);
    treeView->setHeaderHidden(true);
    treeView->setSelectionMode(QAbstractItemView::ExtendedSelection);
    treeView->setAnimated(true);
    treeView->setIndentation(20);
    treeView->setSortingEnabled(true);
    treeView->setContextMenuPolicy(Qt::CustomContextMenu);
    treeView->setExpandsOnDoubleClick(true);
    treeView->setStyleSheet("QTreeView::item { height: 26px; }");
    connect(treeView, SIGNAL(clicked(const QModelIndex&)), this, SLOT(onItemClicked(const QModelIndex&)));

//    connect(treeView, &QTreeView::doubleClicked, this, &ClientWindow::onTreeViewDoubleClicked);
//    treeView->show();
//    treeView->setFixedSize(200, 200); // Set a minimum size for the tree view
//    rightPanelLayout->addWidget(treeView);
    treeView->show();
}

// Define the slot that will be triggered
void ClientWindow::onItemClicked(const QModelIndex& index)
{
    // Retrieve the selected item's data
    QVariant itemData = index.data(Qt::UserRole);
    QString itemPath = itemData.toString();
    qDebug() << "ON CLICKN E: " << itemData << itemPath;
    this->client->sendFolderRequest(itemPath);

    // Perform any desired actions with the selected item
    // ...
}

void ClientWindow::updateAllApps(QStandardItemModel* &model) {
    qDebug() << "display all apps";
    if (appsWin == nullptr) {
        qDebug() << "Error: not found list app window";
        return;
    }
//    QTreeView *treeView = new QTreeView(appsWin->ui-);
    QTreeView *treeView = appsWin->ui->appTree;
    //    treeView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    treeView->setModel(model);
    treeView->setHeaderHidden(true);
    treeView->setSelectionMode(QAbstractItemView::ExtendedSelection);
    treeView->setAnimated(true);
    treeView->setIndentation(20);
    treeView->setSortingEnabled(true);
    treeView->setContextMenuPolicy(Qt::CustomContextMenu);
//    treeView->setExpandsOnDoubleClick(true);
//    treeView->setStyleSheet("QTreeView::item { height: 26px; }");
//    connect(treeView, &QTreeView::doubleClicked, this, &ClientWindow::onTreeViewDoubleClicked);
    //    treeView->show();
    //    treeView->setFixedSize(200, 200); // Set a minimum size for the tree view
    //    rightPanelLayout->addWidget(treeView);
    qDebug() << "are you sleeping?";
    treeView->show();
}

void ClientWindow::updateProcesses(QStandardItemModel* &model) {
    qDebug() << "display all processes";
    if (appsWin == nullptr) {
        qDebug() << "No window to display.\n";
        return;
    }
    //    if (appsWin == nullptr) {
    //        qDebug() << "Error: not found list app window";
    //    }
    //    QTreeView *treeView = new QTreeView(appsWin->ui-);
    QTableView *tableView = appsWin->ui->processTable;
    model->setHeaderData(0, Qt::Horizontal, "Process Name");
    model->setHeaderData(1, Qt::Horizontal, "PID");
    tableView->setModel(model);

    tableView->show();
}


void ClientWindow::updateRunningApps(QStandardItemModel* &model) {
    if (appsWin == nullptr) {
        return;
    }
    qDebug() << "display running apps";
    //    if (appsWin == nullptr) {
    //        qDebug() << "Error: not found list app window";
    //    }
    //    QTreeView *treeView = new QTreeView(appsWin->ui-);
    QTreeView *treeView = appsWin->ui->runningAppTree;
    //    treeView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    treeView->setModel(model);
    treeView->setHeaderHidden(true);
    treeView->setSelectionMode(QAbstractItemView::ExtendedSelection);
    treeView->setAnimated(true);
    treeView->setIndentation(20);
    treeView->setSortingEnabled(true);
    treeView->setContextMenuPolicy(Qt::CustomContextMenu);
//    treeView->setExpandsOnDoubleClick(true);
    //    treeView->setStyleSheet("QTreeView::item { height: 26px; }");
    //    connect(treeView, &QTreeView::doubleClicked, this, &ClientWindow::onTreeViewDoubleClicked);
    //    treeView->show();
    //    treeView->setFixedSize(200, 200); // Set a minimum size for the tree view
    //    rightPanelLayout->addWidget(treeView);
    treeView->show();
}

void ClientWindow::onTreeViewDoubleClicked(const QModelIndex &index)
{
//    // get the file path from the user role of the clicked item
//    QString filePath = index.data(Qt::UserRole).toString();

//    // open the file using QDesktopServices::openUrl()
//    QDesktopServices::openUrl(QUrl::fromLocalFile(filePath));
}

void ClientWindow::on_pushButton_clicked_1(){
//    client->sendMessage(tr("list processes"));
//    client->sendMessage(tr("list applications"));
    if (!appsWin)
        appsWin = new appsWindow(ui->widget_2);
    appsWin->show();
//    connect(appsWin->ui->exitButton, &QPushButton::clicked, [=](){
//        client->sendMessage(tr("stop_recording"));
//        delete appsWin;
////        appWin->
//    });
    client->sendMessage(tr("list processes and apps"));
//    client->sendMessage(tr("list applications"));
}
void ClientWindow::on_pushButton_clicked_2(){
    client->sendMessage(tr("list applications"));
}
void ClientWindow::on_pushButton_clicked_3(){
    client->sendMessage(tr("keyboard track"));

}
void ClientWindow::on_pushButton_clicked_4(){
    client->sendMessage(tr("take screenshot"));

}
void ClientWindow::on_pushButton_clicked_5(){
    qDebug() << "sending ls cmd";
    client->sendFolderRequest(tr("."));
    fileExp = new fileExplorer(ui->widget_2);
    fileExp->show();
    connect(fileExp->ui->exitButton, QPushButton::clicked, [=](){
        delete fileExp;
    });
}
void ClientWindow::on_pushButton_clicked_6(){

}
void ClientWindow::on_pushButton_clicked_7(){
    client->sendMessage(tr("recording"));

//    QWidget* previous_widg = ui->widget_2;
    audioWindow* audio_w = new audioWindow(ui->widget_2);
    audio_w->set_time();
    audio_w->show();
    connect(audio_w, &audioWindow::click_stop, [=](){
        client->sendMessage(tr("stop_recording"));
        delete audio_w;
    });


}
void ClientWindow::on_pushButton_clicked_8(){

}
