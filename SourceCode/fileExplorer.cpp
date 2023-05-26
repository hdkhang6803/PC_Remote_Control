#include "fileExplorer.h"

#include <QDebug>

fileExplorer::fileExplorer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::fileExplorer)
{
    ui->setupUi(this);

    connect(ui->exitButton, &QPushButton::clicked, [=](){
        close();
    });
    connect(ui->backButton, &QPushButton::clicked, [=](){
        qDebug() << ui->Path->text() + "//..";
        emit (sendFolderRequest(ui->Path->text() + "/.."));
    });
}

fileExplorer::~fileExplorer()
{
    delete ui;
}

QString getFolderName(const QString& path)
{
    int lastSlashPos = path.lastIndexOf('/');
    if (lastSlashPos != -1)
        return path.left(lastSlashPos);
    else
        return "";
}

QString getFileName(const QString& path)
{
    int lastSlashPos = path.lastIndexOf('/');
    if (lastSlashPos != -1)
        return path.mid(lastSlashPos + 1);
    else
        return path;
}

QString fileExplorer::getName(const QString& path)
{
    int lastSlashPos = path.lastIndexOf('/');
    int extensionPos = path.lastIndexOf('.');
    if (lastSlashPos != -1)
    {
        if (extensionPos != -1 && extensionPos > lastSlashPos)
            return path.mid(lastSlashPos + 1, extensionPos - lastSlashPos - 1);
        else
            return path.mid(lastSlashPos + 1);
    }
    else
    {
        if (extensionPos != -1)
            return path.left(extensionPos);
        else
            return path;
    }
}

void fileExplorer::updateFilesWindow(QStringList files) {
    QGridLayout *layout = ui->DirectoryGrid;
    QFrame *GirdFrame = ui->GirdFrame;

    int numColumns = 7;
    int rowIndex = 0;
    int colIndex = 0;

    for (auto x : fileNameLabels) {
        if (x) delete x;
    }
    fileNameLabels.clear();
    for (auto x : fileNavList) {
        if (x) delete x;
    }
    fileNavList.clear();
    for (auto x : vboxList) {
        if (x) {

            QWidget* widget1 = x->itemAt(0)->widget();
            QWidget* widget2 = x->itemAt(1)->widget();

            // Remove the widgets from the layout
            x->removeWidget(widget1);
            x->removeWidget(widget2);

            // Delete the widgets
            delete widget1;
            delete widget2;
            delete x;
        }
    }
    vboxList.clear();
    layout->update();

    numColumns = 7;
    rowIndex = 0;
    colIndex = 0;

    QStringList sortedFiles = files;
    std::sort(sortedFiles.begin(), sortedFiles.end(), [](const QString &a, const QString &b) {
        if (a[0] == '1' && a[0] == b[0])
            return a < b;
        return a[0] == '1';
    });

    QString curDirSpe = sortedFiles[0];
    QString curDir = curDirSpe;
    curDir.remove(0, 1);
    curDir.chop(3);
    qDebug() << curDir << "\n";
    ui->Path->setText(curDir);

    for (int i = 0; i < sortedFiles.size(); ++i) {
        QString filePathSpe = sortedFiles[i];
        QString filePath = filePathSpe;
        filePath.remove(0, 1);

        // Determine if it's a directory or file
        bool isDirectory = (filePathSpe[0] == '1');
        qDebug() << filePathSpe << filePath << isDirectory;

        QString name = getName(filePath);
        //        QLabel *label = new QLabel(name);

        qDebug() << filePath;

        // Calculate the row and column positions
        rowIndex = i / numColumns;
        colIndex = i % numColumns;
        qDebug() << rowIndex << colIndex;

        //        QIcon iconDir("folder.png");
        //        QIcon iconFile("document.png");

        FileNavButton *button = new FileNavButton();

        fileNavList.push_back(button);
        button->setStyleSheet("background-color: transparent;");


        //        bool isDirectory = QFileInfo(filePath).isDir();
        connect(button, FileNavButton::doubleClicked, [isDirectory, filePath, this]() {
            //            MyPushButton *button = static_cast<MyPushButton*>(sender());
            //            bool isDirectory = (filePathSpe[0] == '1');
            //            QString filePath = filePathSpe.remove(0, 1);
            if (isDirectory) {
                qDebug() << "Directory double-clicked!";
//                this->client->sendFolderRequest(filePath);
                emit (sendFolderRequest(filePath));
            } else {
                qDebug() << "File double-clicked!";
            }
            //            button->deleteLater();
        });

        QVBoxLayout* vbox = new QVBoxLayout();
        vboxList.push_back(vbox);
        vbox->setObjectName(name);

        QLabel* IconFile1_5 = new QLabel(GirdFrame);
        IconFile1_5->setObjectName("IconFile1_5");
        IconFile1_5->setMaximumSize(QSize(100, 100));
        IconFile1_5->setTextFormat(Qt::RichText);
        IconFile1_5->setStyleSheet(QString::fromUtf8("padding-top: 8px;\n"
                                                     "padding-bottom: 2px;\n"
                                                     "margin: 0px;"));
        IconFile1_5->setPixmap(QPixmap(QString::fromUtf8("document.png")));
        if (isDirectory)
            IconFile1_5->setPixmap(QPixmap(QString::fromUtf8("folder.png")));
        IconFile1_5->setScaledContents(true);
        IconFile1_5->setMargin(17);

        //        vbox->addWidget(button);
        vbox->addWidget(IconFile1_5);

        QLabel* nameLabel = new QLabel(GirdFrame);
        nameLabel->setObjectName("Label_5");
        nameLabel->setMaximumSize(QSize(100, 50));
        nameLabel->setAlignment(Qt::AlignCenter);
        nameLabel->setText(name);
        //        fileNameLabels.push_back(nameLabel);

        vbox->addWidget(nameLabel);

        layout->addLayout(vbox, rowIndex, colIndex, 1, 1);
        layout->addWidget(button, rowIndex, colIndex);
    }
}

void fileExplorer::updateFolderStruct(QStandardItemModel* &model) {
//    qDebug() << "display file struct";
//        QTreeView *treeView = ui->treeView;
//        treeView->setModel(model);
//        treeView->setHeaderHidden(true);
//        treeView->setSelectionMode(QAbstractItemView::ExtendedSelection);
//        treeView->setAnimated(true);
//        treeView->setIndentation(20);
//        treeView->setSortingEnabled(true);
//        treeView->setContextMenuPolicy(Qt::CustomContextMenu);
//        treeView->setExpandsOnDoubleClick(true);
//        treeView->setStyleSheet("QTreeView::item { height: 26px; }");
//        connect(treeView, SIGNAL(clicked(const QModelIndex&)), this, SLOT(onItemClicked(const QModelIndex&)));

//        treeView->show();

}

// Define the slot that will be triggered
void fileExplorer::onItemClicked(const QModelIndex& index)
{
        // Retrieve the selected item's data
        QVariant itemData = index.data(Qt::UserRole);
        QString filePathSpe = itemData.toString();
        QString filePath = filePathSpe.remove(0, 1);
        qDebug() << "ON CLICK: " << itemData << filePath;
//        this->client->sendFolderRequest(filePath);
        emit (sendFolderRequest(filePath));

}
