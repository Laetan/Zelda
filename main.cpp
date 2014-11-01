#include <QApplication>
#include <QGraphicsView>
#include <gamescene.h>

#include "mainwindow.h"
#include "Model/element.h"
#include "Model/Character/personnage.h"
#include "Model/Character/zelda.h"
#include <QtDebug>

int main( int argc, char **argv )
{
    qsrand(QTime::currentTime().msec());
    QApplication app(argc, argv);
//    QGraphicsView *view = new QGraphicsView();
//    GameScene *scene = new GameScene(0,0,900,736,view);
//    view->setScene(scene);

    MainWindow *w = new MainWindow();


    w->show();

    return app.exec();

}
