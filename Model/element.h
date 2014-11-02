#ifndef ELEMENT_H
#define ELEMENT_H

#include <QWidget>
#include <QtGui>
#include <QGraphicsPixmapItem>
#include <QString>

class Element : public QGraphicsPixmapItem
{
public:
    Element();
    Element(QString);
    Element(QString, QString);
    Element(QString, int, int, QString);

    void update();
    void move(bool=false);

    bool checkCollideWithEnv();
    bool collideWithEnv(int,int);
    QString getName() const;

    QString getDir() const;

    QString getCurrentDir() const;
    void setCurrentDir(const QString &value);

protected:
    int life;
    const QString name;
    int speed;
    QString dir;
    QString currentDir;

    void death();

};

#endif // ELEMENT_H
