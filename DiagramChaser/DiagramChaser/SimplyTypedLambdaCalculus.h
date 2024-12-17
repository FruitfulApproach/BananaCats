#pragma once

#include "InferenceRule.h"
#include "Type.h"
#include "Judgement.h"
#include "TypeTheory.h"
#include <vector>

class SimplyTypedLambdaCalculus : public TypeTheory
{
public:
	SimplyTypedLambdaCalculus(const Type* baseType);

private:
	InferenceRule baseTypeIntro, productTypeIntro, functionTypeIntro,
		emptyContext, addToContext;
};



