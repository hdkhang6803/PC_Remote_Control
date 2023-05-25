#ifndef FILENAVBUTTON_H
#define FILENAVBUTTON_H

#include <QPushButton>
#include <QMouseEvent>

#include <QDebug>

class FileNavButton : public QPushButton
{
    Q_OBJECT
public:
    explicit FileNavButton(QWidget *parent = nullptr) : QPushButton(parent) {}
    ~FileNavButton() {
        qDebug() << "deleted";
    }

    void mouseDoubleClickEvent(QMouseEvent *event) override
    {
        if (event->button() == Qt::LeftButton)
            emit doubleClicked();
    }

    void setPath(const QString &path) { m_path = path; }
    QString path() const { return m_path; }

signals:
    void doubleClicked();

private:
    QString m_path;
};

#endif // FILENAVBUTTON_H
