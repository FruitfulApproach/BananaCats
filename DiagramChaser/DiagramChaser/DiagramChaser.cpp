#include "stdafx.h"
#include "DiagramChaser.h"


DiagramChaser::DiagramChaser(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DiagramChaserClass())
{
    ui->setupUi(this);
    view = new DiagramChaserView();
    setCentralWidget(view);
    scene = new DiagramChaserInteractiveScene();
    view->setScene(scene);
}

DiagramChaser::~DiagramChaser()
{
    delete ui;
    delete scene;
    delete view;
}
