#include "stdafx.h"
#include "MainWindow.h"
#include <QtWidgets/QApplication>

// TODO TEST REMOVE

#include "Morphism.h"
#include "Object.h"
#include "Category.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();


    // TODO TEST REMOVE

     /*   Object A("A");  
        Object B("B");
        Object C("C");
        Morphism f(A, B, {}, "f");
        Morphism g(B, C, {}, "g");
        Morphism h = g(f);
     */


    //Equality<Identity> identity_is_unique(const Category & C, const IdentityMorphism& id1, const IdentityMorphism& id2)
    //{
    //    Equality<Identity> eq;

    //    if ({ id1, id2 } <= C)
    //    {
    //        if (id1.dom() != id2.dom())
    //            qFatal("Incompatible Morphisms", "The identity morphisms passed in are not defined on the same object.");

    //        eq = id1 = id2.left(id1) = id1(id2) = id2;

    //        return eq.endPoints();
    //    }
    //    else {
    //        qFatal("Wrong Category", "The idenity maps passed in are not constructed in the category passed in.");
    //    }

    //    return eq;
    //}


    //auto C = Category("C");
    //auto X = C("X");
    //auto f = C(X, X, "f");
    //auto i = C.id(X, "i");
    //auto j = C.id(X, "j");  
    //auto i_eq_j = IdentityMorphismIsUnique(C, i, j).prove();

    //f = C("f:", X->Y);  //https://stackoverflow.com/a/4928626/7076615
    //g = C("g:", Y->Z);

    //qDebug() << h.string();

    return a.exec();
}
