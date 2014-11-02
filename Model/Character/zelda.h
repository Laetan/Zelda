#ifndef ZELDA_H
#define ZELDA_H

#include "personnage.h"
#include <QTimer>
#include <QObject>
#include <QString>
#include <QGraphicsPixmapItem>
#include <QPixmap>

/**
 * @brief Classe de gestion du joueur
 */
class Zelda : public Personnage
{
public:
    //Constructor & Destructor
    Zelda();
    Zelda(QString);

    void update();

    void checkCollideWithElement();
    void loot(QString);
    void takeDmg();
    int getArrows();
    void setAnimation();
    void blink();
    void death();

    // Getter & Setter
    int getNbreArrows() const;
    void setNbreArrows(int value);

    QString getName() const;
    void setName(const QString &value);

    QString getDir() const;
    void setDir(const QString &value);

    QList<QPixmap> getListAnimation() const;

public:

protected:

protected:
    int nbreArrows;
    QPixmap picture;
    int blinkCounter = 0;
    int blinkOn = 0;
    QTimer timer;
    QList<QPixmap> listAnimation;
};

#endif // ZELDA_H
