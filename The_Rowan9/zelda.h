#ifndef ZELDA_H
#define ZELDA_H

#include "personnage.h"
#include <QTimer>
#include <QObject>
#include <QString>
#include <QGraphicsPixmapItem>

class Zelda : public Personnage
{
public:
    //Constructor & Destructor
    Zelda();
    ~Zelda();

    // Methods
    int getArrows();
   // void takeItem(Ressource &item); // take life, weapon,...


    void move(QString);
    void startMove(QString);

    // Getter & Setter
    int getNbreArrows() const;
    void setNbreArrows(int value);

    QString getName() const;
    void setName(const QString &value);

private:
    int nbreArrows;
    QString dir;
    QString name;
    QPixmap picture;
    QTimer timer;


    // Mouse & Keyboard event
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

    void StartMove(char dir);
};

#endif // ZELDA_H
