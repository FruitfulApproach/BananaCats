#include "stdafx.h"
#include "Category.h"

Category::Category(const QString& name)
	: Object(name)
{

}

Category::~Category()
{
}

QSet<Object> Category::ob() const
{
	auto values = constructedObjects.values();
	QSet<Object> set(values.begin(), values.end());
	return set;
}

QSet<Morphism> Category::mor() const
{
	auto values = constructedMorphisms.values();
	QSet<Morphism> set(values.begin(), values.end());
	return set;
}

const Object& Category::operator()(const QString& name) const
{
	Object X(name);
	return addObject(X);
}

const Object& Category::addObject(const Object& X) const
{
	constructedObjects[X.string()] = X;
	return constructedObjects[X.string()];
}


