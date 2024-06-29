#include "Family.h"
#include "Union.h"

bool Family::isMember(const unsigned element) const
{
    for(Set* set : m_sets)
    {
        if(set->isMember(element)) return true;
    }
    return false;
}

std::ostream &Family::describe(std::ostream &os) const
{
    for(Set* set : m_sets)
    {
        set->describe(os); os << ", ";
    }
    return os;
}

Set *Family::clone() const
{
    return new Family(*this);
}

Family Family::operator+(const Set *set) const 
{
    Family result(*this);
    result.m_sets.push_back(set->clone());
    return result;
}

Family &Family::operator+=(const Set *set)
{
    m_sets.push_back(set->clone());
    return *this;
}

Family &Family::add(const Set *set)
{
    m_sets.push_back(set->clone());
    return *this;
}

Set *Family::intersect()
{
    Set* result = new Intersect(m_sets[0], m_sets[1]);
    for (size_t i = 2; i < m_sets.size(); i++)
    {
        result = new Intersect(result, m_sets[i]);
    }
    return result;
}
Set *Family::unite()
{
    Set* result = new Union(m_sets[0], m_sets[1]);
    for (size_t i = 2; i < m_sets.size(); i++)
    {
        result = new Union(result, m_sets[i]);
    }
    return result;
}

Set* Family::operator||(Set* set1)const
{
    return new Union((Set*)this, set1);
}
Set* Family::operator&&(Set* set1)const 
{
    return new Intersect((Set*)this, set1);
}

Family::Family(const Family& other)
{
    copy(other);
}
Family& Family::operator=(const Family& other)
{
    if (this != &other)
    {
        free();
        copy(other);
    }
    return *this;
    
}
Family::~Family()
{
    free();
}

void Family::copy(const Family& other)
{
    for(Set* set : other.m_sets)
    {
        m_sets.push_back(set->clone());
    }
}
void Family::free()
{
    for(Set* set : other.m_sets)
    {
        delete set;
    }
}