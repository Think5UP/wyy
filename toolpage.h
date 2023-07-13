#ifndef TOOLPAGE_H
#define TOOLPAGE_H

#include <QWidget>
#include <QPropertyAnimation>

namespace Ui {
class ToolPage;
}

class QFormLayout;
class QLabel;
class ToolPage : public QWidget
{
    Q_OBJECT

public:
    explicit ToolPage(QWidget *parent = nullptr);
    ~ToolPage();

public slots:
    void addWidget(const QString &title, QWidget *widget);
    void updateWidget(const QString &title);

private slots:
    void onPushButtonFoldClicked();

private:

    void updateCollapsedState();
    void animationFinished();
    void expand();
    void collapse();

private:
    Ui::ToolPage *ui;

    bool isExpanded_;
    QPropertyAnimation *animation_;
};

#endif // TOOLPAGE_H
