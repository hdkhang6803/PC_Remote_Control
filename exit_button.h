#ifndef EXIT_BUTTON_H
#define EXIT_BUTTON_H

#include <QMainWindow>
#include <QTcpSocket>
namespace Ui {
class exit_button;
}

class exit_button : public QMainWindow
{
    Q_OBJECT

public:
    explicit exit_button(QWidget *parent = nullptr);
    ~exit_button();

private slots:
    void on_pushButton_clicked();


private:
    Ui::exit_button *ui;
};

#endif // EXIT_BUTTON_H
