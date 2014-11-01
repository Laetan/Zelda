#include <QApplication>
#include <QGraphicsView>
#include <basicscene.h>
#include <QtDebug>

#include <element.h>
#include <personnage.h>
#include <zelda.h>
#include "IntroScene.h"


int main( int argc, char **argv )
{
    QApplication app(argc, argv);
    QGraphicsView *view = new QGraphicsView();
//    QGraphicsView *viewIntro = new QGraphicsView();
    IntroScene *sceneIntro = new IntroScene(0,0,926,724,view);
    BasicScene *scene = new BasicScene(0,0,600,600,view);

    view->setScene(scene);
    view->setScene(sceneIntro);


    // Instancier un objet zzd

    view->show();



    return app.exec();

}
