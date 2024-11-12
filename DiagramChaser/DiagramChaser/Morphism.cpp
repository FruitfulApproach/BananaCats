#include "stdafx.h"
#include "Morphism.h"
#include <QStringList>

Morphism::Morphism(const Object& X, const Object& Y, const QVector<Morphism>& composition, 
	const QString& name)
	: Object(name)
{
	domain = X;
	codomain = Y;
	this->composition = composition;
}

Morphism::~Morphism()
{
}

Morphism Morphism::operator()(const Morphism& f) const
{
	const Morphism& g = *this;

	if (f.cod() != g.dom())
	{
		qFatal("Composition Undefined", "Morphism composition " +
			g.string() + "(" + f.string() + ") is undefined because of domain / codomain incompatibilty.");
	}

	return Morphism(f.dom(), g.cod(), { *this, f });
}

QString Morphism::string() const
{
	if (composition.length() == 0)
		return Object::string();

	QStringList list;
	
	foreach(auto & f, composition)
	{
		list << f.string();
	}

	return list.join("∘");
}

