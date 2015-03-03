#include "problem011.h"

#include <algorithm>
#include <cassert>
#include <regex>
#include <vector>

#include "../../log.h"
#include "../../primes.h"

namespace
{

typedef std::vector<std::vector<int>> Grid;
Grid GetGrid(const int& n, const std::string& array)
{
    std::vector<std::string> line;
    std::regex ws_re(",");
    std::copy(std::sregex_token_iterator(array.begin(), array.end(), ws_re, -1),
              std::sregex_token_iterator(),
              std::back_inserter(line));
    Log("Line: " + std::to_string(line.size()));
    assert(line.size() == size_t(n * n));
    Grid grid(1, Grid::value_type());
    int i(0);
    for (const auto& s : line)
    {
        grid.at(i).push_back(std::stoi(s));
        if (grid.at(i).size() == size_t(n) && grid.size() < size_t(n))
        {
            grid.push_back(Grid::value_type());
            ++i;
        }
    }
    Log("Grid: " + std::to_string(grid.size()));
    assert(grid.size() == size_t(n));
    return grid;
}

uint64_t ProcessSubGrid(const Grid& grid, const int& x, const int& y, const int& m)
{
    std::vector<uint64_t> results(10, 0);
    for (int i(0); i < m; ++i)
    {
        for (int j(0); j < m; ++j)
        {

        }
    }
}

uint64_t GetLargestSubsetProduct(const int& m, const int& n, const std::string& array)
{
    Grid grid = GetGrid(n, array);
//    std::vector<uint64_t> primes{2, 3};
    const int i(6), j(8);
    uint64_t sum(0), temp(0);
    for (int i(0); i < n - m; ++i)
    {
        for (int j(0); j < n - m; ++j)
        {
            if ((temp = ProcessSubGrid(grid, i, j, m)) > sum)
                sum = temp;
        }
    }
//    size_t pSize(1), cSize(primes.size());
//    while (cSize != pSize)
//    {
//        Log("sum: " + std::to_string(sum) +
//            ", back: " + std::to_string(primes.back()) +
//            ", size: " + std::to_string(primes.size()));
//        sum += primes.back();
//        GetNextPrime(primes, limit);
//        pSize = cSize;
//        cSize = primes.size();
//    }
    return sum;
}

}  // namespace

Problem011::Problem011(const int& m, const int& n, const std::string& array)
    :   BaseRunnable(GetLargestSubsetProduct(m, n, array)) {}
