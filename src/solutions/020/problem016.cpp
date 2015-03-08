#include "problem016.h" 

#include <cstdint>
#include <string>
#include <vector>

#include "../../log.h"
 
namespace 
{

std::string Square(const std::string& n)
{
    std::vector<std::string> rows;
    for (int i(0); i < n.size(); ++i)
    {
        rows.push_back(std::string(i, '0'));
    }
    return "";
}
 
uint64_t Function() 
{ 
    const std::uint64_t two_32(std::numeric_limits<uint64_t>::max() / 2);
    const std::string s232(std::to_string(two_32));
    Log("max: " + s232);
    long double d = std::pow(2, 1000);
    Log("d: " + std::to_string(d));

    return 0;
} 
 
}  // namespace 
 
Problem016::Problem016() : BaseRunnable(Function()) {} 
