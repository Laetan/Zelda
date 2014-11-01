#include <QApplication>
#include <QGraphicsView>
#include <gamescene.h>

#include "Model/element.h"
#include "Model/Character/personnage.h"
#include "Model/Character/zelda.h"
#include <QtDebug>

int main( int argc, char **argv )
{
    QApplication app(argc, argv);
    QGraphicsView *view = new QGraphicsView();
    GameScene *scene = new GameScene(0,0,900,736,view);
    view->setScene(scene);

    // Instancier un objet Zelda



    view->show();

    return app.exec();

}
