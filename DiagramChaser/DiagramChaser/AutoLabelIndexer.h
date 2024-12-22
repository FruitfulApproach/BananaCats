#pragma once

#include <QObject>
#include "Label.h"
#include <qregularexpression.h>
#include <QBitArray>

class AutoLabelIndexer  : public QObject
{
	Q_OBJECT

public:
	AutoLabelIndexer(Label* start, QObject *parent=nullptr)
		: QObject(parent)
	{
		direction = 1;
		previous = start;

		zzConstRegex = new QRegularExpression("-?\s[0-9](\s[0-9])*");
		variableRegex = new QRegularExpression("[a-zA-Z]'*");

		languagePrecedence = {
			zzConstRegex,
			variableRegex,
		};
	}

	virtual ~AutoLabelIndexer();

	virtual Label* computeNextLabel(Label* current, QList<const QRegularExpression*> language);

private:
	void parseText(QList<QString>& outputTemplate);

private:
	Label* previous = nullptr;
	int direction = 0; // Uninitialized
	
	QRegularExpression* zzConstRegex;
	QRegularExpression* variableRegex;

	QList<const QRegularExpression*> languagePrecedence;
};
