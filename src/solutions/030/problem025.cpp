#include "problem025.h"

#include <string>
 
#include "../../log.h"
#include "../../ttmath/ttmath.h"

namespace 
{ 
 
uint64_t Function(const int& n)
{ 
    ttmath::UInt<10000> fibonacci1, fibonacci2, fibonacci3;
    fibonacci1 = 1;
    fibonacci2 = 1;

    int i(2);
    std::string s;
    for (; s.size() < size_t(n); ++i)
    {
        fibonacci3 = fibonacci1 + fibonacci2;
        fibonacci1 = fibonacci2;
        fibonacci2 = fibonacci3;
        std::stringstream ss;
        ss << fibonacci2;
        s = ss.str();
    }

    return i;
} 
 
}  // namespace 
 
Problem025::Problem025(const int& n) : BaseRunnable(Function(n)) {}
