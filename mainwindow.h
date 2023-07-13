#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QRect>
#include <QList>
#include <QMargins>
#include <QMainWindow>
#include <QMouseEvent>
#include <QPushButton>
#include <QPropertyAnimation>

#include "toolbox.h"
#include "toolpage.h"
#include "personform.h"
#include "qsystemdetection.h"
#include "framelesswindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public CFramelessWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void initMenu();
protected:
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

    void resizeEvent(QResizeEvent *event) override;

private slots:

    void on_btn_close_clicked();

    void on_btn_maximize_clicked();

    void on_btn_minimize_clicked();

    void onListWidgetItemSelectionChanged();
    void onListWidget2ItemSelectionChanged();

    void on_btn_name_clicked();

    void on_btn_volume_clicked();

private:
    Ui::MainWindow *ui;

    // 记录鼠标点击位置 实现移动窗口位置
    QPoint last_;

    bool maxForm_;
    bool mute_;

    personForm *personPage_;



    QPushButton *btn_recommend_;
    QPushButton *btn_jingxuan_;
    QPushButton *btn_boke_;
    QPushButton *btn_community_;
    QPushButton *btn_myLikeMusic_;
    QPushButton *btn_RecPlayed_;
    QPushButton *btn_myBoke_;
    QPushButton *btn_myFavorites_;
    QPushButton *btn_downloadMag_;
    QPushButton *btn_localMusic_;



};
#endif // MAINWINDOW_H
