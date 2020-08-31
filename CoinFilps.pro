#-------------------------------------------------
#
# Project created by QtCreator 2020-08-29T21:46:41
#
#-------------------------------------------------

QT       += core gui
QT       +=multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CoinFilps
TEMPLATE = app


SOURCES += main.cpp\
        mymainwindow.cpp \
    startscene.cpp \
    mypushbotton.cpp \
    levelselectscene.cpp \
    playscene.cpp \
    coinbutton.cpp \
    dataconfig.cpp

HEADERS  += mymainwindow.h \
    startscene.h \
    mypushbotton.h \
    levelselectscene.h \
    playscene.h \
    coinbutton.h \
    dataconfig.h

FORMS    += mymainwindow.ui

RESOURCES += \
    res/res.qrc
