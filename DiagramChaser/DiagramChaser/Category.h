#pragma once
#include "Object.h"
#include "Morphism.h"

class Category : public Object
{
public:
    Category(const QString& name=nullptr);
    ~Category();

    QSet<Object> ob() const;
    QSet<Morphism> mor() const;

    const Object& operator() (const QString& name) const;
    const Morphism& operator() (const Object& X, const Object& Y, const QString& name);
    const Morphism& operator() (const Morphism& g, const Morphism& f, const QString& name = nullptr);
    const Morphism& operator() (const QVector<Morphism> composition, const QString& name = nullptr);

    //void annotate(const Object& X, const QString& notation)
    //{
    //    if (constructedObjects.contains(notation))
    //    {
    //        auto objectWithThatName = constructedObjects[notation];

    //        if (objectWithThatName != X)
    //            qCritical("Ambiguous notation requested for " + X.string() + ", but " + X.tostring() " already owns the name.");
    //    }
    //    
    //    constructedObjects[notation] = X;
    //}

private:
    const Object& addObject(const Object& X) const;

protected:
    QMap<QString, Object> constructedObjects;
    QMap<QString, Morphism> constructedMorphisms;
};

