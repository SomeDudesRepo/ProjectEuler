#include "problem021.h"

#include <map>
 
#include "../../factors.h"
#include "../../log.h"
 
namespace 
{ 

uint64_t Function(const int& limit)
{ 
    typedef std::map<uint64_t, uint64_t> DFunc;
    DFunc dFunc;
    for (uint64_t n(2); n <= limit; ++n)
    {
        const uint64_t sum(ProperDivisorSum(n));
        if (sum == 1)
            continue;
        dFunc[n] = sum;
        Log("d(" + std::to_string(n) + ") = " + std::to_string(sum));
    }

    uint64_t count(0);
    for (const auto& p : dFunc)
    {
        auto iters = dFunc.equal_range(p.second);
        for (auto it = iters.first; it != iters.second; ++it)
        {
            if(p.first != it->second || p.first == it->first)
                continue;

            Log("d(" + std::to_string(p.first) + ") = " + std::to_string(p.second) +
                " and d(" + std::to_string(it->first) + ") = " + std::to_string(it->second));
            count += p.first;
        }
    }

    return count;
} 
 
}  // namespace 
 
Problem021::Problem021(const int& limit) : BaseRunnable(Function(limit)) {}
