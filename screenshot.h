#ifndef SCREENSHOT_H
#define SCREENSHOT_H

#include <QWidget>

namespace Ui {
class screenshot;
}

class screenshot : public QWidget
{
    Q_OBJECT

signals:
    void capture();
    void save();
    void end_session();

private slots:
    void m_on_saveButton_clicked();
    void m_on_captureButton_clicked();
    void m_on_exitButton_clicked();
public:
    explicit screenshot(QWidget *parent = nullptr);
    void display_image(QByteArray& img_byte);
    ~screenshot();

private:
    Ui::screenshot *ui;
};

#endif // SCREENSHOT_H
