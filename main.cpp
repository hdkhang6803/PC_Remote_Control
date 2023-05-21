
//#include "clientwindow2.h"
//#include "clientinfo.h"
//#include "screendisplayer.h"
//#include "connectDialog2.h"
//#include "mainWindow.h"
#include "fileexplorer.h"
//#include "audiorecorder.h"
//#include "screenshot.h"
//#include "keystroke.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    fileExplorer w;
//    connectDialog2 w;
//    MainWindow w;
    w.show();
    return a.exec();
}
