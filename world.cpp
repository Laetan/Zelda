#include "world.h"
#include <QDir>
#include <QCoreApplication>
#include <QtDebug>
#include <QMessageBox>

World::World()
{
    QString dirPath = QCoreApplication::applicationDirPath()+"/Ressources/zones";
    QDir zoneDir(dirPath);
    QStringList list=zoneDir.entryList();

    for(int i=0; i<list.size();i++){
        if(list.at(i).endsWith(".zn")){
            QString path = zoneDir.absolutePath()+"/"+list.at(i);
            path.chop(3);
            zones.append(path);
        }
    }
    QFile linkFile(dirPath+"/world.link");
    if(!linkFile.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", "Cannot find world link file world.link");
    }
    QTextStream in(&linkFile);
    while(!in.atEnd()) {
        QString line = in.readLine();
        QList<QString> row = line.split(" ");
        if(row.size()==3) links.append(row);
    }
}

const QString World::start(){
    for(int i = 0; i< zones.size();i++){
        if(zones[i].endsWith("start")){
            return zones[i];
        }
    }
    return zones[0];

}
