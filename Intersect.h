#pragma once
#include "Set.h"
#include "Union.h"

class Intersect : public Set
{
public:
    bool isMember(const unsigned element) const override;
    std::ostream& describe(std::ostream& os) const override;
    Set* operator||(Set* set1) const override;
    Set* operator&&(Set* set1) const override;
public:
    Intersect(Set* set1, Set* set2);
    Intersect(const Intersect& other);
    Intersect& operator=(const Intersect& other);
    ~Intersect();
private:
    void copy(const Intersect& other);
    void free();
    Set* clone() const override;
private:
    Set* m_set1, *m_set2;
};