#include <QApplication>
#include <QGraphicsView>
#include <basicscene.h>

#include <element.h>
#include <personnage.h>
#include <zelda.h>
#include   <QtDebug>

int main( int argc, char **argv )
{
    QApplication app(argc, argv);
    QGraphicsView *view = new QGraphicsView();
    BasicScene *scene = new BasicScene(0,0,600,600,view);
    view->setScene(scene);

    // Instancier un objet Zelda



    view->show();

    return app.exec();

}
