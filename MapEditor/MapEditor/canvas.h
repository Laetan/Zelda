#ifndef CANVAS_H
#define CANVAS_H
#define ZONE_WIDTH_MAX 30
#define ZONE_HEIGTH_MAX 23
#define SPRITE_WIDTH 32
#define SPRITE_HEIGTH 32
#include "grid.h"
#include "spritesheet.h"
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QPointF>


typedef QList<QList<QPixmap> > Picto;
class Palette : public QGraphicsScene
{
    Q_OBJECT


public:
    //explicit Palette(QObject *parent = 0);
    Palette(int,int,int,int,QObject *parent = 0);
    const QString getSelectedPixRef();
    int getCurrentPalette();
    enum PaletteState{
        ENVIRONNEMENT,
        ELEMENT
    };
    class Pic : public QGraphicsRectItem{
    public:
        explicit Pic(int,QString,QPixmap&, Palette*);
    private:
        Palette *palette;
        void mousePressEvent(QGraphicsSceneMouseEvent*);
    };

private:

    QGraphicsRectItem *selection;
    QList<Palette::Pic*> picLabels;
    QString selectedPixRef;
    QHash<QString,QPixmap> pixmaps;
    SpriteSheetManager ssm, elemSS;
    int currentPalette;
    void changeSelection(Palette::Pic*);
    void getPics(SpriteSheetManager*);
    void drawPics();
public slots:
    void changePaletteToElement();
    void changePaletteToEnvironement();

};

class Canvas : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit Canvas(QObject *parent = 0);
    Canvas(int,int,int,int,QObject *parent = 0);
    void setPalette(Palette*);

private:
    void mousePressEvent(QGraphicsSceneMouseEvent*);
    void mouseMoveEvent(QGraphicsSceneMouseEvent*);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent*);
    void mouseAction(QPointF, Qt::MouseButton);
    void drawCanvas();
    bool addElement(QPointF , QString);
    bool delElement(QPointF);
    bool addEnv(QPointF , Qt::MouseButton , QString);
    bool painting;
    Palette* palette;
    SpriteSheetManager ssm, elemSS;
    Grid *grid;
    QList<QList<QString> > data;
    QList<QList<QString> >elemData;
    QList<QGraphicsPixmapItem*> elemList;

signals:

public slots:
    void save();
    void load();
    void clearAll();

};

#endif // CANVAS_H
