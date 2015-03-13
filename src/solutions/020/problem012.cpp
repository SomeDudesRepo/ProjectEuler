#include "problem012.h"

#include <vector>

#include "../../factors.h"
#include "../../log.h"

namespace
{

uint64_t TriangleWithDivisorCount(const int& count)
{
    uint64_t current(0), next(1);
    int factors(0);
    while (factors < count)
    {
        current += next;
        factors = ProperDivisorCount(current, count);
        ++next;
    }
    return current;
}

}  // namespace

Problem012::Problem012(const int& count)
    :   BaseRunnable(TriangleWithDivisorCount(count)) {}
