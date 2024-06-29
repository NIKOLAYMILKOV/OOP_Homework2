#include "Set.h"
#include "Union.h"
#include "Intersect.h"

Set* operator||(Set& set1, Set* set2)
{
    return new Union(&set1, set2);
}
Set* operator&&(Set& set1, Set* set2)
{
    return new Intersect(&set1, set2);
}