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
    connect(ui->actionNewCategory, &QAction::triggered, this, &DiagramChaser::defineCategory);
}

void DiagramChaser::defineCategory()
{
    Category* category = new Category(this);
    auto result = category->exec();

    if (result == Category::Accepted)
    {
        
    }
}

DiagramChaser::~DiagramChaser()
{
    delete ui;
    delete scene;
    delete view;
}
