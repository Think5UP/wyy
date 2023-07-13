#include "personform.h"
#include "ui_personform.h"

#include <QUrl>
#include <QFont>
#include <QStyle>
#include <QMouseEvent>
#include <QPushButton>
#include <QDesktopServices>


personForm::personForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::personForm)
{
    ui->setupUi(this);
    // 设置当点击外部关闭当前窗口
    this->setWindowFlags(Qt::Popup);
    setAttribute(Qt::WA_StyledBackground);

    ui->btn_sign->setProperty("is_signed", false);

    QFont font("JetBrains Mono", 16);
    ui->attention_label->setFont(font);
    ui->attention_label->setText("0");
    ui->attention_label->setAlignment(Qt::AlignCenter);
    ui->dynamic_label->setFont(font);
    ui->dynamic_label->setText("0");
    ui->dynamic_label->setAlignment(Qt::AlignCenter);
    ui->fans_label->setFont(font);
    ui->fans_label->setText("0");
    ui->fans_label->setAlignment(Qt::AlignCenter);
}

personForm::~personForm()
{
    delete ui;
}

void personForm::mousePressEvent(QMouseEvent *event)
{
    // 弹出小部件关闭时不应重播最近的鼠标按下事件
    this->setAttribute(Qt::WA_NoMouseReplay);
    QWidget::mousePressEvent(event);
}

void personForm::on_btn_vipInfo_clicked()
{
     QDesktopServices::openUrl(QUrl(QString("https://music.163.com/#/member?refer=myvipweb")));
}


void personForm::on_btn_levelInfo_clicked()
{
    QDesktopServices::openUrl(QUrl(QString("https://music.163.com/#/user/level")));
}


void personForm::on_btn_store_clicked()
{
    QDesktopServices::openUrl(QUrl(QString("https://music.163.com/store/product")));
}


void personForm::on_btn_personInfo_clicked()
{
    QDesktopServices::openUrl(QUrl(QString("https://music.163.com/#/user/update")));
}


void personForm::on_btn_bind_clicked()
{
}


void personForm::on_btn_service_clicked()
{
}


void personForm::on_btn_logout_clicked()
{

}


void personForm::on_btn_sign_clicked()
{
    ui->btn_sign->setProperty("is_signed", true);
    ui->btn_sign->style()->unpolish(ui->btn_sign);
    ui->btn_sign->style()->polish(ui->btn_sign);
    ui->btn_sign->update();
    ui->btn_sign->setCursor(Qt::ForbiddenCursor);
}

