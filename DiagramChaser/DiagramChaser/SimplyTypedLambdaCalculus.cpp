#include "stdafx.h"
#include "SimplyTypedLambdaCalculus.h"
#include "Term.h"

SimplyTypedLambdaCalculus::SimplyTypedLambdaCalculus(const Type* baseType)
{
	auto base_type = IsType(baseType);
	baseTypeIntro = InferenceRule({}, base_type);

	// Doing it like the below has two advantages:
	// 1. Each InferenceRule already makes copies that it owns (on the Heap), so this avoids doubling the heap allocs.
	// 2. Line-by-lines are great for debugging purposes.  To inspect each variable etc.

	auto A_type = IsType(A);
	auto B_type = IsType(B);
	auto AxB = Product(A, B);
	auto AxB_type = IsType(AxB);
	auto AtoB = Function(A, B);
	auto AtoB_type = IsType(AtoB);

	productTypeIntro = InferenceRule({ &A_type, &B_type }, AxB_type);
	functionTypeIntro = InferenceRule({ &A_type, &B_type }, AtoB_type);

	addInferenceRules({ &baseTypeIntro, &productTypeIntro, &functionTypeIntro });
}
