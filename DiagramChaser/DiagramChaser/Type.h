#pragma once

#include "Term.h"
#include <string>

class Type : public Term
{
public:
	Type() : Term() {
		typeName = "Anonymous";
	}
	Type(const std::string& typeName) : Term()
	{
		this->typeName = typeName;
	}
	Type(const Type& source) 
		: Term(source)
	{
		typeName = source.typeName;
	}
	~Type();

	std::string toString() const override { return typeName;  }
	

protected:
	std::string typeName;
};

class DependentType : public Type
{
public:
	DependentType(const Term& x, const Type& A, const std::string& typeName=nullptr) 
		: Type(typeName)
	{
		*term = x;
		*type = A;
	}

	virtual Type* operator () (const Term& x) = 0;

	std::string toString() const {
		return Type::toString() + ":" + type->str() + "→" + "Universe";
	}

protected:
	Term* term;
	Type* type;
};

class PiType : public DependentType
{
public:
	PiType(const Term& x, const Type& A, const std::string& typeName)
		: DependentType(x, A, "Π(" + x.str() + ":" + A.str() + ")" + typeName + "(" + x.str() + ")")
	{
	}
};

