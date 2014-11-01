#ifndef ZELDA_H
#define ZELDA_H

#include "personnage.h"
#include <QTimer>
#include <QObject>
#include <QString>
#include <QGraphicsPixmapItem>
#include <QPixmap>

class Zelda : public Personnage
{
public:
    //Constructor & Destructor
    Zelda();
    Zelda(QString);

    void update();

    void checkCollideWithElement();

    int getArrows();
   // void takeItem(Ressource &item); // take life, weapon,...
    void setAnimation();

    // Getter & Setter
    int getNbreArrows() const;
    void setNbreArrows(int value);

    QString getName() const;
    void setName(const QString &value);

    QString getDir() const;
    void setDir(const QString &value);

    QList<QPixmap> getListAnimation() const;

protected:
    int nbreArrows;
    QPixmap picture;
    QTimer timer;
    QList<QPixmap> listAnimation;
};

#endif // ZELDA_H
