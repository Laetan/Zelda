#ifndef WORLD_H
#define WORLD_H
#include <QFile>

class World
{
public:
    World();
    const QString start();
    QList<QString> zones;
    QList<QList<QString> > links;
private:


};

#endif // WORLD_H
