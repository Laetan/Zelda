#-------------------------------------------------
#
# Project created by QtCreator 2014-10-19T15:13:31
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MapEditor
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    grid.cpp \
    canvas.cpp \
    spritefinder.cpp \
    spritesheetmanager.cpp \
    palette.cpp \
    savewindow.cpp

HEADERS  += mainwindow.h \
    grid.h \
    canvas.h \
    spritesheet.h \
    savewindow.h

FORMS    += mainwindow.ui \
    savewindow.ui


QMAKE_CXXFLAGS += -std=c++0x
