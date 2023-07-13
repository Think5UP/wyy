#include <QMouseEvent>

#include "myslider.h"

MySlider::MySlider(QWidget *parent)
    : QSlider(parent),
      savedVal_(0)
{

}

MySlider::~MySlider()
{

}

void MySlider::mousePressEvent(QMouseEvent *event)
{
    // 获取点击位置
    int curPosX = event->pos().x();
    // 获取点击位置的百分比
    double percen = curPosX * 1.0 / this->width();
    // 计算点击位置的值
    int value = percen * (this->maximum() - this->minimum()) + this->minimum();

    this->setValue(value);

    QSlider::mousePressEvent(event);
}

void MySlider::setVal(int val)
{
    savedVal_ = val;
}

int MySlider::getVal() const
{
    return savedVal_;
}
