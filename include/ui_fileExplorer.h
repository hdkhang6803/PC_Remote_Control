/********************************************************************************
** Form generated from reading UI file 'fileexplorer.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILEEXPLORER_H
#define UI_FILEEXPLORER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_fileExplorer
{
public:
    QWidget *MainWidget;
    QLabel *TreeView;
    QTreeWidget *treeWidget;
    QLabel *Path;
    QScrollArea *scrollArea;
    QWidget *Contents;
    QVBoxLayout *verticalLayout_2;
    QFrame *GirdFrame;
    QVBoxLayout *verticalLayout;
    QGridLayout *DirectoryGrid;
    QVBoxLayout *File1_25;
    QLabel *IconFile1_20;
    QLabel *Label_20;
    QVBoxLayout *File1_9;
    QLabel *IconFile1_4;
    QLabel *Label_4;
    QVBoxLayout *File1_10;
    QLabel *IconFile1_5;
    QLabel *Label_5;
    QVBoxLayout *File1_12;
    QLabel *IconFile1_7;
    QLabel *label;
    QVBoxLayout *File1_7;
    QLabel *IconFile1_2;
    QLabel *Label_2;
    QVBoxLayout *Folder1;
    QLabel *Folder1_icon;
    QLabel *Folder1_label;
    QVBoxLayout *File1_27;
    QLabel *IconFile1_22;
    QLabel *Label_22;
    QVBoxLayout *File1_13;
    QLabel *IconFile1_8;
    QLabel *Label_8;
    QVBoxLayout *Folder3;
    QLabel *Folder3_icon;
    QLabel *Folder3_label;
    QVBoxLayout *Folder2;
    QLabel *Folder2_icon;
    QLabel *Folder2_label;
    QVBoxLayout *File1_24;
    QLabel *IconFile1_19;
    QLabel *Label_19;
    QSpacerItem *VSpacer;
    QVBoxLayout *File1_11;
    QLabel *IconFile1_6;
    QLabel *Label_6;
    QVBoxLayout *File1_26;
    QLabel *IconFile1_21;
    QLabel *Label_21;
    QSpacerItem *HSpacer;
    QVBoxLayout *File1;
    QLabel *File1_icon;
    QLabel *File1_label;
    QVBoxLayout *File1_28;
    QLabel *IconFile1_23;
    QLabel *Label_23;

    void setupUi(QWidget *fileExplorer)
    {
        if (fileExplorer->objectName().isEmpty())
            fileExplorer->setObjectName("fileExplorer");
        fileExplorer->resize(1040, 940);
        MainWidget = new QWidget(fileExplorer);
        MainWidget->setObjectName("MainWidget");
        MainWidget->setGeometry(QRect(0, 0, 901, 571));
        MainWidget->setStyleSheet(QString::fromUtf8("border-radius: 5px;\n"
"background-color: #F2F6FC;"));
        TreeView = new QLabel(MainWidget);
        TreeView->setObjectName("TreeView");
        TreeView->setGeometry(QRect(10, 20, 221, 31));
        TreeView->setStyleSheet(QString::fromUtf8("background-color: rgb(194, 231, 255);\n"
"border: 1px #000000;\n"
"border-radius: 5px;\n"
"padding-left: 10px;\n"
"font: 600 11pt \"UTM Avo\";"));
        treeWidget = new QTreeWidget(MainWidget);
        QBrush brush(QColor(0, 132, 255, 255));
        brush.setStyle(Qt::NoBrush);
        QFont font;
        font.setFamilies({QString::fromUtf8("UTM Avo")});
        font.setPointSize(14);
        font.setBold(true);
        treeWidget->headerItem()->setText(0, QString());
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setFont(0, font);
        __qtreewidgetitem->setBackground(0, QColor(194, 231, 255));
        __qtreewidgetitem->setForeground(0, brush);
        treeWidget->setHeaderItem(__qtreewidgetitem);
        QIcon icon;
        QString iconThemeName = QString::fromUtf8("folder");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        QFont font1;
        font1.setFamilies({QString::fromUtf8("UTM Avo")});
        font1.setPointSize(10);
        font1.setBold(true);
        QIcon icon1;
        iconThemeName = QString::fromUtf8("document-open");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon1 = QIcon::fromTheme(iconThemeName);
        } else {
            icon1.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem(treeWidget);
        __qtreewidgetitem1->setFont(0, font1);
        __qtreewidgetitem1->setIcon(0, icon);
        QTreeWidgetItem *__qtreewidgetitem2 = new QTreeWidgetItem(__qtreewidgetitem1);
        __qtreewidgetitem2->setIcon(0, icon1);
        new QTreeWidgetItem(__qtreewidgetitem1);
        QTreeWidgetItem *__qtreewidgetitem3 = new QTreeWidgetItem(__qtreewidgetitem1);
        __qtreewidgetitem3->setFont(0, font1);
        new QTreeWidgetItem(__qtreewidgetitem3);
        QTreeWidgetItem *__qtreewidgetitem4 = new QTreeWidgetItem(treeWidget);
        __qtreewidgetitem4->setFont(0, font1);
        QTreeWidgetItem *__qtreewidgetitem5 = new QTreeWidgetItem(__qtreewidgetitem4);
        __qtreewidgetitem5->setFont(0, font1);
        new QTreeWidgetItem(__qtreewidgetitem4);
        QTreeWidgetItem *__qtreewidgetitem6 = new QTreeWidgetItem(treeWidget);
        __qtreewidgetitem6->setFont(0, font1);
        new QTreeWidgetItem(treeWidget);
        treeWidget->setObjectName("treeWidget");
        treeWidget->setGeometry(QRect(10, 60, 221, 501));
        treeWidget->setStyleSheet(QString::fromUtf8("background-color: #ffffff;\n"
"border: 1px #000000;\n"
"border-radius: 5px;\n"
"padding-left: 10px;\n"
"font: 500 10pt \"UTM Avo\";"));
        Path = new QLabel(MainWidget);
        Path->setObjectName("Path");
        Path->setGeometry(QRect(240, 20, 631, 31));
        Path->setStyleSheet(QString::fromUtf8("background-color: rgb(194, 231, 255);\n"
"border: 1px #000000;\n"
"border-radius: 5px;\n"
"padding-left: 10px;\n"
"font: 600 11pt \"UTM Avo\";"));
        scrollArea = new QScrollArea(MainWidget);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(240, 60, 631, 500));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy);
        scrollArea->setMinimumSize(QSize(500, 100));
        scrollArea->setMaximumSize(QSize(16777215, 16777215));
        scrollArea->setStyleSheet(QString::fromUtf8("background-color: #ffffff;\n"
"border: 1px #000000;\n"
"border-radius: 5px;\n"
"padding-left: 10px;\n"
"font: 500 10pt \"UTM Avo\";"));
        scrollArea->setWidgetResizable(true);
        Contents = new QWidget();
        Contents->setObjectName("Contents");
        Contents->setGeometry(QRect(0, 0, 604, 1222));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Contents->sizePolicy().hasHeightForWidth());
        Contents->setSizePolicy(sizePolicy1);
        verticalLayout_2 = new QVBoxLayout(Contents);
        verticalLayout_2->setObjectName("verticalLayout_2");
        GirdFrame = new QFrame(Contents);
        GirdFrame->setObjectName("GirdFrame");
        sizePolicy1.setHeightForWidth(GirdFrame->sizePolicy().hasHeightForWidth());
        GirdFrame->setSizePolicy(sizePolicy1);
        GirdFrame->setMinimumSize(QSize(500, 1200));
        GirdFrame->setMaximumSize(QSize(1500, 15004));
        GirdFrame->setStyleSheet(QString::fromUtf8(""));
        GirdFrame->setFrameShape(QFrame::StyledPanel);
        GirdFrame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(GirdFrame);
        verticalLayout->setObjectName("verticalLayout");
        DirectoryGrid = new QGridLayout();
        DirectoryGrid->setObjectName("DirectoryGrid");
        File1_25 = new QVBoxLayout();
        File1_25->setObjectName("File1_25");
        IconFile1_20 = new QLabel(GirdFrame);
        IconFile1_20->setObjectName("IconFile1_20");
        IconFile1_20->setMaximumSize(QSize(100, 100));
        IconFile1_20->setTextFormat(Qt::RichText);
        IconFile1_20->setPixmap(QPixmap(QString::fromUtf8("C:/Users/LENOVO/Downloads/document.png")));
        IconFile1_20->setScaledContents(true);
        IconFile1_20->setMargin(17);

        File1_25->addWidget(IconFile1_20);

        Label_20 = new QLabel(GirdFrame);
        Label_20->setObjectName("Label_20");
        Label_20->setMaximumSize(QSize(100, 50));
        Label_20->setAlignment(Qt::AlignCenter);

        File1_25->addWidget(Label_20);


        DirectoryGrid->addLayout(File1_25, 4, 0, 1, 1);

        File1_9 = new QVBoxLayout();
        File1_9->setObjectName("File1_9");
        IconFile1_4 = new QLabel(GirdFrame);
        IconFile1_4->setObjectName("IconFile1_4");
        IconFile1_4->setMaximumSize(QSize(100, 100));
        IconFile1_4->setTextFormat(Qt::RichText);
        IconFile1_4->setPixmap(QPixmap(QString::fromUtf8("C:/Users/LENOVO/Downloads/document.png")));
        IconFile1_4->setScaledContents(true);
        IconFile1_4->setMargin(17);

        File1_9->addWidget(IconFile1_4);

        Label_4 = new QLabel(GirdFrame);
        Label_4->setObjectName("Label_4");
        Label_4->setMaximumSize(QSize(100, 50));
        Label_4->setAlignment(Qt::AlignCenter);

        File1_9->addWidget(Label_4);


        DirectoryGrid->addLayout(File1_9, 2, 0, 1, 1);

        File1_10 = new QVBoxLayout();
        File1_10->setObjectName("File1_10");
        IconFile1_5 = new QLabel(GirdFrame);
        IconFile1_5->setObjectName("IconFile1_5");
        IconFile1_5->setMaximumSize(QSize(100, 100));
        IconFile1_5->setTextFormat(Qt::RichText);
        IconFile1_5->setPixmap(QPixmap(QString::fromUtf8("C:/Users/LENOVO/Downloads/document.png")));
        IconFile1_5->setScaledContents(true);
        IconFile1_5->setMargin(17);

        File1_10->addWidget(IconFile1_5);

        Label_5 = new QLabel(GirdFrame);
        Label_5->setObjectName("Label_5");
        Label_5->setMaximumSize(QSize(100, 50));
        Label_5->setAlignment(Qt::AlignCenter);

        File1_10->addWidget(Label_5);


        DirectoryGrid->addLayout(File1_10, 2, 1, 1, 1);

        File1_12 = new QVBoxLayout();
        File1_12->setObjectName("File1_12");
        IconFile1_7 = new QLabel(GirdFrame);
        IconFile1_7->setObjectName("IconFile1_7");
        IconFile1_7->setMaximumSize(QSize(100, 100));
        IconFile1_7->setTextFormat(Qt::RichText);
        IconFile1_7->setPixmap(QPixmap(QString::fromUtf8("C:/Users/LENOVO/Downloads/document.png")));
        IconFile1_7->setScaledContents(true);
        IconFile1_7->setMargin(17);

        File1_12->addWidget(IconFile1_7);

        label = new QLabel(GirdFrame);
        label->setObjectName("label");
        label->setMaximumSize(QSize(100, 50));
        label->setAlignment(Qt::AlignCenter);

        File1_12->addWidget(label);


        DirectoryGrid->addLayout(File1_12, 2, 3, 1, 1);

        File1_7 = new QVBoxLayout();
        File1_7->setObjectName("File1_7");
        IconFile1_2 = new QLabel(GirdFrame);
        IconFile1_2->setObjectName("IconFile1_2");
        IconFile1_2->setMaximumSize(QSize(100, 100));
        IconFile1_2->setTextFormat(Qt::RichText);
        IconFile1_2->setPixmap(QPixmap(QString::fromUtf8("C:/Users/LENOVO/Downloads/document.png")));
        IconFile1_2->setScaledContents(true);
        IconFile1_2->setMargin(17);

        File1_7->addWidget(IconFile1_2);

        Label_2 = new QLabel(GirdFrame);
        Label_2->setObjectName("Label_2");
        Label_2->setMaximumSize(QSize(100, 50));
        Label_2->setAlignment(Qt::AlignCenter);

        File1_7->addWidget(Label_2);


        DirectoryGrid->addLayout(File1_7, 0, 4, 1, 1);

        Folder1 = new QVBoxLayout();
        Folder1->setObjectName("Folder1");
        Folder1_icon = new QLabel(GirdFrame);
        Folder1_icon->setObjectName("Folder1_icon");
        Folder1_icon->setMaximumSize(QSize(100, 100));
        Folder1_icon->setTextFormat(Qt::RichText);
        Folder1_icon->setPixmap(QPixmap(QString::fromUtf8("C:/Users/LENOVO/Downloads/folder (1).png")));
        Folder1_icon->setScaledContents(true);
        Folder1_icon->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        Folder1_icon->setMargin(10);

        Folder1->addWidget(Folder1_icon);

        Folder1_label = new QLabel(GirdFrame);
        Folder1_label->setObjectName("Folder1_label");
        Folder1_label->setMaximumSize(QSize(100, 50));
        Folder1_label->setAlignment(Qt::AlignCenter);

        Folder1->addWidget(Folder1_label);


        DirectoryGrid->addLayout(Folder1, 0, 0, 1, 1);

        File1_27 = new QVBoxLayout();
        File1_27->setObjectName("File1_27");
        IconFile1_22 = new QLabel(GirdFrame);
        IconFile1_22->setObjectName("IconFile1_22");
        IconFile1_22->setMaximumSize(QSize(100, 100));
        IconFile1_22->setTextFormat(Qt::RichText);
        IconFile1_22->setPixmap(QPixmap(QString::fromUtf8("C:/Users/LENOVO/Downloads/document.png")));
        IconFile1_22->setScaledContents(true);
        IconFile1_22->setMargin(17);

        File1_27->addWidget(IconFile1_22);

        Label_22 = new QLabel(GirdFrame);
        Label_22->setObjectName("Label_22");
        Label_22->setMaximumSize(QSize(100, 50));
        Label_22->setAlignment(Qt::AlignCenter);

        File1_27->addWidget(Label_22);


        DirectoryGrid->addLayout(File1_27, 3, 0, 1, 1);

        File1_13 = new QVBoxLayout();
        File1_13->setObjectName("File1_13");
        IconFile1_8 = new QLabel(GirdFrame);
        IconFile1_8->setObjectName("IconFile1_8");
        IconFile1_8->setMaximumSize(QSize(100, 100));
        IconFile1_8->setTextFormat(Qt::RichText);
        IconFile1_8->setPixmap(QPixmap(QString::fromUtf8("C:/Users/LENOVO/Downloads/document.png")));
        IconFile1_8->setScaledContents(true);
        IconFile1_8->setMargin(17);

        File1_13->addWidget(IconFile1_8);

        Label_8 = new QLabel(GirdFrame);
        Label_8->setObjectName("Label_8");
        Label_8->setMaximumSize(QSize(100, 50));
        Label_8->setAlignment(Qt::AlignCenter);

        File1_13->addWidget(Label_8);


        DirectoryGrid->addLayout(File1_13, 2, 4, 1, 1);

        Folder3 = new QVBoxLayout();
        Folder3->setObjectName("Folder3");
        Folder3_icon = new QLabel(GirdFrame);
        Folder3_icon->setObjectName("Folder3_icon");
        Folder3_icon->setMaximumSize(QSize(100, 100));
        Folder3_icon->setTextFormat(Qt::RichText);
        Folder3_icon->setPixmap(QPixmap(QString::fromUtf8("C:/Users/LENOVO/Downloads/folder (1).png")));
        Folder3_icon->setScaledContents(true);
        Folder3_icon->setMargin(10);

        Folder3->addWidget(Folder3_icon);

        Folder3_label = new QLabel(GirdFrame);
        Folder3_label->setObjectName("Folder3_label");
        Folder3_label->setMaximumSize(QSize(100, 50));
        Folder3_label->setAlignment(Qt::AlignCenter);

        Folder3->addWidget(Folder3_label);


        DirectoryGrid->addLayout(Folder3, 0, 2, 1, 1);

        Folder2 = new QVBoxLayout();
        Folder2->setObjectName("Folder2");
        Folder2_icon = new QLabel(GirdFrame);
        Folder2_icon->setObjectName("Folder2_icon");
        Folder2_icon->setMaximumSize(QSize(100, 100));
        Folder2_icon->setTextFormat(Qt::RichText);
        Folder2_icon->setPixmap(QPixmap(QString::fromUtf8("C:/Users/LENOVO/Downloads/folder (1).png")));
        Folder2_icon->setScaledContents(true);
        Folder2_icon->setMargin(10);

        Folder2->addWidget(Folder2_icon);

        Folder2_label = new QLabel(GirdFrame);
        Folder2_label->setObjectName("Folder2_label");
        Folder2_label->setMaximumSize(QSize(100, 50));
        Folder2_label->setAlignment(Qt::AlignCenter);

        Folder2->addWidget(Folder2_label);


        DirectoryGrid->addLayout(Folder2, 0, 1, 1, 1);

        File1_24 = new QVBoxLayout();
        File1_24->setObjectName("File1_24");
        IconFile1_19 = new QLabel(GirdFrame);
        IconFile1_19->setObjectName("IconFile1_19");
        IconFile1_19->setMaximumSize(QSize(100, 100));
        IconFile1_19->setTextFormat(Qt::RichText);
        IconFile1_19->setPixmap(QPixmap(QString::fromUtf8("C:/Users/LENOVO/Downloads/document.png")));
        IconFile1_19->setScaledContents(true);
        IconFile1_19->setMargin(17);

        File1_24->addWidget(IconFile1_19);

        Label_19 = new QLabel(GirdFrame);
        Label_19->setObjectName("Label_19");
        Label_19->setMaximumSize(QSize(100, 50));
        Label_19->setAlignment(Qt::AlignCenter);

        File1_24->addWidget(Label_19);


        DirectoryGrid->addLayout(File1_24, 0, 6, 1, 1);

        VSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        DirectoryGrid->addItem(VSpacer, 6, 0, 1, 1);

        File1_11 = new QVBoxLayout();
        File1_11->setObjectName("File1_11");
        IconFile1_6 = new QLabel(GirdFrame);
        IconFile1_6->setObjectName("IconFile1_6");
        IconFile1_6->setMaximumSize(QSize(100, 100));
        IconFile1_6->setTextFormat(Qt::RichText);
        IconFile1_6->setPixmap(QPixmap(QString::fromUtf8("C:/Users/LENOVO/Downloads/document.png")));
        IconFile1_6->setScaledContents(true);
        IconFile1_6->setMargin(17);

        File1_11->addWidget(IconFile1_6);

        Label_6 = new QLabel(GirdFrame);
        Label_6->setObjectName("Label_6");
        Label_6->setMaximumSize(QSize(100, 50));
        Label_6->setAlignment(Qt::AlignCenter);

        File1_11->addWidget(Label_6);


        DirectoryGrid->addLayout(File1_11, 2, 2, 1, 1);

        File1_26 = new QVBoxLayout();
        File1_26->setObjectName("File1_26");
        IconFile1_21 = new QLabel(GirdFrame);
        IconFile1_21->setObjectName("IconFile1_21");
        IconFile1_21->setMaximumSize(QSize(100, 100));
        IconFile1_21->setTextFormat(Qt::RichText);
        IconFile1_21->setPixmap(QPixmap(QString::fromUtf8("C:/Users/LENOVO/Downloads/document.png")));
        IconFile1_21->setScaledContents(true);
        IconFile1_21->setMargin(17);

        File1_26->addWidget(IconFile1_21);

        Label_21 = new QLabel(GirdFrame);
        Label_21->setObjectName("Label_21");
        Label_21->setMaximumSize(QSize(100, 50));
        Label_21->setAlignment(Qt::AlignCenter);

        File1_26->addWidget(Label_21);


        DirectoryGrid->addLayout(File1_26, 5, 0, 1, 1);

        HSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        DirectoryGrid->addItem(HSpacer, 0, 5, 1, 1);

        File1 = new QVBoxLayout();
        File1->setObjectName("File1");
        File1_icon = new QLabel(GirdFrame);
        File1_icon->setObjectName("File1_icon");
        File1_icon->setMaximumSize(QSize(100, 100));
        File1_icon->setTextFormat(Qt::RichText);
        File1_icon->setPixmap(QPixmap(QString::fromUtf8("C:/Users/LENOVO/Downloads/document.png")));
        File1_icon->setScaledContents(true);
        File1_icon->setMargin(17);

        File1->addWidget(File1_icon);

        File1_label = new QLabel(GirdFrame);
        File1_label->setObjectName("File1_label");
        File1_label->setMaximumSize(QSize(100, 50));
        File1_label->setAlignment(Qt::AlignCenter);

        File1->addWidget(File1_label);


        DirectoryGrid->addLayout(File1, 0, 3, 1, 1);

        File1_28 = new QVBoxLayout();
        File1_28->setObjectName("File1_28");
        IconFile1_23 = new QLabel(GirdFrame);
        IconFile1_23->setObjectName("IconFile1_23");
        IconFile1_23->setMaximumSize(QSize(100, 100));
        IconFile1_23->setTextFormat(Qt::RichText);
        IconFile1_23->setPixmap(QPixmap(QString::fromUtf8("C:/Users/LENOVO/Downloads/document.png")));
        IconFile1_23->setScaledContents(true);
        IconFile1_23->setMargin(17);

        File1_28->addWidget(IconFile1_23);

        Label_23 = new QLabel(GirdFrame);
        Label_23->setObjectName("Label_23");
        Label_23->setMaximumSize(QSize(100, 50));
        Label_23->setAlignment(Qt::AlignCenter);

        File1_28->addWidget(Label_23);


        DirectoryGrid->addLayout(File1_28, 1, 0, 1, 1);


        verticalLayout->addLayout(DirectoryGrid);


        verticalLayout_2->addWidget(GirdFrame);

        scrollArea->setWidget(Contents);
        treeWidget->raise();
        TreeView->raise();
        scrollArea->raise();
        Path->raise();

        retranslateUi(fileExplorer);

        QMetaObject::connectSlotsByName(fileExplorer);
    } // setupUi

    void retranslateUi(QWidget *fileExplorer)
    {
        fileExplorer->setWindowTitle(QCoreApplication::translate("fileExplorer", "Form", nullptr));
        TreeView->setText(QCoreApplication::translate("fileExplorer", "Tree View", nullptr));

        const bool __sortingEnabled = treeWidget->isSortingEnabled();
        treeWidget->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->topLevelItem(0);
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("fileExplorer", "Folder1", nullptr));
        QTreeWidgetItem *___qtreewidgetitem1 = ___qtreewidgetitem->child(0);
        ___qtreewidgetitem1->setText(0, QCoreApplication::translate("fileExplorer", "File1.1", nullptr));
        QTreeWidgetItem *___qtreewidgetitem2 = ___qtreewidgetitem->child(1);
        ___qtreewidgetitem2->setText(0, QCoreApplication::translate("fileExplorer", "File1.2", nullptr));
        QTreeWidgetItem *___qtreewidgetitem3 = ___qtreewidgetitem->child(2);
        ___qtreewidgetitem3->setText(0, QCoreApplication::translate("fileExplorer", "Folder1.1", nullptr));
        QTreeWidgetItem *___qtreewidgetitem4 = ___qtreewidgetitem3->child(0);
        ___qtreewidgetitem4->setText(0, QCoreApplication::translate("fileExplorer", "File1.3", nullptr));
        QTreeWidgetItem *___qtreewidgetitem5 = treeWidget->topLevelItem(1);
        ___qtreewidgetitem5->setText(0, QCoreApplication::translate("fileExplorer", "Folder2", nullptr));
        QTreeWidgetItem *___qtreewidgetitem6 = ___qtreewidgetitem5->child(0);
        ___qtreewidgetitem6->setText(0, QCoreApplication::translate("fileExplorer", "Folder2.1", nullptr));
        QTreeWidgetItem *___qtreewidgetitem7 = ___qtreewidgetitem5->child(1);
        ___qtreewidgetitem7->setText(0, QCoreApplication::translate("fileExplorer", "File2.1", nullptr));
        QTreeWidgetItem *___qtreewidgetitem8 = treeWidget->topLevelItem(2);
        ___qtreewidgetitem8->setText(0, QCoreApplication::translate("fileExplorer", "Folder3", nullptr));
        QTreeWidgetItem *___qtreewidgetitem9 = treeWidget->topLevelItem(3);
        ___qtreewidgetitem9->setText(0, QCoreApplication::translate("fileExplorer", "File1", nullptr));
        treeWidget->setSortingEnabled(__sortingEnabled);

        Path->setText(QCoreApplication::translate("fileExplorer", "D:\\Folder2", nullptr));
        IconFile1_20->setText(QString());
        Label_20->setText(QCoreApplication::translate("fileExplorer", "File1", nullptr));
        IconFile1_4->setText(QString());
        Label_4->setText(QCoreApplication::translate("fileExplorer", "File1", nullptr));
        IconFile1_5->setText(QString());
        Label_5->setText(QCoreApplication::translate("fileExplorer", "File1", nullptr));
        IconFile1_7->setText(QString());
        label->setText(QCoreApplication::translate("fileExplorer", "File1", nullptr));
        IconFile1_2->setText(QString());
        Label_2->setText(QCoreApplication::translate("fileExplorer", "File1", nullptr));
        Folder1_icon->setText(QString());
        Folder1_label->setText(QCoreApplication::translate("fileExplorer", "Folder1", nullptr));
        IconFile1_22->setText(QString());
        Label_22->setText(QCoreApplication::translate("fileExplorer", "File1", nullptr));
        IconFile1_8->setText(QString());
        Label_8->setText(QCoreApplication::translate("fileExplorer", "File1", nullptr));
        Folder3_icon->setText(QString());
        Folder3_label->setText(QCoreApplication::translate("fileExplorer", "Folder3", nullptr));
        Folder2_icon->setText(QString());
        Folder2_label->setText(QCoreApplication::translate("fileExplorer", "Folder2", nullptr));
        IconFile1_19->setText(QString());
        Label_19->setText(QCoreApplication::translate("fileExplorer", "File1", nullptr));
        IconFile1_6->setText(QString());
        Label_6->setText(QCoreApplication::translate("fileExplorer", "File1", nullptr));
        IconFile1_21->setText(QString());
        Label_21->setText(QCoreApplication::translate("fileExplorer", "File1", nullptr));
        File1_icon->setText(QString());
        File1_label->setText(QCoreApplication::translate("fileExplorer", "File1", nullptr));
        IconFile1_23->setText(QString());
        Label_23->setText(QCoreApplication::translate("fileExplorer", "File1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class fileExplorer: public Ui_fileExplorer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILEEXPLORER_H
