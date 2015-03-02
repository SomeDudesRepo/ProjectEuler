#include "problem004.h"

#include <cassert>
#include <string>

#include "../../log.h"

namespace
{

bool IsPalindrome(const int& number)
{
    const std::string sNumber(std::to_string(number));
    assert(sNumber.size() > 1U);
    const size_t middle(sNumber.size() / 2);
    std::string::const_iterator fIt(sNumber.begin());
    std::string::const_reverse_iterator rIt(sNumber.end());
    for(size_t n(0); n != middle; ++n, ++fIt, ++rIt)
    {
        if (*fIt != *rIt)
            return false;
    }
    return true;
}

int CalculateLargestPalindrome(const int& min, const int& max)
{
    int candidate(0);
    for( int i(max); i >= min; --i)
    {
        for (int j(max); j >= min; j--)
        {
            if (i * j > candidate && IsPalindrome(i * j))
                candidate = i * j;
        }
    }
    if (candidate == 0)
        throw std::string("No palindrome!");

    return candidate;
}

}  // namspace

Problem004::Problem004(const int& min, const int& max)
    :   BaseRunnable(CalculateLargestPalindrome(min, max)) {}
