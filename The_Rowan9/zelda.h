#ifndef ZELDA_H
#define ZELDA_H

#include "personnage.h"
#include <QTimer>
#include <QObject>

class Zelda : public Personnage
{
public:
    //Constructor & Destructor
    Zelda();
    ~Zelda();

    // Methods
    int GetArrows();
    void TakeItem(Ressource &item); // take life, weapon,...

    // Getter & Setter
    int getNbreArrows() const;
    void setNbreArrows(int value);

    string getName() const;
    void setName(const string &value);

private:
    int nbreArrows;
    string name;
    pixmap picture;
    QTimer timer;


    // Mouse & Keyboard event
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

    void StartMove(char dir);

private slot:
    void move(char dir);

};

#endif // ZELDA_H
