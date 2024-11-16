#include "stdafx.h"
#include "InferenceRule.h"
#include <algorithm>

InferenceRule::InferenceRule(const std::initializer_list<const Judgement*>& premises, const Judgement& conclusion)
	: conclusion(conclusion.clone())
{
	for (auto it = premises.begin(); it != premises.end(); it++)
		this->premises.push_back((*it)->clone());
}

InferenceRule::~InferenceRule()
{
	// This object will own all of its child objects; so here we must delete them:

	for (size_t i = 0; i < premises.size(); i++)
		delete premises[i];

	delete conclusion;
}
