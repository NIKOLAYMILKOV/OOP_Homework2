#pragma once
#include "Set.h"
#include "Union.h"
#include "Intersect.h"
#include <vector>

class Family : public Set
{
public:
    Family operator+(const Set* set) const;
    Family& operator+=(const Set* set);
    Family& add(const Set* set);
    Set* intersect();
    Set* unite();
    bool isMember(const unsigned element) const override;
    std::ostream& describe(std::ostream& os) const override;
    Set* operator||(Set* set1) const override;
    Set* operator&&(Set* set1) const override;
public:
    Family() = default;
    Family(const Family& other);
    Family& operator=(const Family& other);
    ~Family();
private:
    Set* clone() const override;
    void copy(const Family& other);
    void free();
private:
    std::vector<Set*> m_sets;
};


