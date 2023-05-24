#include "screendisplayer.h"
#include "fileexplorer.h"
#include "audiorecorder.h"
#include "screenshot.h"
#include "keystroke.h"
#include "clientwindow1.h"
#include "serverinfo.h"
#include "clientinfo.h"
#include <QApplication>
#include "apps.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    serverInfo w1;
    clientInfo w2;
    clientWindow1 w3;
    apps w4;
    keystroke w5;
    screenshot w6;
    fileExplorer w7;
    screendisplayer w8;
    audiorecorder w9;

//    connectDialog2 w;
//    MainWindow w;
    w1.show();
    w2.show();
    w3.show();
    w4.show();
    w5.show();
    w6.show();
    w7.show();
    w8.show();
    w9.show();

    return a.exec();
}
