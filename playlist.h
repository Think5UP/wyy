#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <QWidget>

namespace Ui {
class playList;
}

class playList : public QWidget
{
    Q_OBJECT

public:
    explicit playList(QWidget *parent = nullptr);
    ~playList();

private:
    Ui::playList *ui;
};

#endif // PLAYLIST_H
