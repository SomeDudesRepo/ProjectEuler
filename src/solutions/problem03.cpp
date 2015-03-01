#include "problem03.h"

#include <string>

#include <QFile>
#include <QMessageBox>
#include <QXmlStreamReader>

#include "../log.h"
#include "../primes.h"

namespace
{

int CalculateMaxPrimeFactor(const uint64_t& number)
{
    Log("Start");
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
        {
            Log("End");
            return temp;
        }
        while (temp % primes[n] == 0)
        {
            temp /= primes[n];
        }
        ++n;
    }
    throw std::string("No factors?!?!?!");
}

}  // namspace

Problem03::Problem03(const uint64_t& number)
    :   BaseRunnable(CalculateMaxPrimeFactor(number)) {}
