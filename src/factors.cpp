#include "factors.h"

#include <cmath>

uint64_t ProperDivisorSum(const uint64_t& n)
{
    const uint64_t root(static_cast<uint64_t>(std::sqrt(n)));
    uint64_t sum(1);
    for (uint64_t i(2); i <= root; ++i)
    {
        if (n % i == 0)
            sum += i + (i == root && root * root == n ? 0 : (n / i));
    }
    return sum;
}

int ProperDivisorCount(const uint64_t& n, const int& count)
{
    const uint64_t root(static_cast<uint64_t>(std::sqrt(n)));
    int fCount(0);
    for (uint64_t i(1); i <= root; ++i)
    {
        if(n % i == 0)
        {
            if (i == root)
                ++fCount;
            else
                fCount += 2;
        }
        if (fCount > count)
            return fCount;
    }
    return fCount;
}
