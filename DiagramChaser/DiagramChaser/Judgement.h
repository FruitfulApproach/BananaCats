#pragma once

#include "Type.h"

class Judgement
{
public:
	Judgement()
	{}
	Judgement(const Judgement& source)
	{}
	virtual ~Judgement();

	virtual std::string toString() const
	{
		return objectToAddressString(this);
	}

	std::string str() const { return toString(); }

	virtual const Judgement* clone() const {
		return new Judgement(*this);
	}
};

class IsType : public Judgement
{
public:
	IsType(const Term* type)
		: Judgement()
	{
		this->type = dynamic_cast<const Type*>(type->clone());
	}

	IsType(const Term& term)
		: Judgement()
	{
		this->type = dynamic_cast<const Type*>(term.clone());
	}

	IsType(const IsType& source)
	{
		type = dynamic_cast<const Type*>(source.type->clone());
	}

	std::string toString() const override {
		return type->str() + " type";
	}

	const Judgement* clone() const {
		return new IsType(*this);
	}

private:
	const Type* type;
};

class Typing : public Judgement
{
	const Judgement* clone() const {
		return new Typing(*this);
	}
};

class WellFormed : public Judgement
{
	const Judgement* clone() const {
		return new WellFormed(*this);
	}
};

class IsContext : public Judgement
{
public:
	IsContext(const Term& term)
		: term(term.clone())
	{}

	IsContext(const IsContext& source)
	{
		this->term = source.term->clone();
	}

	Judgement* clone() const {
		return new IsContext(*this);
	}

	std::string toString() const override
	{
		return "|- " + term->str() + " ctx";
	}

private:
	const Term* term;
};