#ifndef INTROSCENE_H
#define INTROSCENE_H

#include <QGraphicsScene>
#include <QString>
#include <QTime>
#include <QKeyEvent>
#include <QGraphicsView>


class IntroScene : public QGraphicsScene
{
    Q_OBJECT
public:
    IntroScene(int, int, int, int, QObject *parent = 0);
    void display(QString);
    void close(QGraphicsView);

private:
    void keyPressEvent(QKeyEvent *event);
};

#endif // INTROSCENE_H
