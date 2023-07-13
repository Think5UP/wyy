#ifndef PERSONFORM_H
#define PERSONFORM_H

#include <QWidget>

namespace Ui {
class personForm;
}

class personForm : public QWidget
{
    Q_OBJECT

public:
    explicit personForm(QWidget *parent = nullptr);
    ~personForm();

protected:
    void mousePressEvent(QMouseEvent *event) override;

private slots:
    void on_btn_vipInfo_clicked();

    void on_btn_levelInfo_clicked();

    void on_btn_store_clicked();

    void on_btn_personInfo_clicked();

    void on_btn_bind_clicked();

    void on_btn_service_clicked();

    void on_btn_logout_clicked();

    void on_btn_sign_clicked();

private:
    Ui::personForm *ui;
};

#endif // PERSONFORM_H
