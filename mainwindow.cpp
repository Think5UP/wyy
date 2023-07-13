#include <windows.h>

#include <QFile>
#include <QDebug>
#include <QDesktopWidget>

#include "toolbox.h"
#include "myslider.h"
#include "toolpage.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : CFramelessWindow(parent),
      ui(new Ui::MainWindow),
      maxForm_(false),
      mute_(false),
      personPage_(nullptr)
{
    ui->setupUi(this);
    ui->btn_maximize->setProperty("is_maximum", false);
    ui->btn_volume->setProperty("is_mute", mute_);
    this->setWindowTitle("网易云音乐");
    this->setWindowIcon(QIcon(":/images/logo.ico"));
    setWindowFlags(windowFlags() | Qt::Window | Qt::FramelessWindowHint | Qt::WindowSystemMenuHint);
    this->setAttribute(Qt::WA_TranslucentBackground);

    setResizeableAreaWidth(8);
    setTitleBar(ui->move_widget);
    QFile fileQss(":/bin/main.qss");
    bool isOpen = fileQss.open(QFile::ReadOnly);
    qApp->setStyleSheet(fileQss.readAll());
    fileQss.close();
    initMenu();

    ui->progressSlider->installEventFilter(this);

    connect(this->ui->move_widget, SIGNAL(doubleClickHappend()), this, SLOT(on_btn_maximize_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initMenu()
{
    ui->listWidget->setSelectionMode(QListWidget::ExtendedSelection);
    ui->listWidget_2->setSelectionMode(QListWidget::ExtendedSelection);

    btn_recommend_ = new QPushButton(this);
    btn_jingxuan_ = new QPushButton(this);
    btn_boke_ = new QPushButton(this);
    btn_community_ = new QPushButton(this);
    btn_myLikeMusic_ = new QPushButton(this);
    btn_RecPlayed_  = new QPushButton(this);
    btn_myBoke_  = new QPushButton(this);
    btn_myFavorites_  = new QPushButton(this);
    btn_downloadMag_  = new QPushButton(this);
    btn_localMusic_  = new QPushButton(this);

    QListWidgetItem* item = new QListWidgetItem("为你推荐");
    QListWidgetItem* item2 = new QListWidgetItem("云音乐精选");
    QListWidgetItem* item3 = new QListWidgetItem("播客");
    QListWidgetItem* item4 = new QListWidgetItem("社区");
    QListWidgetItem* item5 = new QListWidgetItem("我喜欢的音乐");
    QListWidgetItem* item6 = new QListWidgetItem("最近播放");
    QListWidgetItem* item7 = new QListWidgetItem("我的播客");
    QListWidgetItem* item8 = new QListWidgetItem("我的收藏");
    QListWidgetItem* item9 = new QListWidgetItem("下载管理");
    QListWidgetItem* item10 = new QListWidgetItem("本地音乐");

    item->setSizeHint(QSize(135, 40));
    item2->setSizeHint(QSize(135, 40));
    item3->setSizeHint(QSize(135, 40));
    item4->setSizeHint(QSize(135, 40));
    item5->setSizeHint(QSize(135, 40));
    item6->setSizeHint(QSize(135, 40));
    item7->setSizeHint(QSize(135, 40));
    item8->setSizeHint(QSize(135, 40));
    item9->setSizeHint(QSize(135, 40));
    item10->setSizeHint(QSize(135, 40));
    ui->listWidget->addItem(item);
    ui->listWidget->addItem(item2);
    ui->listWidget->addItem(item3);
    ui->listWidget->addItem(item4);

    ui->listWidget_2->addItem(item5);
    ui->listWidget_2->addItem(item6);
    ui->listWidget_2->addItem(item7);
    ui->listWidget_2->addItem(item8);
    ui->listWidget_2->addItem(item9);
    ui->listWidget_2->addItem(item10);
    ui->listWidget->setItemWidget(item, btn_recommend_);
    ui->listWidget->setItemWidget(item2, btn_jingxuan_);
    ui->listWidget->setItemWidget(item3, btn_boke_);
    ui->listWidget->setItemWidget(item4, btn_community_);
    ui->listWidget_2->setItemWidget(item5, btn_myLikeMusic_);
    ui->listWidget_2->setItemWidget(item6, btn_RecPlayed_);
    ui->listWidget_2->setItemWidget(item7, btn_myBoke_);
    ui->listWidget_2->setItemWidget(item8, btn_myFavorites_);
    ui->listWidget_2->setItemWidget(item9, btn_downloadMag_);
    ui->listWidget_2->setItemWidget(item10, btn_localMusic_);
    connect(ui->listWidget, &QListWidget::itemSelectionChanged, this, &MainWindow::onListWidget2ItemSelectionChanged);
    connect(ui->listWidget_2, &QListWidget::itemSelectionChanged, this, &MainWindow::onListWidgetItemSelectionChanged);
    ui->listWidget->setCurrentRow(0);

}

// 跟踪鼠标移动
void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    // 获取当前可移动区域的高度
    int titleHight = ui->move_widget->height();
    // 事件发生位置和记录高度对比
    if(event->y() < titleHight)
    {
        // 记录位置移动
        int dx = event->globalX() - last_.x();
        int dy = event->globalY() - last_.y();
        last_ = event->globalPos();
        this->move(this->x() + dx, this->y() + dy);
    }
}

//
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    int titleHeight = ui->move_widget->height();
    if(event->y() <titleHeight)
    {
        // 记录点击位置
        last_ = event->globalPos(); //获取到按压的位置
    }
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    int currentW = this -> size().width(); // 用以记录当前窗体宽度
    int currentH = this -> size().height(); // 用以记录当前窗体高度

    int scrollAreaWidget = ui->scrollArea->size().width();
    int broadcastHeight = ui->broadcast_widget->size().height();
    int titleHeight = ui->title_widget->size().height();
    ui->move_widget->resize(currentW, ui->move_widget->height());
    ui->title_widget->resize(currentW - scrollAreaWidget, titleHeight);
    ui->scrollArea->setGeometry(0, 0, scrollAreaWidget, currentH - broadcastHeight);
    ui->broadcast_widget->setGeometry(0, ui->scrollArea->size().height(), currentW, broadcastHeight);
    ui->page_stackedWidget->setGeometry(scrollAreaWidget, titleHeight, currentW - scrollAreaWidget, currentH - broadcastHeight - titleHeight);
}

void MainWindow::on_btn_close_clicked()
{
    close();
}


void MainWindow::on_btn_maximize_clicked()
{
    if(!maxForm_)
    {
        this->showMaximized();
    }
    else
    {
        this->showNormal();
    }
    maxForm_ = !maxForm_;
    ui->btn_maximize->setProperty("is_maximum", maxForm_);
    ui->btn_maximize->style()->unpolish(ui->btn_maximize);
    ui->btn_maximize->style()->polish(ui->btn_maximize);
    ui->btn_maximize->update();
}


void MainWindow::on_btn_minimize_clicked()
{
    this->showMinimized();
}

void MainWindow::onListWidgetItemSelectionChanged()
{
    {
        QSignalBlocker blocker(ui->listWidget);
        ui->listWidget->clearSelection();
    }
    // ui->listWidget->setCurrentRow(-1);
}

void MainWindow::onListWidget2ItemSelectionChanged()
{
    {
        QSignalBlocker blocker(ui->listWidget_2);
        ui->listWidget_2->clearSelection();
    }
    // ui->listWidget_2->setCurrentRow(0);
    // ui->listWidget_2->selec;
}




void MainWindow::on_btn_name_clicked()
{
    if(personPage_)
    {
        if(personPage_->isHidden())
        {
            personPage_->show();
        }
        else {
            personPage_->hide();
        }
    }
    else
    {
        personPage_ = new personForm(this);
        personPage_->show();
    }
    int posX = this->geometry().left() + ui->btn_name->geometry().left();
    int posY = this->geometry().top() + ui->btn_name->geometry().bottom() + 20;
    personPage_->setStyleSheet("personForm {border-radius: 10px;}");
    personPage_->move(posX, posY);
}


void MainWindow::on_btn_volume_clicked()
{
    mute_ = !mute_;
    ui->btn_volume->setProperty("is_mute", mute_);
    ui->btn_volume->style()->unpolish(ui->btn_volume);
    ui->btn_volume->style()->polish(ui->btn_volume);
    ui->btn_volume->update();
    if(mute_)
    {
        ui->volumlSlider->setVal(ui->volumlSlider->value());
        ui->volumlSlider->setValue(0);
        return;
    }
    ui->volumlSlider->setValue(ui->volumlSlider->getVal());
}

