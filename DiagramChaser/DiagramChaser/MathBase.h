#pragma once

#include <QString>

class MathBase
{
public:
	MathBase(const QString& name = nullptr);
	virtual ~MathBase();

    bool operator==(const MathBase& other) const
    {
        return this->string() == other.string();
    }

    bool operator!=(const MathBase& other) const 
    { 
        return !(*this == other); 
    }

    friend uint qHash(const MathBase& key, size_t seed = 0) 
    {
        return qHash(key.string(), static_cast<uint>(seed));
    }

    virtual QString string() const;

protected:
	QString name;
};
