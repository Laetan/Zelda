#include "canvas.h"
#include <QtDebug>
#include <QMessageBox>
typedef QList<QList<QPixmap> > Picto;



//Palette::Palette(QObject *parent): QGraphicsScene(0,0,200,800,parent),selection(nullptr),ssm("sprite_zone"),
//    selectedPixRef("")
//{
//}

Palette::Palette(int posx,int posy,int width,int height,QObject *parent) :
    QGraphicsScene(posx,posy,width,height,parent),
    selection(nullptr),
    selectedPixRef(""),
    ssm("sprite_zone","env"),
    elemSS("sprite_monster1","elem")
{

    getPics(&ssm);
    drawPics();
    currentPalette=ENVIRONNEMENT;

}

void Palette::getPics(SpriteSheetManager* ss){
    QList<QString> picNames = ss->finder->allPic();
    QHash<QString,QPixmap> picList;

    foreach(QString picName,picNames){
        picList.insert(picName,ss->get(picName));
    }
    pixmaps = picList;
    return;
}

void Palette::drawPics(){
    int i = 0;
    QList<QString>keys = pixmaps.keys();
    std::sort(keys.begin(),keys.end());
    foreach (QString key, keys) {
        Palette::Pic *pic = new Palette::Pic(i,key,pixmaps[key],this);
        picLabels.append(pic);
        this->addItem(pic);
        i++;
    }

    setSceneRect(0,0,width(),i*40+70);
}

void Palette::changeSelection(Palette::Pic *picSelected){
    int pos = picLabels.indexOf(picSelected);
    if(pos>=0){
        if(selection==nullptr){
            selection = new QGraphicsRectItem(0,0,178,39);
            this->addItem(selection);
        }
        selection->setPos(6,17+pos*40);
        QString labelText = ((QGraphicsTextItem*)picSelected->childItems()[0])->toPlainText();
        if(currentPalette==ENVIRONNEMENT)
            selectedPixRef = ssm.finder->findRef(labelText) ;
        if(currentPalette==ELEMENT)
            selectedPixRef = elemSS.finder->findRef(labelText) ;
        if(selectedPixRef==""){
            QMessageBox::information(0, "error", "Unreferenced label : "+labelText);
        }

    }else{
        qDebug()<<"Cannot find this pic in pics";
    }
}

Palette::Pic::Pic(int pos, QString label, QPixmap &pict, Palette *p):QGraphicsRectItem(0,0,170,33),
palette(p){
    this->setPos(10,20+pos*40);
    QGraphicsTextItem *labelItem =new QGraphicsTextItem(label,this);
    labelItem->setPos(40,0);
    QGraphicsPixmapItem *pic= new QGraphicsPixmapItem(pict,this);
    int posx = 17-pict.width()/2, posy=17-pict.width()/2;
    pic->setPos(posx,posy);
}

void Palette::Pic::mousePressEvent(QGraphicsSceneMouseEvent *mouse){
    if(mouse->button()==Qt::LeftButton)
        palette->changeSelection(this);
}

void Palette::changePaletteToElement(){
    if(currentPalette==ELEMENT)return;
    getPics(&elemSS);
    this->clear();
    picLabels.clear();
    selection=nullptr;
    drawPics();
    currentPalette=ELEMENT;
}
void Palette::changePaletteToEnvironement(){
    if(currentPalette==ENVIRONNEMENT)return;
    getPics(&ssm);
    this->clear();
    picLabels.clear();
    selection=nullptr;
    drawPics();
    currentPalette=ENVIRONNEMENT;
}

const QString Palette::getSelectedPixRef(){return selectedPixRef;}
int Palette::getCurrentPalette(){return currentPalette;}
