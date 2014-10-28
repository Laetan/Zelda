#-------------------------------------------------
#
# Project created by QtCreator 2014-10-28T17:38:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TP_Zelda
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    element.cpp \
    monster.cpp \
    personnage.cpp \
    zelda.cpp

HEADERS  += mainwindow.h \
    ../Zelda/element.h \
    ../Zelda/monster.h \
    ../Zelda/personnage.h \
    ../Zelda/zelda.h \
    element.h \
    monster.h \
    personnage.h \
    zelda.h

FORMS    += mainwindow.ui
