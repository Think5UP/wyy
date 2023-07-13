#include "toolbox.h"
#include "ui_toolbox.h"
#include "toolpage.h"

#include <QVBoxLayout>

ToolBox::ToolBox(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ToolBox),
    contentVBoxLayout_(nullptr)
{
    ui->setupUi(this);

    QWidget *widget = new QWidget(this);
    contentVBoxLayout_ = new QVBoxLayout;
    contentVBoxLayout_->setContentsMargins(0, 0, 0, 0);
    contentVBoxLayout_->setSpacing(2);

    QVBoxLayout *vBoxLayout = new QVBoxLayout(widget);
    vBoxLayout->setContentsMargins(0, 0, 0, 0);
    vBoxLayout->addLayout(contentVBoxLayout_);
    vBoxLayout->addStretch(1);
}

ToolBox::~ToolBox()
{
    delete ui;
}

void ToolBox::addWidget(const QString &title, QWidget *widget)
{
    ToolPage *page = new ToolPage(this);
    page->addWidget(title, widget);

    contentVBoxLayout_->addWidget(page);
}
