#ifndef WORLD_H
#define WORLD_H
#include <QFile>

class World
{
public:
    World();
    const QString start();
    const QString nextStage(QString, QString);
    QList<QString> zones;
    QList<QList<QString> > links;
private:


};

#endif // WORLD_H
