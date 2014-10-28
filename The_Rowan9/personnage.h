#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include <QMouseEvent>
#include <QKeyEvent>
#include <QWidget>
#include <QtGui>

#include "element.h"

class Personnage : public Element  // Classe abstraite
{
    Q_OBJECT

signals:
    void mouseClickEvent();

public:
    Personnage(QWidget *aParent=0)=0; // Fonction virtuelle pure
    ~Personnage();

    // Methods
    void Move(int, int);
    bool Alive(int life);
    int ReceiveDmg(int dmg);
    void Attack(Personnage &target);
    void Speak();

    //Getter & Setter
    int getLife() const;
    void setLife(int value);

    int getDmg() const;
    void setDmg(int value);

    int getX() const;
    void setX(int value);

    int getY() const;
    void setY(int value);


protected:
    int life;
    int dmg;
    int x;
    int y;

};

#endif // PERSONNAGE_H
