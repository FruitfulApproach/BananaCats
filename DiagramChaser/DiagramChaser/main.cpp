#include "stdafx.h"
#include "MainWindow.h"
#include <QtWidgets/QApplication>

// TODO TEST REMOVE
#include "Term.h"
#include "Type.h"
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    // TODO TEST REMOVE
    //Var b1 = b;
    //ZZ_8 _1(1);
    //ZZ_8 _2(2);

    auto A = Term();
    auto B = Type();
    //auto P = PiType(x, A, B(x))

    qDebug() << A.toString();

    return a.exec();
}
