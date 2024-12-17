#include "stdafx.h"
#include "DiagramChaser.h"

DiagramChaser::DiagramChaser(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DiagramChaserClass())
{
    ui->setupUi(this);
}

DiagramChaser::~DiagramChaser()
{
    delete ui;
}
