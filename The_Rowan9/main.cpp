#include <QApplication>
#include <QGraphicsView>
#include <basicscene.h>

int main( int argc, char **argv )
{
    QApplication app(argc, argv);
    QGraphicsView *view = new QGraphicsView();
    BasicScene *scene = new BasicScene(0,0,800,800,view);
    view->setScene(scene);


    view->show();

    return app.exec();

}
