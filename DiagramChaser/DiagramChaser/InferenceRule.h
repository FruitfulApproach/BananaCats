#pragma once

#include <initializer_list>
#include "Judgement.h"

class InferenceRule
{
public:
	InferenceRule() {}

	InferenceRule(const std::initializer_list<const Judgement*>& premises, const Judgement& conclusion);
	virtual ~InferenceRule();

	const InferenceRule* clone() const {
		return new InferenceRule(*this);
	}

private:
	std::vector<const Judgement*> premises;
	const Judgement* conclusion = nullptr;
};

