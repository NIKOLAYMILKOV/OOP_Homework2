#include "Interval.h"
#include <Windows.h>

Interval::Interval(const unsigned leftEnd, const unsigned rightEnd)
{
    if(leftEnd < 0 || rightEnd < 0 || leftEnd > rightEnd) throw std::invalid_argument("Neither end can be engative number");

    m_leftEnd = leftEnd;
    m_rightEnd = rightEnd;
}

bool Interval::isMember(const unsigned element) const
{
    return element >= m_leftEnd && element <= m_rightEnd;
}

std::ostream &Interval::describe(std::ostream &os) const
{
    os << "{n belongs to [" << m_leftEnd << ", " << m_rightEnd << "]}";
    return os;
}

Set *Interval::clone() const
{
    return new Interval(*this);
}

const unsigned Interval::getLeftEnd() const
{
    return m_leftEnd;
}
const unsigned Interval::getRightEnd() const
{
    return m_rightEnd;
}

Set* Interval::operator||(Set* set1)const
{
    return new Union((Set*)this, set1);
}
Set* Interval::operator&&(Set* set1)const 
{
    return new Intersect((Set*)this, set1);
}