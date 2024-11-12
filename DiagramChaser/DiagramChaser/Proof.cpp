#include "stdafx.h"
#include "Proof.h"

Proof::Proof(const QString& name) : Prop(name)
{

	theoremResult = prove();
}
