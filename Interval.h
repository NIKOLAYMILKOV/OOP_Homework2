#pragma once
#include "Set.h"
#include "Union.h"
#include "Intersect.h"

class Interval : public Set
{
public:
    Interval(){};
    Interval(const unsigned leftEnd, const unsigned rightEnd);
    ~Interval() = default;
public:
    bool isMember(const unsigned element) const override;
    std::ostream& describe(std::ostream& os) const override;
    const unsigned getLeftEnd() const;
    const unsigned getRightEnd() const;
    Set* operator||(Set* set1) const override;
    Set* operator&&(Set* set1) const override;
private:
    Set* clone() const override;
private:
    size_t m_leftEnd, m_rightEnd;
};
