#pragma once
#include "Object.h"

class Prop : public Object
{
public:
	Prop(const QString& name=nullptr) : Object(name) {}
	~Prop() {}
};

