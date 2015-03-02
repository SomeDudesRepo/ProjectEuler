#ifndef PRIMES_H
#define PRIMES_H

#include <cstdint>
#include <vector>

const uint64_t gPrimes[] = {2, 3, 5, 7, 11, 13, 17, 19};

void GetNextPrime(std::vector<uint64_t>& primes, const int& limit = -1);

uint64_t GetNthPrime(const int& n);

#endif // PRIMES_H
