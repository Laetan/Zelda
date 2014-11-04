#include "mainwindow.h"
#include "savewindow.h"
#include <QApplication>
#include "spritesheet.h"
#include <QtDebug>
#include <QList>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setFixedSize(1200,756);


    w.show();

    return a.exec();
}
