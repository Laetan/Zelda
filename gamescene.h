#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include "spritesheet.h"
#include "Model/Character/zelda.h"
#include "Model/Character/Monster/monster.h"
#include "Model/Item/projectile.h"
#include "world.h"

class GameScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit GameScene(QObject *parent = 0);
    GameScene(int,int,int,int,QObject *parent = 0);

    void remove(Monster*);
    void remove(Projectile*);
    void remove(Element*);

    QList<QList<int> > getEnvData() const;
    void setEnvData(const QList<QList<int> > &value);

private:
    QList<QList<int> > envData;
    SpriteSheetManager envSS;
    World world;
    QTimer *timer;
    Zelda *zelda;

    QList<Monster*> monsterList;
    QList<Projectile*> projectList;
    void keyPressEvent(QKeyEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent*);
    void loadStage(QString);
    void drawStage();
    void keyReleaseEvent(QKeyEvent *event);
signals:

public slots:
    void update();
};

#endif // GAMESCENE_H
