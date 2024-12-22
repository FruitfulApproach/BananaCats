#include "stdafx.h"
#include "AutoLabelIndexer.h"
#include <QRegularExpressionMatch>

AutoLabelIndexer::~AutoLabelIndexer()
{
	if (zzConstRegex != nullptr)
		delete zzConstRegex;
	if (variableRegex != nullptr)
		delete variableRegex;
}

void AutoLabelIndexer::parseIntoTemplate(QList<QString>& outputTemplate, 
	const QRegularExpression* regex)
{
	int component = 0;

	for (; component < outputTemplate.length(); ++)
	{

	}


	int prevSize = outputTemplate.size();
	auto text = outputTemplate.pop_front();
	int size = outputTemplate.size();

	while (prevSize < size)
	{
		QMap<int, QString> differences;
		auto matches = regex->globalMatch(text);
	}
};

Label* AutoLabelIndexer::computeNextLabel(Label* current, QList<const QRegularExpression*>& language=QList<const QRegularExpression*>())
{
	if (language.length() == 0)
		language = languagePrecedence;	

	Label* next = nullptr;
	auto txt = current->toPlainText();
	auto prevTxt = previous->toPlainText();



	parseText(txt);
	parseText(prevTxt);

	
	
	previous = current;
	return next;
}