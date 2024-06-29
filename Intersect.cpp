#include "Intersect.h"

Intersect::Intersect(Set *set1, Set *set2)
{
    m_set1 = set1->clone();
    m_set2 = set2->clone();
}

Intersect::Intersect(const Intersect &other)
{
    copy(other);
}

Intersect &Intersect::operator=(const Intersect &other)
{
    if (this != &other)
    {
        free();
        copy(other);
    }
    return *this;
}

Intersect::~Intersect()
{
    free();
}

bool Intersect::isMember(const unsigned element) const
{
    return m_set1->isMember(element) && m_set2->isMember(element);
}

std::ostream &Intersect::describe(std::ostream &os) const
{
    m_set1->describe(os);
    os << " ∩ ";
    m_set2->describe(os);
    return os;
}

void Intersect::copy(const Intersect &other)
{
    m_set1 = other.m_set1->clone();
    m_set2 = other.m_set2->clone();
}

void Intersect::free()
{
    delete m_set1,m_set2;
}

Set *Intersect::clone() const
{
    return new Intersect(*this);
}

Set* Intersect::operator||(Set* set1)const
{
    return new Union((Set*)this, set1);
}
Set* Intersect::operator&&(Set* set1)const 
{
    return new Intersect((Set*)this, set1);
}

