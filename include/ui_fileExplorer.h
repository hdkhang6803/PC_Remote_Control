/********************************************************************************
** Form generated from reading UI file 'fileExplorer.ui'
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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_fileExplorer
{
public:
    QWidget *MainWidget;
    QLabel *TreeView;
    QTreeView *treeView;
    QLabel *Path;
    QScrollArea *scrollArea;
    QWidget *Contents;
    QVBoxLayout *verticalLayout_2;
    QFrame *GirdFrame;
    QVBoxLayout *verticalLayout;
    QGridLayout *DirectoryGrid;
    QVBoxLayout *File1_25;
    QLabel *IconFile1_20;
    QVBoxLayout *File1_9;
    QLabel *IconFile1_4;
    QVBoxLayout *File1_10;
    QLabel *IconFile1_5;
    QVBoxLayout *File1_12;
    QLabel *IconFile1_7;
    QVBoxLayout *File1_7;
    QLabel *IconFile1_2;
    QVBoxLayout *Folder1;
    QLabel *Folder1_icon;
    QVBoxLayout *File1_27;
    QLabel *IconFile1_22;
    QVBoxLayout *File1_13;
    QLabel *IconFile1_8;
    QVBoxLayout *Folder3;
    QLabel *Folder3_icon;
    QVBoxLayout *Folder2;
    QLabel *Folder2_icon;
    QVBoxLayout *File1_24;
    QLabel *IconFile1_19;
    QSpacerItem *VSpacer;
    QVBoxLayout *File1_11;
    QLabel *IconFile1_6;
    QVBoxLayout *File1_26;
    QLabel *IconFile1_21;
    QSpacerItem *HSpacer;
    QVBoxLayout *File1;
    QLabel *File1_icon;
    QVBoxLayout *File1_28;
    QLabel *IconFile1_23;
    QPushButton *exitButton;
    QPushButton *backButton;
    QLabel *Filler;

    void setupUi(QWidget *fileExplorer)
    {
        if (fileExplorer->objectName().isEmpty())
            fileExplorer->setObjectName("fileExplorer");
        fileExplorer->resize(901, 573);
        MainWidget = new QWidget(fileExplorer);
        MainWidget->setObjectName("MainWidget");
        MainWidget->setGeometry(QRect(0, 0, 901, 571));
        MainWidget->setStyleSheet(QString::fromUtf8("border-radius: 5px;\n"
"background-color: #F2F6FC;"));
        TreeView = new QLabel(MainWidget);
        TreeView->setObjectName("TreeView");
        TreeView->setGeometry(QRect(10, 10, 221, 31));
        TreeView->setStyleSheet(QString::fromUtf8("background-color: rgb(194, 231, 255);\n"
"border: 1px #000000;\n"
"border-radius: 5px;\n"
"padding-left: 10px;\n"
"font: 600 11pt \"UTM Avo\";"));
        treeView = new QTreeView(MainWidget);
        treeView->setObjectName("treeView");
        treeView->setGeometry(QRect(10, 50, 221, 461));
        treeView->setStyleSheet(QString::fromUtf8("background-color: #ffffff;\n"
"border: 1px #000000;\n"
"border-radius: 5px;\n"
"padding-left: 10px;\n"
"font: 500 10pt \"UTM Avo\";"));
        Path = new QLabel(MainWidget);
        Path->setObjectName("Path");
        Path->setGeometry(QRect(280, 10, 591, 31));
        Path->setStyleSheet(QString::fromUtf8("background-color: rgb(194, 231, 255);\n"
"border: 1px #000000;\n"
"border-radius: 5px;\n"
"padding-left: 6px;\n"
"font: 600 11pt \"UTM Avo\";"));
        scrollArea = new QScrollArea(MainWidget);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(240, 50, 631, 500));
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


        DirectoryGrid->addLayout(File1_12, 2, 3, 1, 1);

        File1_7 = new QVBoxLayout();
        File1_7->setObjectName("File1_7");
        IconFile1_2 = new QLabel(GirdFrame);
        IconFile1_2->setObjectName("IconFile1_2");
        IconFile1_2->setMaximumSize(QSize(100, 100));
        IconFile1_2->setStyleSheet(QString::fromUtf8("padding-top: 10px;\n"
"padding-bottom: 6px;\n"
"margin: 14px;"));
        IconFile1_2->setTextFormat(Qt::RichText);
        IconFile1_2->setPixmap(QPixmap(QString::fromUtf8("C:/Users/LENOVO/Downloads/document.png")));
        IconFile1_2->setScaledContents(true);
        IconFile1_2->setMargin(0);

        File1_7->addWidget(IconFile1_2);


        DirectoryGrid->addLayout(File1_7, 0, 4, 1, 1);

        Folder1 = new QVBoxLayout();
        Folder1->setObjectName("Folder1");
        Folder1_icon = new QLabel(GirdFrame);
        Folder1_icon->setObjectName("Folder1_icon");
        Folder1_icon->setMaximumSize(QSize(100, 100));
        Folder1_icon->setStyleSheet(QString::fromUtf8("padding-top: 12px;\n"
"padding-bottom: 6px;\n"
"margin: 5px;"));
        Folder1_icon->setTextFormat(Qt::RichText);
        Folder1_icon->setPixmap(QPixmap(QString::fromUtf8("C:/Users/LENOVO/Downloads/folder (1).png")));
        Folder1_icon->setScaledContents(true);
        Folder1_icon->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        Folder1_icon->setMargin(0);

        Folder1->addWidget(Folder1_icon);


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


        DirectoryGrid->addLayout(File1_13, 2, 4, 1, 1);

        Folder3 = new QVBoxLayout();
        Folder3->setObjectName("Folder3");
        Folder3_icon = new QLabel(GirdFrame);
        Folder3_icon->setObjectName("Folder3_icon");
        Folder3_icon->setMaximumSize(QSize(100, 100));
        Folder3_icon->setStyleSheet(QString::fromUtf8("padding-top: 12px;\n"
"padding-bottom: 6px;\n"
"margin: 5px;"));
        Folder3_icon->setTextFormat(Qt::RichText);
        Folder3_icon->setPixmap(QPixmap(QString::fromUtf8("C:/Users/LENOVO/Downloads/folder (1).png")));
        Folder3_icon->setScaledContents(true);
        Folder3_icon->setMargin(0);

        Folder3->addWidget(Folder3_icon);


        DirectoryGrid->addLayout(Folder3, 0, 2, 1, 1);

        Folder2 = new QVBoxLayout();
        Folder2->setObjectName("Folder2");
        Folder2_icon = new QLabel(GirdFrame);
        Folder2_icon->setObjectName("Folder2_icon");
        Folder2_icon->setMaximumSize(QSize(100, 100));
        Folder2_icon->setStyleSheet(QString::fromUtf8("padding-top: 12px;\n"
"padding-bottom: 6px;\n"
"margin: 5px;"));
        Folder2_icon->setTextFormat(Qt::RichText);
        Folder2_icon->setPixmap(QPixmap(QString::fromUtf8("C:/Users/LENOVO/Downloads/folder (1).png")));
        Folder2_icon->setScaledContents(true);
        Folder2_icon->setMargin(0);

        Folder2->addWidget(Folder2_icon);


        DirectoryGrid->addLayout(Folder2, 0, 1, 1, 1);

        File1_24 = new QVBoxLayout();
        File1_24->setObjectName("File1_24");
        IconFile1_19 = new QLabel(GirdFrame);
        IconFile1_19->setObjectName("IconFile1_19");
        IconFile1_19->setMaximumSize(QSize(100, 100));
        IconFile1_19->setStyleSheet(QString::fromUtf8("padding-top: 10px;\n"
"padding-bottom: 6px;\n"
"margin: 14px;"));
        IconFile1_19->setTextFormat(Qt::RichText);
        IconFile1_19->setPixmap(QPixmap(QString::fromUtf8("C:/Users/LENOVO/Downloads/document.png")));
        IconFile1_19->setScaledContents(true);
        IconFile1_19->setMargin(0);

        File1_24->addWidget(IconFile1_19);


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


        DirectoryGrid->addLayout(File1_26, 5, 0, 1, 1);

        HSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        DirectoryGrid->addItem(HSpacer, 0, 5, 1, 1);

        File1 = new QVBoxLayout();
        File1->setObjectName("File1");
        File1_icon = new QLabel(GirdFrame);
        File1_icon->setObjectName("File1_icon");
        File1_icon->setMaximumSize(QSize(100, 100));
        File1_icon->setStyleSheet(QString::fromUtf8("padding-top: 10px;\n"
"padding-bottom: 6px;\n"
"margin: 14px;"));
        File1_icon->setTextFormat(Qt::RichText);
        File1_icon->setPixmap(QPixmap(QString::fromUtf8("C:/Users/LENOVO/Downloads/document.png")));
        File1_icon->setScaledContents(true);
        File1_icon->setMargin(0);

        File1->addWidget(File1_icon);


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


        DirectoryGrid->addLayout(File1_28, 1, 0, 1, 1);


        verticalLayout->addLayout(DirectoryGrid);


        verticalLayout_2->addWidget(GirdFrame);

        scrollArea->setWidget(Contents);
        exitButton = new QPushButton(MainWidget);
        exitButton->setObjectName("exitButton");
        exitButton->setGeometry(QRect(10, 520, 221, 31));
        exitButton->setStyleSheet(QString::fromUtf8("font: 600 10pt \"UTM Avo\";\n"
"border: 1px solid rgb(194, 231, 255);\n"
"background-color: #ffffff;\n"
"border-radius: 5px;\n"
""));
        backButton = new QPushButton(MainWidget);
        backButton->setObjectName("backButton");
        backButton->setGeometry(QRect(240, 10, 41, 31));
        backButton->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 132, 255);\n"
"border: 1px #000000;\n"
"border-radius: 5px;\n"
"padding: 0 7px 4px 0px;\n"
"font: 600 11pt \"UTM Avo\";"));
        Filler = new QLabel(MainWidget);
        Filler->setObjectName("Filler");
        Filler->setGeometry(QRect(275, 10, 16, 31));
        Filler->setStyleSheet(QString::fromUtf8("background-color: rgb(194, 231, 255);\n"
"border: 1px #000000;\n"
"font: 600 11pt \"UTM Avo\";\n"
"border-radius: 0;"));
        treeView->raise();
        TreeView->raise();
        scrollArea->raise();
        exitButton->raise();
        backButton->raise();
        Path->raise();
        Filler->raise();

        retranslateUi(fileExplorer);

        QMetaObject::connectSlotsByName(fileExplorer);
    } // setupUi

    void retranslateUi(QWidget *fileExplorer)
    {
        fileExplorer->setWindowTitle(QCoreApplication::translate("fileExplorer", "Form", nullptr));
        TreeView->setText(QCoreApplication::translate("fileExplorer", "Tree View", nullptr));
        Path->setText(QCoreApplication::translate("fileExplorer", "D:\\Folder2", nullptr));
        IconFile1_20->setText(QString());
        IconFile1_4->setText(QString());
        IconFile1_5->setText(QString());
        IconFile1_7->setText(QString());
        IconFile1_2->setText(QString());
        Folder1_icon->setText(QString());
        IconFile1_22->setText(QString());
        IconFile1_8->setText(QString());
        Folder3_icon->setText(QString());
        Folder2_icon->setText(QString());
        IconFile1_19->setText(QString());
        IconFile1_6->setText(QString());
        IconFile1_21->setText(QString());
        File1_icon->setText(QString());
        IconFile1_23->setText(QString());
        exitButton->setText(QCoreApplication::translate("fileExplorer", "Exit", nullptr));
        backButton->setText(QCoreApplication::translate("fileExplorer", "<", nullptr));
        Filler->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class fileExplorer: public Ui_fileExplorer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILEEXPLORER_H
