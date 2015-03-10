#include "problem020.h" 
 
#include "../../log.h"
#include "../../ttmath/ttmath.h"
 
namespace 
{ 
 
uint64_t AddDigitsOfFactorial(const int& base)
{ 
    using namespace ttmath;

    typedef Big<1,64> MyBig;
    MyBig x = base;
    CGamma<MyBig> cgamma;
    MyBig f100 = Factorial(x, cgamma);

    std::string s;
    f100.ToString(s, 10, false);
    Log(std::to_string(base) + "! = " + s);

    uint64_t count(0);
    for (auto c : s)
    {
        if (c == 'e')
            break;
        if (c < 48 || c > 57)
            continue;
        count += static_cast<uint64_t>(c - char(48));
    }
    Log("1,64: " + std::to_string(count));
    return count;
} 
 
}  // namespace 
 
Problem020::Problem020(const int& base) : BaseRunnable(AddDigitsOfFactorial(base)) {}
