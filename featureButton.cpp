
#include "featureButton.h"

//FeatureButton::FeatureButton(const QString& buttonName, QWidget *parent) :
//    QPushButton(buttonName, parent)
//{
//    connect(this, &QPushButton::clicked, this, &FeatureButton::onClicked);
//}

FeatureButton::FeatureButton(QWidget *parent) :
    QPushButton(parent)
{
    connect(this, &QPushButton::clicked, this, &FeatureButton::onClicked);
}

void FeatureButton::onClicked() {
    emit clickedNumber(number);
}

void FeatureButton::setNumber(int num) {
    number = num;
}
