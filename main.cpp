
#include "fileExplorer.h".h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    fileExplorer w;
    w.show();
    return a.exec();
}
