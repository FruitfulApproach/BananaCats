#include "stdafx.h"
#include "TypeTheory.h"

TypeTheory::~TypeTheory()
{
	for (int i = 0; i < this->ruleList.size(); i++)
		delete ruleList[i];
}

std::vector<const InferenceRule*> TypeTheory::inferenceRules() const
{
	std::vector<const InferenceRule*> ruleList;

	for (int i = 0; i < this->ruleList.size(); i++)
	{
		ruleList.push_back(this->ruleList[i]->clone());
	}

	return ruleList;
}

void TypeTheory::addInferenceRules(std::initializer_list<const InferenceRule*> ruleList)
{
	this->ruleList = std::vector<const InferenceRule*>(ruleList);
}
