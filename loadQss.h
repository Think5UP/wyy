#ifndef LOADQSS_H
#define LOADQSS_H

#include <QFile>
#include <QtDebug>
#include <QObject>
#include <QApplication>

class LoadQss : public QObject
{
    Q_OBJECT
public:
    LoadQss(QObject *parent = nullptr);

    static LoadQss *loader;

    static LoadQss *getInstance()
    {
        if(nullptr == loader)
        {
            loader = new LoadQss;
        }
        return loader;
    }

    bool loadFromFile(const QString &file);

private:


    LoadQss(const LoadQss &) = delete;
    LoadQss &operator=(const LoadQss &) = delete;

    ~LoadQss() {}
};

#endif // LOADQSS_H
