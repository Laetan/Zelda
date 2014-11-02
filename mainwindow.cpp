#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gamescene.h"
#include "IntroScene.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    IntroScene *sceneIntro = new IntroScene(0,0,926,724,ui->graphicsView);
    //GameScene *game =  new GameScene(0,0,900,734,ui->graphicsView);
    ui->graphicsView->setScene(sceneIntro);
}

MainWindow::~MainWindow()
{
    delete ui;
}
