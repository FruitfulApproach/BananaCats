#pragma once

#include <iostream>
#include <string>
#include <memory>
#include <typeinfo>
#include <exception>

class Var;
extern Var a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
extern Var A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;

class Term
{
public:
	Term()
	{}
	Term(const Term& source)
	{}
	virtual ~Term();

	virtual std::string toString() const
	{
		return objectToAddressString(this);
	}

	std::string str() const { return toString(); }
	friend std::ostream& operator<<(std::ostream& os, const Term& t);

	virtual Term* clone() const 
	{
		return new Term(*this);
	}

	virtual Term* operator * (const Term& term) const;

	virtual const Term* operator -> () const { return this; }		
	// -> operator is Left-associative in C++; In Lean/Coq however, it is Right-associative!
	
	Term& B() const;
};

class Var : public Term
{
public:
	Var(const std::string& unicode)
		// NOTE: Can't use string::length() to get char-length if we use UTF-8 unicode (for example)
		: Term()
	{
		this->unicode = unicode;
	}

	Var(const Var& source)
		: Term(source)
	{
		this->unicode = source.unicode;
	}

	Term* clone() const {
		return new Var(*this);
	}

	std::string toString() const override { return unicode; }

private:
	std::string unicode;
};


template<typename BuiltinInt>
class ZZ_ : public Term
{
// For example ZZ_<int> will usually act like ZZ_/32 from abstract algebra (on Windows x86+ PC at least)
public:
	ZZ_(const BuiltinInt& value)
	{

		this->value = value;
		this->string = std::to_string(value);
	}

	ZZ_(const ZZ_& source)
	{
		this->value = source.value;
		this->string = source.string;
	}

	const Term* clone() const {
		return new ZZ_(*this);
	}

	std::string toString() const override { return string; }

	ZZ_ operator + (const ZZ_& x) const
	{
		return ZZ_(value + x.value);
	}

	ZZ_ operator - (const ZZ_& x) const
	{
		return ZZ_(value - x.value);
	}

	ZZ_ operator * (const ZZ_& x) const
	{
		return ZZ_(value * x.value);
	}

	ZZ_ operator / (const ZZ_& x) const
	{
		return ZZ_(value / x.value);
	}

	ZZ_ operator % (const ZZ_& x) const
	{
		return ZZ_(value % x.value);
	}

	ZZ_ operator - () const
	{
		return ZZ_(-value);
	}

	ZZ_ operator >> (const ZZ_& x) const
	{
		return ZZ_(value >> x.value);
	}

	ZZ_ operator << (const ZZ_& x) const
	{
		return ZZ_(value << x.value);
	}

	ZZ_ operator & (const ZZ_& x) const
	{
		return ZZ_(value & x.value);
	}

	ZZ_ operator | (const ZZ_& x) const
	{
		return ZZ_(value | x.value);
	}

	static size_t sizeOf() { return sizeof(BuiltinInt); }

	bool operator < (const ZZ_& x) const
	{
		return value < x.value;
	}

	bool operator <= (const ZZ_& x) const
	{
		return value <= x.value;
	}

	bool operator > (const ZZ_& x) const
	{
		return value > x.value;
	}

	bool operator >= (const ZZ_& x) const
	{
		return value >= x.value;
	}

	bool operator == (const ZZ_& x) const
	{
		return value == x.value;
	}

	bool operator != (const ZZ_& x) const
	{
		return value != x.value;
	}

private:
	BuiltinInt value;
	std::string string;
};

typedef ZZ_<char> ZZ_8;
typedef ZZ_<short> ZZ_16;
typedef ZZ_<int> ZZ_32;
typedef ZZ_<long long> ZZ_64;


class String : public Term
{
public:
	String(const std::string& string="")
		: Term()
	{
		this->string = string;
	}

	String(const String& source)
		: Term(source)
	{
		this->string = source.string;
	}

	Term* clone() const {
		return new String(*this);
	}

	std::string toString() const override { return string; }

	//String operator * (const String& s)
	//{
	//	return String(string + s.string);
	//}

	//String operator () (const String& s)
	//{
	//	return *this * s;
	//}

	bool operator <= (const String& s)
	{
		if (s.string.find(this->string) != std::string::npos)
			return true;
		return false;
	}

private:
	std::string string;
};


class Product : public Term
{
public:
	Product(const Term& A, const Term& B)
		: lhs(A.clone()),
		rhs(B.clone())
	{}

	Product(const Product& source)
		: lhs(source.lhs->clone()),
		rhs(source.rhs->clone())
	{}

	Term* clone() const {
		return new Product(*this);
	}

	std::string toString() const override 
	{
		return lhs->str() + "×" + rhs->str();
	}

private:
	Term* lhs;
	Term* rhs;
};


class Function : public Term
{
public:
	Function(const Term& domain, const Term& codomain)
		: domain(domain.clone()), codomain(codomain.clone())
	{}

	Function(const Function& source)
		: domain(source.domain->clone()), codomain(source.codomain->clone())
	{}

	Term* clone() const {
		return new Function(*this);
	}

	std::string toString() const override
	{
		return "(" + domain->str() + " -> " + codomain->str() + ")";  
	}

private:
	Term* domain, * codomain;
};

//// This is for internal use only - not typically used by the end-user except during syntax sugar of A->(B);
//class _FunctionBuilder : public Term
//{
//public:
//	_FunctionBuilder(const Term& domain)
//	{}
//
//	std::string toString() const override
//	{
//		return domain->str() + "→?";
//	}
//
//	Function* operator () (const Term& codomain) const
//	{
//		return new Function(*domain, codomain);
//	}
//
//private:
//	Term* domain;
//};

inline Term& Term::B() const
{
	return *(new Function(*this, ::B));
}