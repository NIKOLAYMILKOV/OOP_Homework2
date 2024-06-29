#pragma once
#include "Set.h"
#include <string>
#include "Union.h"
#include "Intersect.h"

class Filter : public Set
{
public:
    bool isMember(const unsigned element) const override;
    std::ostream& describe(std::ostream& os) const override;
    Set* operator||(Set* set1) const override;
    Set* operator&&(Set* set1) const override;
public:
    Filter(Set* set, bool(*filterCondition)(unsigned int), std::string describtion);
    Filter(const Filter& other);
    Filter& operator=(const Filter& other);
    ~Filter();
private:
    void copy(const Filter& other);
    void free();
    Set* clone() const override;
private:
    Set* m_set;
    bool(*m_filterCondition)(unsigned int);
    std::string m_describtion;
};



