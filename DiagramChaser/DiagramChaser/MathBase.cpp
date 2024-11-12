#include "stdafx.h"
#include "MathBase.h"
#include <typeinfo>
#include <QtGlobal>

MathBase::MathBase(const QString& name)
{
	this->name = name;
}

MathBase::~MathBase()
{
}

QString MathBase::string() const
{
	if (this->name != nullptr)
		return this->name;
	qFatal("Not Implemented", "Author didn't implement " + QString(typeid(*this).name()) + " class's string() method.");
	return "NotImplemented";
}
