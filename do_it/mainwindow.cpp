#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "customscene.h"
#include "triangle.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new CustomScene();
    triangle= new Triangle();
    triangle->setPos(250,250);
    scene->addItem(triangle);

    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setMouseTracking(true);

    connect(scene, &CustomScene::MoveMouseSignal, triangle, &Triangle::UsePhysicsToMoveSlot);

}

MainWindow::~MainWindow()
{
    delete ui;
}

