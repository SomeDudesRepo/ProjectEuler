#include "problem002.h"

#include <string>

#include "../../log.h"

namespace
{

void LogInts(const int &a, const int &b, const int& sum)
{
    Log("a: " + std::to_string(a) +
        ", b: " + std::to_string(b) +
        ", sum: " + std::to_string(sum));
}

int CalculateSum(const int& limit)
{
    int a(1), b(2), temp(0), sum(0);
    while (b < limit)
    {
      LogInts(a, b, sum);
      if (b % 2 == 0)
        sum += b;
      temp = a + b;
      std::swap(a, b);
      std::swap(b, temp);
    }
    return sum;
}

}  // namspace

Problem002::Problem002(const int& limit)
    :   BaseRunnable(CalculateSum(limit)) {}
