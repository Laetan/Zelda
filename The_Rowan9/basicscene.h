#ifndef BASICSCENE_H
#define BASICSCENE_H

#include <QGraphicsScene>
#include <QTimer>

class BasicScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit BasicScene(QObject *parent = 0);
    BasicScene(int,int,int,int,QObject *parent = 0);
private:
    QTimer *timer;
signals:

public slots:
    void update();

};

#endif // BASICSCENE_H
