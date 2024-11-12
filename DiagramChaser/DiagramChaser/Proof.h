#pragma once

#include "Prop.h"

class Proof : public Prop
{
public:
	Proof(const QString& name = nullptr);
	~Proof() {}

	virtual Prop prove() const = 0;

	virtual const Prop& result() const 
	{
		return theoremResult;
	}

protected:
	Prop theoremResult;
};

