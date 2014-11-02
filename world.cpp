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
        if(row.size()==3){
            QString path = QCoreApplication::applicationDirPath()+"/Ressources/zones/";
            row[0] = path+row[0];row[2] = path+row[2];
            links.append(row);
            QString temp = row[0]; row[0]=row[2]; row[2]=temp;
            if(row[1]=="N") row[1]="S";
            else if(row[1]=="S") row[1]="N";
            else if(row[1]=="W") row[1]="E";
            else if(row[1]=="E") row[1]="W";
            else if(row[1]=="D") row[1]="U";
            else if(row[1]=="U") row[1]="D";
            links.append(row);
        }

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

const QString World::nextStage(QString stage, QString dir)
{
    foreach(QList<QString> link, links)
        if(link[0]==stage && link[1] == dir)
            return link[2];

}
