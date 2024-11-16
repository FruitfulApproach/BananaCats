#pragma once

#include "Term.h"
#include <string>

class Type : public Term
{
public:
	Type() : Term() {
	}

	Type(const Type& source) : Term(source)
	{
	}

	virtual const Term* clone() const 
	{
		return new Type(*this);
	}

	~Type();
};

class DependentType : public Type
{
public:
	DependentType(const Term* x, const Type* A) 
		: Type(), term(x), type(A)
	{
	}

	DependentType(const DependentType& source)
		: Type()
	{
		term = source.term->clone();
		type = dynamic_cast<const Type*>(source.type->clone());
	}

	virtual const Term* clone() const 
	{
		return new DependentType(*this);
	}

	virtual const Type* operator () (const Term& x) 
	{
		return nullptr; // TODO ??? later in the book
	}

	std::string toString() const 
	{
		return Type::toString() + ":" + type->str() + "→" + "Universe";
	}

private:
	const Term* term;
	const Type* type;
};

class PiType : public DependentType
{
public:
	PiType(const Term* x, const Type* A)
		: DependentType(x, A)
	{
	}
};

