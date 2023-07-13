#include "mywidget.h"

MyWidget::MyWidget(QWidget *parent) : QWidget(parent)
{
    setAttribute(Qt::WA_StyledBackground,true);
}

void MyWidget::mouseDoubleClickEvent(QMouseEvent *event)
{
    emit doubleClickHappend();
}
