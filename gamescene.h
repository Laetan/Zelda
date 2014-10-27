#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QGraphicsScene>
#include "spritesheet.h"
#include "world.h"

class GameScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit GameScene(QObject *parent = 0);

private:
    QList<QList<int> > envData;
    SpriteSheetManager envSS;
    World world;
    void loadStage(QString);
    void drawStage();
signals:

public slots:

};

#endif // GAMESCENE_H
