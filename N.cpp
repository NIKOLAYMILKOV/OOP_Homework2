#include "N.h"

bool N::isMember(const unsigned element) const
{
    return element >= 0;
}

std::ostream &N::describe(std::ostream &os) const
{
    os << "{n ∈ N}";
    return os;
}

Set *N::clone() const
{
    return new N(*this);
}

Set* N::operator||(Set* set1)const
{
    return new Union((Set*)this, set1);
}
Set* N::operator&&(Set* set1)const 
{
    return new Intersect((Set*)this, set1);
}

// N::N()
// {
//     isFinate = false;
// }
