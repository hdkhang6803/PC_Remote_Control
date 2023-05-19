#ifndef FILEEXPLORER_H
#define FILEEXPLORER_H

#include <QWidget>

namespace Ui {
class fileExplorer;
}

class fileExplorer : public QWidget
{
    Q_OBJECT

public:
    explicit fileExplorer(QWidget *parent = nullptr);
    ~fileExplorer();

private:
    Ui::fileExplorer *ui;
};

#endif // FILEEXPLORER_H
