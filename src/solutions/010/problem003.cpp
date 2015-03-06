#include "problem003.h"

#include <string>

#include "../../log.h"
#include "../../primes.h"

namespace
{

uint64_t CalculateMaxPrimeFactor(const uint64_t& number)
{
    std::vector<uint64_t> primes(gPrimes, gPrimes + sizeof gPrimes / sizeof gPrimes[0]);
//    std::vector<uint64_t> primes(ArrayToVector<uint64_t>(gPrimes));
    int n(0);
    uint64_t temp(number);
    bool run(true);
    while (run)
    {
        if (n == primes.size())
            GetNextPrime(primes);
        Log("n: " + std::to_string(n) + ", back: " + std::to_string(primes.back()) +
            ", temp: " + std::to_string(temp));
        if (primes.back() == temp)
            return temp;

        while (temp % primes[n] == 0)
            temp /= primes[n];

        ++n;
    }
    throw std::string("No factors?!?!?!");
}

}  // namspace

Problem003::Problem003(const uint64_t& number)
    :   BaseRunnable(CalculateMaxPrimeFactor(number)) {}
