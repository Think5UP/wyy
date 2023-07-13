#include "loadQss.h"


LoadQss::LoadQss(QObject *parent)
    : QObject{parent}
{

}

bool LoadQss::loadFromFile(const QString &file)
{
    QFile fileQss(file);
    bool isOpen = fileQss.open(QFile::ReadOnly);
    qDebug() << isOpen;
    qApp->setStyleSheet(fileQss.readAll());
    fileQss.close();
    return isOpen;
}
