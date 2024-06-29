#include "Union.h"

Union::Union(Set *set1, Set *set2)
{
    m_set1 = set1->clone();
    m_set2 = set2->clone();
}

Union::Union(const Union &other)
{
    copy(other);
}

Union &Union::operator=(const Union &other)
{
    if (this != &other)
    {
        free();
        copy(other);
    }
    return *this;
}

Union::~Union()
{
    free();
}

bool Union::isMember(const unsigned elment) const
{
    return m_set1->isMember(elment) || m_set2->isMember(elment);
}

std::ostream &Union::describe(std::ostream &os) const
{
    m_set1->describe(os);
    os << " U ";
    m_set2->describe(os);
    return os;
}

void Union::copy(const Union &other)
{
    m_set1 = other.m_set1->clone();
    m_set2 = other.m_set2->clone();
}

void Union::free()
{
    delete m_set1,m_set2;
}

Set *Union::clone() const
{
    return new Union(*this);
}

Set* Union::operator||(Set* set1)const
{
    return new Union((Set*)this, set1);
}
Set* Union::operator&&(Set* set1)const 
{
    return new Intersect((Set*)this, set1);
}