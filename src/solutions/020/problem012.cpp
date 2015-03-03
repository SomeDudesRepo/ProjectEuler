#include "problem012.h"

#include <vector>

#include "../../log.h"

namespace
{

int FactorCount(const uint64_t& n, const int& count)
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

uint64_t TriangleWithDivisorCount(const int& count)
{
    uint64_t current(0), next(1);
    int factors(0);
    while (factors < count)
    {
        current += next;
        factors = FactorCount(current, count);
        ++next;
    }
    return current;
}

}  // namespace

Problem012::Problem012(const int& count)
    :   BaseRunnable(TriangleWithDivisorCount(count)) {}
