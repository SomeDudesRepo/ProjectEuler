#include "problem09.h"

#include <vector>

#include "../log.h"

namespace
{

bool IsNaturalSquare(const int& n)
{
    const int root(static_cast<int>(std::sqrt(n)));
    return root * root == n;
}

std::vector<int> NaturalSquares(const int& limit)
{
    std::vector<int> result;
    for (int n(limit); n > 0; --n)
    {
        if (IsNaturalSquare(n))
            result.push_back(n);
    }
    return result;
}

void CheckPossibleTriplets(const int& square, const int& sum)
{
    for (int i(square - 1); i > 0; --i)
    {
        for (int j(i -1); j > 0; --j)
        {

        }
    }
}

uint64_t GetPythagoreanProduct()
{
    const int sum(1000);
    auto squares = NaturalSquares(1000);
    for (const auto& square : squares)
    {
        CheckPossibleTriplets(square, sum);
    }
    uint64_t candidate(0);
    return candidate;
}

}  // namespace

Problem09::Problem09() : BaseRunnable(GetPythagoreanProduct()) {}
