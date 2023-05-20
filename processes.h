#ifndef PROCESSES_H
#define PROCESSES_H

#include <QWidget>

namespace Ui {
class processes;
}

class processes : public QWidget
{
    Q_OBJECT

public:
    explicit processes(QWidget *parent = nullptr);
    ~processes();

private:
    Ui::processes *ui;
};

#endif // PROCESSES_H
