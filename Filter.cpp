#include "Filter.h"

Filter::Filter(Set *set, bool (*filterCondition)(unsigned int), std::string describtion)
{
    m_set = set->clone();
    m_filterCondition = filterCondition;
    m_describtion = describtion;
}

Filter::Filter(const Filter &other)
{
    copy(other);
}

Filter &Filter::operator=(const Filter &other)
{
    if(this != &other)
    {
        free();
        copy(other);
    }
    return *this;
}

Filter::~Filter()
{
    free();
}

bool Filter::isMember(const unsigned element) const
{
    return m_filterCondition(element);
}

std::ostream &Filter::describe(std::ostream &os) const
{
    os << "{";
    m_set->describe(os);
    os << " | " << m_describtion << "}";
    return os;
}

Set *Filter::clone() const
{
    return new Filter(*this);
}

void Filter::copy(const Filter &other)
{
    m_set = other.m_set->clone();
    m_filterCondition = other.m_filterCondition;
    m_describtion = other.m_describtion;
}

void Filter::free()
{
    delete m_set, m_filterCondition;
}

Set* Filter::operator||(Set* set1)const
{
    return new Union((Set*)this, set1);
}
Set* Filter::operator&&(Set* set1)const 
{
    return new Intersect((Set*)this, set1);
}
