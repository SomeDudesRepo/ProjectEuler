#include "problem007.h"

#include "../../log.h"
#include "../../primes.h"

Problem007::Problem007(const int& nth) : BaseRunnable(GetNthPrime(nth)) {}
