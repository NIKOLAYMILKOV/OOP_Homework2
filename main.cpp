#include "Interval.h"
#include "Intersect.h"
#include "Union.h"
#include "Filter.h"
#include "Series.h"
#include "Family.h"
#include "N.h"

bool isPrime(const unsigned n)
{
    if (n == 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

int main()
{
    
}