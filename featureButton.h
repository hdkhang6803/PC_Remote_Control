
#ifndef FEATUREBUTTON_H
#define FEATUREBUTTON_H

#include <QPushButton>

#include <QWidget>


class FeatureButton : public QPushButton
{
    Q_OBJECT
public:
    using QPushButton::QPushButton;
//    explicit FeatureButton(const QString& buttonName, QWidget *parent = nullptr);
    explicit FeatureButton(QWidget *parent = nullptr);

signals:
    void clickedNumber(int i);
private slots:
    void onClicked();

private:
    int number;
public:
    void setNumber(int num);
};

#endif // FEATUREBUTTON_H
