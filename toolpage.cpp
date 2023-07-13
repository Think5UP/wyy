#include "toolpage.h"
#include "ui_toolpage.h"


ToolPage::ToolPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ToolPage),
    isExpanded_(false)
{
    ui->setupUi(this);
    ui->widget->setAttribute(Qt::WA_StyledBackground);
    connect(ui->pushButton, &QPushButton::clicked, this, &ToolPage::onPushButtonFoldClicked);
}

ToolPage::~ToolPage()
{
    delete ui;
}

void ToolPage::addWidget(const QString &title, QWidget *widget)
{
    ui->pushButton->setText(title);
    ui->verticalLayoutContent->addWidget(widget);
    ui->pushButton->setProperty("expand", false);
}

void ToolPage::updateWidget(const QString &title)
{
    ui->pushButton->setText(title);
}

void ToolPage::expand()
{
    if(animation_)
        return;
    ui->widget->setVisible(true);
    animation_ = new QPropertyAnimation(ui->widget, "maximumHeight");
    animation_->setDuration(300);
    animation_->setStartValue(0);
    animation_->setEndValue(ui->widget->sizeHint().height());
    animation_->setEasingCurve(QEasingCurve::OutQuad);
    connect(animation_, &QPropertyAnimation::finished, this, &ToolPage::animationFinished);
    animation_->start();
}

void ToolPage::collapse()
{
    if(animation_)
        return;
    ui->widget->setVisible(true);
    animation_ = new QPropertyAnimation(ui->widget, "maximumHeight");
    animation_->setDuration(300);
    animation_->setStartValue(ui->widget->sizeHint().height());
    animation_->setEndValue(0);
    animation_->setEasingCurve(QEasingCurve::OutQuad);
    connect(animation_, &QPropertyAnimation::finished, this, &ToolPage::animationFinished);
    animation_->start();
}

void ToolPage::onPushButtonFoldClicked()
{
    isExpanded_ = !isExpanded_;
    if(isExpanded_)
    {
        expand();
    }
    else
    {
        collapse();
    }
}

void ToolPage::updateCollapsedState()
{
    ui->widget->setVisible(isExpanded_);
}

void ToolPage::animationFinished()
{
    if(!isExpanded_)
    {
        ui->widget->setVisible(false);
    }
    delete animation_;
    animation_ = nullptr;
}
