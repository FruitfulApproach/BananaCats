#pragma once

#include "Object.h"
#include "Arrow.h"
#include "AutoLabelIndexer.h"

class Semicategory  : public Object
{
	Q_OBJECT

public:
	Semicategory(Label* name, const QString& composition, QGraphicsItem *parent=nullptr);

	Semicategory(const Semicategory& source)
		: Object(source)
	{ 
		o = source.o;
		this->objectLabel = new Label(*source.objectLabel);
		this->arrowLabel = new Label(*source.arrowLabel);
		this->objectSource = qgraphicsitem_cast<Object*>(source.objectSource->copy());
		this->arrowSource = qgraphicsitem_cast<Arrow*>(source.arrowSource->copy());
	}

	~Semicategory();

	void setArrowCopySource(Arrow* source)
	{
		arrowSource = source;
	}

	void setObjectCopySource(Object* source)
	{
		objectSource = source;
	}
	
	Label* autoIncrementObjectLabel(const Label& start)
	{
		Label* label;

		if (objectAutoIndexer == nullptr)
		{
			label = new Label(*start);
		}
		else
		{
			label = objectAutoIndexer->nextLabel(start);
		}

		return label;
	}

	Object* createObject()
	{
		objectSource = qgraphicsitem_cast<Object*>(objectSource->copy());
		objectLabel->setParentItem(objectSource);
		objectLabel = autoIncrementObjectLabel(*objectLabel);
		return objectSource;
	}

	Arrow* createArrow()
	{
		arrowSource = qgraphicsitem_cast<Arrow*>(arrowSource->copy());
		return arrowSource;
	}

private:
	QString o;  // Guess
	Label* objectLabel = nullptr;
	Label* arrowLabel = nullptr;
	Object* objectSource = nullptr;
	Arrow* arrowSource = nullptr;
	AutoLabelIndexer* arrowAutoIndexer = nullptr;
	AutoLabelIndexer* objectAutoIndexer = nullptr;
};
