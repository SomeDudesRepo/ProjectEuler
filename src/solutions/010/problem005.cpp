#include "problem005.h"

#include <string>

#include "../../log.h"

namespace
{

int CalculateSmallestMultiple(const int& min, const int& max)
{
    for (int n(max); ; n += max)
    {
        bool found(true);
        for (int p(min); p <= max; ++p)
        {
            if (n % p != 0)
            {
                found = false;
                break;
            }
        }
        if (found)
            return n;
    }
    throw std::string("Never found!");
}

}  // namspace

Problem005::Problem005(const int& min, const int& max)
    :   BaseRunnable(CalculateSmallestMultiple(min, max)) {}
