#include "problem016.h" 

#include <cstdint>
#include <string>
#include <vector>

#include "../../log.h"
#include "../../ttmath/ttmath.h"

namespace 
{

uint64_t Function(const int& power)
{ 
    using namespace ttmath;
    typedef Big<1,64> MyBig;
    MyBig x = 2;
    x.PowUInt(power);

    std::string s;
    x.ToString(s, 10, false);
    Log(std::to_string(2) + "^" + std::to_string(power)  + " = " + s);

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
 
Problem016::Problem016(const int& power) : BaseRunnable(Function(power)) {}
