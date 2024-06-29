#pragma once
#include "Set.h"
#include "Union.h"
#include "Intersect.h"

class EmptySet :public Set
{
public:
    bool isMember(const unsigned element) const override;
    std::ostream& describe(std::ostream& os) const override;
    Set* operator||(Set* set1)const override;
    Set* operator&&(Set* set1)const override;
public:
    EmptySet() = default;
    ~EmptySet() = default;
private:
    Set* clone() const override;
};