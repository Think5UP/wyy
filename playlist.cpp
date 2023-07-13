#include "playlist.h"
#include "ui_playlist.h"

playList::playList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::playList)
{
    ui->setupUi(this);
}

playList::~playList()
{
    delete ui;
}
