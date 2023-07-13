#ifndef MYSLIDER_H
#define MYSLIDER_H

#include <QObject>
#include <QSlider>

class MySlider : public QSlider
{
public:
    explicit MySlider(QWidget *parent = nullptr);
    ~MySlider();

    void mousePressEvent(QMouseEvent *event) override;

    void setVal(int val);
    int getVal() const;

private:
    int savedVal_;
};

#endif // MYSLIDER_H
