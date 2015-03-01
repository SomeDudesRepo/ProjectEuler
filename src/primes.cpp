#include "primes.h"

#include "log.h"

void GetNextPrime(std::vector<uint64_t>& primes)
{
    for (uint64_t next(primes.back() + 2); ; next += 2)
    {
        bool found(true);
        for (const auto& p : primes)
        {
            if (next % p == 0)
            {
                found = false;
                break;
            }
        }
        if (found)
        {
            primes.push_back(next);
            break;
        }
    }
}

uint64_t GetNthPrime(const int& n)
{
    std::vector<uint64_t> primes(gPrimes, gPrimes + sizeof gPrimes / sizeof gPrimes[0]);
    if (size_t(n) < primes.size())
        return primes.at(n - 1);

    while (size_t(n) > primes.size())
        GetNextPrime(primes);

    return primes.back();
}
