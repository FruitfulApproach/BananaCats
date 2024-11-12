#pragma once
#include "Morphism.h"

class IdentityMorphism : public Morphism
{
public:
	Morphism operator ()(const Morphism& f) const override
	{
		return leftIdentity(f);
	}

	Morphism leftIdentity(const Morphism& f) const
	{
		auto g = Morphism::operator()(f);
		return f;
	}

	Morphism rightIdentity(const Morphism& f) const
	{
		auto g = f(*this);
		return f;
	}
};

