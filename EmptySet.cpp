#include "EmptySet.h"

bool EmptySet::isMember(const unsigned element) const
{
    return false;
}

std::ostream &EmptySet::describe(std::ostream &os) const
{
    os << "{empty set}";
    return os;
}

Set *EmptySet::clone() const
{
    return new EmptySet(*this);
}

Set* EmptySet::operator||(Set* set1)const
{
    return new Union((Set*)this, set1);
}
Set* EmptySet::operator&&(Set* set1)const 
{
    return new Intersect((Set*)this, set1);
}

// EmptySet::EmptySet()
// {
//     m_isFinate = true;
// }
