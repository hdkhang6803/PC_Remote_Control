#ifndef KEYSTROKE_H
#define KEYSTROKE_H

#include <QWidget>

namespace Ui {
class keystroke;
}

class keystroke : public QWidget
{
    Q_OBJECT

signals:
    void start_hook();
    void end_hook();
    void end_session_stroke();
private slots:
    void m_on_clear_clicked();
    void m_on_start_clicked();
    void m_on_exit_clicked();


public:
    explicit keystroke(QWidget *parent = nullptr);
    ~keystroke();
    void display_stroke(QString& str1, QString& str2);

private:
    Ui::keystroke *ui;
    bool is_running_flag = 0;
};

#endif // KEYSTROKE_H
