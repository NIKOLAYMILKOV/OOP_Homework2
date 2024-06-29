#pragma once
#include <iostream>
#include <stdexcept>

class Set
{
public:
    Set() = default;
    virtual ~Set() = default;
    virtual bool isMember(const unsigned elment) const = 0;
    virtual std::ostream& describe(std::ostream& os)const = 0;
    virtual Set* clone() const = 0;
    virtual Set* operator||(Set* set1) const = 0;
    virtual Set* operator&&(Set* set1) const = 0;
    // bool isFinate() const;
protected:
    // bool m_isFinate;
};
