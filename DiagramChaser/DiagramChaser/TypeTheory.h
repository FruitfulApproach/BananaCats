#pragma once

#include "InferenceRule.h"
#include <initializer_list>

class TypeTheory
{
public:
	TypeTheory()
	{}
	virtual ~TypeTheory();

	std::vector<const InferenceRule*> inferenceRules() const;

protected:
	void addInferenceRules(std::initializer_list<const InferenceRule*> ruleList);

private:
	std::vector<const InferenceRule*> ruleList;
};

