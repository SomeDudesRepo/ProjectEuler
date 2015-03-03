#include "problem010.h"

#include <vector>

#include "../../log.h"
#include "../../primes.h"

namespace
{

uint64_t GetSumOfPrimesUnderLimit(const int& limit)
{
    std::vector<uint64_t> primes;
    primes.push_back(2);
    primes.push_back(3);
    uint64_t sum(2);
    size_t pSize(1), cSize(primes.size());
    while (cSize != pSize)
    {
//        Log("sum: " + std::to_string(sum) +
//            ", back: " + std::to_string(primes.back()) +
//            ", size: " + std::to_string(primes.size()));
        sum += primes.back();
        GetNextPrime(primes, limit);
        pSize = cSize;
        cSize = primes.size();
    }
    return sum;
}

}  // namespace

Problem010::Problem010(const int& limit) : BaseRunnable(GetSumOfPrimesUnderLimit(limit)) {}
