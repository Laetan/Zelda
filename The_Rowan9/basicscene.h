#ifndef BASICSCENE_H
#define BASICSCENE_H

#include <QGraphicsScene>
#include <QTimer>
#include "zelda.h"

class BasicScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit BasicScene(QObject *parent = 0);
    BasicScene(int,int,int,int,QObject *parent = 0);
private:
    QTimer *timer;
    Zelda *zelda;
    void keyPressEvent(QKeyEvent *event);
signals:

public slots:
    void update();

};

#endif // BASICSCENE_H
