#pragma once
#include "Set.h"
#include "Interval.h"
#include "Intersect.h"
#include "Union.h"

class Series : public Set
{
public:
    bool isMember(const unsigned element) const override;
    std::ostream& describe(std::ostream& os) const override;
    Set* operator||(Set* set1) const override;
    Set* operator&&(Set* set1) const override;
public:
    // Series(){};
    Series(Set* set, unsigned(*seriesExpresion)(unsigned a), std::string description);
    Series(const Series& other);
    Series& operator=(const Series& other);
    ~Series();
private:
    void copy(const Series& other);
    void free();
    Set* clone() const override;
private:
    Set* m_set;
    unsigned(*m_seriesExpresion)(unsigned a);
    std::string m_description;
};