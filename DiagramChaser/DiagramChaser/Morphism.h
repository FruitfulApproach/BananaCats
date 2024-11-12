#pragma once

#include "Object.h"
#include <QtGlobal>

class Morphism : public Object
{
public:
	Morphism(const Object& X, const Object& Y, const QVector<Morphism>& composition = QVector<Morphism>(),
		const QString& name=nullptr);
	~Morphism();

	const Object& dom() const { return domain; }
	const Object& cod() const { return codomain; }

	virtual Morphism operator ()(const Morphism& f) const;

	QString string() const override;

protected:
	Object domain;
	Object codomain;
	QVector<Morphism> composition;
};


