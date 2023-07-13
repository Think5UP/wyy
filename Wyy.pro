QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

LIBS += -ldwmapi

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    loadQss.cpp \
    main.cpp \
    mainwindow.cpp \
    myslider.cpp \
    mywidget.cpp \
    personform.cpp \
    playlist.cpp \
    toolbox.cpp \
    toolpage.cpp

win32{
        SOURCES += \
                framelesswindow.cpp
}

HEADERS += \
    loadQss.h \
    mainwindow.h \
    myslider.h \
    mywidget.h \
    framelesswindow.h \
    personform.h \
    playlist.h \
    toolbox.h \
    toolpage.h

FORMS += \
    mainwindow.ui \
    personform.ui \
    playlist.ui \
    toolbox.ui \
    toolpage.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
