#include "stdafx.h"
#include "DiagramChaser.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DiagramChaser w;
    w.show();
    return a.exec();
}
