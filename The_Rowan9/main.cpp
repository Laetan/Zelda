#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QTimer>
#include <QEventLoop>
#include <QtGui>
#include <QtDebug>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QGraphicsView view;
    QGraphicsScene scene(0,0, 500, 500,&view);
    view.setScene(&scene);

    QString exePath = QCoreApplication::applicationDirPath();
    QString s = exePath  + "/Ressource/Sprites/";
    QFile file(s+"zelda.png");
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", file.errorString()+" : "+s);
    }
    file.close();
    qDebug()<<s;

    QPixmap pixmap(s+"zelda.png");

    QGraphicsPixmapItem* item = new QGraphicsPixmapItem(pixmap);
    scene.addItem(item);

    view.show();

    item->setPos(100, 100);




    return app.exec();
}
