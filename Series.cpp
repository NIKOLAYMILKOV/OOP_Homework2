#include "Series.h"

bool Series::isMember(const unsigned element) const
{    
    
    return false;
}

std::ostream &Series::describe(std::ostream &os) const
{
    os << "{" << m_description << " | ";
    m_set->describe(os);
    os << "}";

    return os;
}

Series::Series(Set *set, unsigned (*seriesExpresion)(unsigned a), std::string description)
{
    m_set = set->clone();
    m_seriesExpresion = seriesExpresion;
    m_description = description;
}

Series::Series(const Series &other)
{
    copy(other);
}

Series &Series::operator=(const Series &other)
{
    if(this != &other)
    {
        free();
        copy(other);
    }
    return *this;
}

Series::~Series()
{
    free();
}

void Series::copy(const Series &other)
{
    m_set = other.m_set->clone();
    m_seriesExpresion = other.m_seriesExpresion;
    m_description = other.m_description;
}

void Series::free()
{
    delete m_set, m_seriesExpresion;
}

Set *Series::clone() const
{
    return new Series(*this);
}

Set* Series::operator||(Set* set1)const
{
    return new Union((Set*)this, set1);
}   
Set* Series::operator&&(Set* set1)const 
{
    return new Intersect((Set*)this, set1);
}
