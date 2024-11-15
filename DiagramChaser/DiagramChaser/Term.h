#pragma once

#include <iostream>
#include <string>

class Term
{
public:
	Term()
	{}
	Term(const Term& source)
	{}
	virtual ~Term();

	virtual std::string toString() const = 0;
	std::string str() const { return toString(); }
	friend std::ostream& operator<<(std::ostream& os, const Term& t);
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

	std::string toString() const override { return unicode; }

private:
	std::string unicode;
};

extern Var a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
extern Var A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;


template<typename BuiltinInt>
class ZZ : public Term
{
// For example ZZ<int> will usually act like ZZ/32 from abstract algebra (on Windows x86+ PC at least)
public:
	ZZ(const BuiltinInt& value)
	{

		this->value = value;
		this->string = std::to_string(value);
	}

	ZZ(const ZZ& source)
	{
		this->value = source.value;
		this->string = source.string;
	}

	std::string toString() const override { return string; }

	ZZ operator + (const ZZ& x) const
	{
		return ZZ(value + x.value);
	}

	ZZ operator - (const ZZ& x) const
	{
		return ZZ(value - x.value);
	}

	ZZ operator * (const ZZ& x) const
	{
		return ZZ(value * x.value);
	}

	ZZ operator / (const ZZ& x) const
	{
		return ZZ(value / x.value);
	}

	ZZ operator % (const ZZ& x) const
	{
		return ZZ(value % x.value);
	}

	ZZ operator - () const
	{
		return ZZ(-value);
	}

	ZZ operator >> (const ZZ& x) const
	{
		return ZZ(value >> x.value);
	}

	ZZ operator << (const ZZ& x) const
	{
		return ZZ(value << x.value);
	}

	ZZ operator & (const ZZ& x) const
	{
		return ZZ(value & x.value);
	}

	ZZ operator | (const ZZ& x) const
	{
		return ZZ(value | x.value);
	}

	static size_t sizeOf() { return sizeof(BuiltinInt); }

	bool operator < (const ZZ& x) const
	{
		return value < x.value;
	}

	bool operator <= (const ZZ& x) const
	{
		return value <= x.value;
	}

	bool operator > (const ZZ& x) const
	{
		return value > x.value;
	}

	bool operator >= (const ZZ& x) const
	{
		return value >= x.value;
	}

	bool operator == (const ZZ& x) const
	{
		return value == x.value;
	}

	bool operator != (const ZZ& x) const
	{
		return value != x.value;
	}

private:
	BuiltinInt value;
	std::string string;
};

typedef ZZ<char> ZZ_8;
typedef ZZ<short> ZZ_16;
typedef ZZ<int> ZZ_32;
typedef ZZ<long long> ZZ_64;


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

	std::string toString() const override { return string; }

	String operator * (const String& s)
	{
		return String(string + s.string);
	}

	String operator () (const String& s)
	{
		return *this * s;
	}

	bool operator <= (const String& s)
	{
		if (s.string.find(this->string) != std::string::npos)
			return true;
		return false;
	}

private:
	std::string string;
};

