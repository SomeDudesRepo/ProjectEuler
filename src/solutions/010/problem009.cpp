#include "problem009.h"

#include <vector>

#include "../../log.h"

namespace
{

uint64_t GetPythagoreanProduct()
{
    for (int c(997); c > 3; --c)
    {
        for (int b(1000 - c - 1); c > (1000 - c) / 2 && b > 2; --b)
        {
            const int a(1000 - b - c);
            if (a > b)
                continue;
            if(std::pow(a, 2) + std::pow(b, 2) == std::pow(c, 2))
            {
                Log("GOOD!");
                Log("a: " + std::to_string(a) +
                    ", b: " + std::to_string(b) +
                    ", c: " + std::to_string(c));
                return a * b * c;
            }
        }
    }
    throw std::string("Did not find such triplet!");
}

}  // namespace

Problem009::Problem009() : BaseRunnable(GetPythagoreanProduct()) {}
