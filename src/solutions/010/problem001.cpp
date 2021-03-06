#include "problem001.h"

#include <string>

#include "../../log.h"

namespace
{

// http://stackoverflow.com/questions/4229870/
//        c-algorithm-to-calculate-least-common-multiple-for-multiple-numbers
int GreatestCommonDenominator(int a, int b)
{
    for (;;)
    {
        if (a == 0)
            return b;
        b %= a;
        if (b == 0)
            return a;
        a %= b;
    }
}

int LeastCommonMultiple(int a, int b)
{
    int temp = GreatestCommonDenominator(a, b);
    Log("Gcd: " + std::to_string(temp));
    return temp ? (a / temp * b) : 0;
}

int SumNumbersUpTo(const int& limit)
{
    return limit * (limit + 1) / 2;
}

int CalculateSum(const int &a, const int &b, const int& limit)
{
    const int lcm(LeastCommonMultiple(a, b));
    Log("Lcm: " + std::to_string(lcm));
    return (a * SumNumbersUpTo(limit / a)) +
           (b * SumNumbersUpTo(limit / b)) -
           (lcm * SumNumbersUpTo(limit / lcm));
}

}  // namspace

Problem001::Problem001(const int &a, const int &b, const int& limit)
    :   BaseRunnable(CalculateSum(a, b, limit)) {}
