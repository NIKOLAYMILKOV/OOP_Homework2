#pragma once
#include "Set.h"
#include "Intersect.h"

class Union : public Set
{
public:
    bool isMember(const unsigned elment) const override;
    std::ostream& describe(std::ostream& os) const override;
    Set* operator||(Set* set1) const override;
    Set* operator&&(Set* set1) const override;
public:
    Union(Set* set1, Set* set2);
    Union(const Union& other);
    Union& operator=(const Union& other);
    ~Union();
private:
    void copy(const Union& other);
    void free();
    Set* clone() const override;
private:
    Set* m_set1, *m_set2;
};
