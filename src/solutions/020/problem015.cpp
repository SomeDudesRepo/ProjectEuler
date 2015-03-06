#include "problem015.h" 
 
#include "../../log.h" 
 
namespace 
{ 

uint64_t Factorial(const int& i, const int& limit)
{
    uint64_t fact(1);
    for (int j(i); j > limit; --j)
        fact *= j;
//    Log(std::to_string(i) + "! = " + std::to_string(fact));
    return fact;
}

uint64_t GetPaths(const int& n, const int& m)
{
    const int n_m(n - m);
    int limit(n_m >= m ? n_m : m), div(n_m >= m ? m : n_m);
    return Factorial(n, limit) / Factorial(div, 1);
}

uint64_t NumberOfPaths(const int& gridSize)
{ 
    const int m(gridSize), n(gridSize * 2 - 1);
    Log("m: " + std::to_string(m) + ", n: " + std::to_string(n));
//    const uint64_t paths(Factorial(n - 1) / (Factorial(n - m) * Factorial(m - 1)));
    return GetPaths(n - 1, m - 1);
} 
 
}  // namespace 
 
Problem015::Problem015(const int& gridSize) : BaseRunnable(NumberOfPaths(gridSize)) {}
