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

    // Methods
    int getArrows();
   // void takeItem(Ressource &item); // take life, weapon,...

    // Getter & Setter
    int getNbreArrows() const;
    void setNbreArrows(int value);

    QString getName() const;
    void setName(const QString &value);

    QString getDir() const;
    void setDir(const QString &value);

private:
    int nbreArrows;
    QString name;
    QPixmap picture;
    QTimer timer;
    QList<QPixmap> listAnimation;


    // Mouse & Keyboard event
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
  //  void keyReleaseEvent(QKeyEvent *event);

};

#endif // ZELDA_H
