#include "problem015.h"

#include <algorithm>
#include <vector>

#include "../../log.h" 
 
namespace 
{ 

std::vector<uint64_t> Factors(int n, int limit)
{
    std::vector<uint64_t> v(n - limit + 1);
    std::generate(v.begin(), v.end(), [&]{ return n--; });
    return v;
}

void Simplify(std::vector<uint64_t>& top, std::vector<uint64_t>& bot)
{
    for (auto& b : bot)
    {
        for (auto& t : top)
        {
            if(t % b != 0)
                continue;
//            Log("b: " + std::to_string(b) + ", t: " + std::to_string(t));
            t /= b;
            b = 1;
            break;
        }
    }
}

uint64_t RunVectorProduct(const std::vector<uint64_t>& top, const std::vector<uint64_t>& bot)
{
    uint64_t t(1), b(1);
    std::for_each(top.begin(), top.end(), [&t](const uint64_t& n){ t *= n; });
    std::for_each(bot.begin(), bot.end(), [&b](const uint64_t& n){ b *= n; });
    Log("Paths: " + std::to_string(t / b));
    return t / b;
}

uint64_t Paths(int m)
{
    auto vTop = Factors(2 * m - 1, m + 1);
    auto vBot = Factors(m - 1, 3);
//    for (auto i : vTop)
//        Log("Top: " + std::to_string(i));
//    for (auto i : vBot)
//        Log("Bottom: " + std::to_string(i));
    Simplify(vTop, vBot);
    for (auto i : vTop)
        Log("Top: " + std::to_string(i));
    for (auto i : vBot)
        Log("Bottom: " + std::to_string(i));
    return RunVectorProduct(vTop, vBot);
}
 
}  // namespace 
 
Problem015::Problem015(const int& gridSize) : BaseRunnable(Paths(gridSize)) {}
