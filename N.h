#pragma once
#include "Set.h"
#include "Intersect.h"
#include "Union.h"


class N : public Set
{
public:
    bool isMember(const unsigned elment) const override;
    std::ostream& describe(std::ostream& os) const override;
    Set* operator||(Set* set1) const override;
    Set* operator&&(Set* set1) const override;
public:
    N() = default;
    ~N() = default;
private:
    Set* clone() const override;
};

