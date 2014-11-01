#-------------------------------------------------
#
# Project created by QtCreator 2014-10-22T14:48:52
#
#-------------------------------------------------

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Zelda
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
        gamescene.cpp\
        spritefinder.cpp \
        spritesheetmanager.cpp \
        world.cpp \
        Model/Item/Objets.cpp \
        Model/Character/personnage.cpp \
        Model/Character/zelda.cpp \
        Model/element.cpp \
        Model/Character/Monster/monster.cpp \
        Model/Item/arrow.cpp

HEADERS  += mainwindow.h \
        gamescene.h\
        spritesheet.h \
        world.h \
        Model/Item/Objets.h \
        Model/Character/personnage.h \
        Model/Character/zelda.h \
        Model/element.h \
        Model/Character/Monster/monster.h \
        Model/Item/arrow.h

FORMS    += mainwindow.ui
