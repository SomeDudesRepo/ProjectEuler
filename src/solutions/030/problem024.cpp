#include "problem024.h" 
 
#include "../../log.h" 
#include "../../ttmath/ttmath.h"

namespace 
{ 

using namespace ttmath;
typedef Big<1,64> MyBig;

std::string ShiftDigit(std::string base, const int& shift)
{
    const auto c(base.at(shift));
    base.replace(shift, 1, "");
    base.insert(base.begin(), 1, c);
    return base;
}

std::string NthPermutation(const std::string& base, const int& nth)
{
    std::string s(base);
    int element(nth),
        rowCount(base.size()),
        columnCount(Factorial(MyBig(rowCount - 1)).ToInt()),
        desiredRow(0);
    std::vector<char> v;
    while (element > 1)
    {
        desiredRow = static_cast<int>(std::ceil(double(element) / double(columnCount)));
        // Swap chars
        const size_t pos(desiredRow - 1);
        v.push_back(s.at(pos));
        s.replace(pos, 1, "");

        // Rework details
        --rowCount;
        element = element - (columnCount * (desiredRow - 1));
        columnCount = Factorial(MyBig(rowCount - 1)).ToInt();
    }
    s.insert(std::begin(s), std::begin(v), std::end(v));
    return s;
}
 
uint64_t Function(const std::string& base, const int& nth)
{
    Log(NthPermutation(base, 1));
    Log(NthPermutation(base, Factorial(MyBig(base.size())).ToInt()));
    const std::string perm(NthPermutation(base, nth));
    Log(perm);
    return std::stoull(perm);
} 
 
}  // namespace 
 
Problem024::Problem024(const std::string& base, const int& nth)
    : BaseRunnable(Function(base, nth)) {}
