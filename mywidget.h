#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QMouseEvent>

class MyWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MyWidget(QWidget *parent = nullptr);
    void mouseDoubleClickEvent(QMouseEvent *event) override;

signals:
    void doubleClickHappend();

};

#endif // MYWIDGET_H
