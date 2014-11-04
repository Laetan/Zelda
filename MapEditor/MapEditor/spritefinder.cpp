#include "spritesheet.h"
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QCoreApplication>
#include <QDir>
#include <QtDebug>

SpriteFinder::SpriteFinder(QString fileName, QString type): type(type)
{
    QFile file(fileName+".conf");
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", file.errorString()+":"+fileName+".conf");
    }
    QTextStream in(&file);
    while(!in.atEnd()) {
        QString line = in.readLine();
        finder.append(line.split(";"));
    }
    file.close();
    in.reset();
    file.setFileName(fileName+".ref");
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", file.errorString()+":"+fileName+".ref");
    }
    while(!in.atEnd()) {
        QString line = in.readLine();
        refTable.append(line.split(";"));
    }
    file.close();

}
/**
 * @brief SpriteFinder::find Recupère les coordonnées du sprite req dans le sprite sheet
 * @param req
 * @return
 */
QList<int>SpriteFinder::find(const QString req ){
    QList<int> resp ;

    for(int i=0; i < finder.size(); i++){
        QList<QString> row = finder.at(i);
        if(row.size()>2 && row.at(2).startsWith(req)){
            resp.append(row[0].toInt());
            resp.append(row[1].toInt());
        }
    }
    return resp;
}

QList<QList<int> > SpriteFinder::findAll(const QString req ){
    QList<QList<int> > resp ;
    for(int i=0; i < finder.size(); i++){
        QList<QString> row = finder.at(i);
        if(row.size()>2 && row.at(2).startsWith(req)){
            QList<int> resp_row;
            resp_row.append(row[0].toInt());
            resp_row.append(row[1].toInt());
            resp.append(resp_row);
        }
    }
    return resp;
}

QList<QString> SpriteFinder::allPic(){
    QList<QString> resp;
    QList<QList<QString> > *list_ptr(0);
    int refIndex;
    if(type=="elem"){list_ptr=&refTable; refIndex = 2;}
    else if(type=="env"){list_ptr=&finder;refIndex = 2;}
    for(int i=0; i < list_ptr->size(); i++){
        QList<QString> row = list_ptr->at(i);
        if(row.size()>refIndex && !row[refIndex].isNull() && !row[refIndex].isEmpty())
            resp.append(row[refIndex]);
    }
    return resp;
}

QString SpriteFinder::findByRef(QString ref){
    for(int i =0; i < refTable.size();i++){
        if(refTable[i][0]==ref)
            return refTable[i][1];
    }
    return "";
}
QString SpriteFinder::findRef(const QString obj){
    if(type=="elem") return obj;
    for(int i =0; i < refTable.size();i++){
        if(refTable[i].size()>1 && refTable[i][1]==obj)
            return refTable[i][0];
    }
    return "";
}

const QList<int> SpriteFinder::picSize(const QString ref){
    QList<int> resp;
    for(int i =0; i < refTable.size();i++){
        if(refTable[i].size()>2 && refTable[i][2]==ref){
            resp.append(refTable[i][0].toInt());
            resp.append(refTable[i][1].toInt());
            return resp;
        }
    }
    return resp;
}
