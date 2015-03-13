#include "problem023.h" 

#include <algorithm>
#include <vector>

#include "../../factors.h"
#include "../../log.h"

namespace 
{

struct State
{
    int n;
    bool abundant;

    State() : n(-1), abundant(false) {}
};

void PrintAbundants(const std::vector<State>& abundants)
{
    for (size_t n(0); n != abundants.size(); ++n)
    {
        if (abundants[n].abundant)
            Log("Abundant - " + std::to_string(n + 1) + ": " + std::to_string(abundants[n].n));
        else
            Log("NOT Abundant - " + std::to_string(n + 1) + ": " + std::to_string(abundants[n].n));
    }
}

bool IsSumOfPreviousAbundants(const int& n, const std::vector<State>& abundants)
{
    for (int i(1); i <= n; ++i)
    {
        if (!abundants[i - 1].abundant)
            continue;
        for (int j(n); j >= i; --j)
        {
//            Log("i: " + std::to_string(i) + ", j: " + std::to_string(j));
            if (!abundants[j - 1].abundant)
                continue;

            if (n == i + j)
            {
                Log(std::to_string(n) + " is the sum of i: " +
                    std::to_string(i) + " and j: " +
                    std::to_string(j) + "");
                return true;
            }
        }
    }
    return false;
}

uint64_t Function(const int& limit)
{ 
    std::vector<State> abundants(limit);
    uint64_t total(0);
    for (int n(1); n <= limit; ++n)
    {
        const int sum(static_cast<int>(ProperDivisorSum(n)));
        if (sum > n)
        {
            abundants[n - 1].abundant = true;
            abundants[n - 1].n = sum;
//            if (n % 2 == 0 && !abundants[n / 2 - 1].abundant)
//            {
//                Log(std::to_string(n) + " abundant and is not double of another");
//            }
        }
        if (!IsSumOfPreviousAbundants(n, abundants))
        {
            Log(std::to_string(n) + " NOT sum of other abundants");
            total += n;
        }
    }

//    PrintAbundants(abundants);

//    CleanNonAbundants(-1, abundants);

    return total;
//    return static_cast<uint64_t>(std::count_if(abundants.begin(), abundants.end(),
//                                               [] (const State& state) { return state.n != -1; }));
} 
 
}  // namespace 
 
Problem023::Problem023(const int& limit) : BaseRunnable(Function(limit)) {}
