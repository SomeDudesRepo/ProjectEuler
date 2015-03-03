#include "problem011.h"

#include <algorithm>
#include <cassert>
#include <regex>
#include <vector>

#include "../../log.h"

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
    std::vector<uint64_t> nums(m, 1);
    uint64_t vTemp(1),hTemp(1);
    for (int i(0); i < m; ++i)
    {
        hTemp = 1;
        vTemp = 1;
        for (int j(0); j < m; ++j)
        {
            hTemp *= grid[x + i][y + j];
            vTemp *= grid[y + j][x + i];
            if (i == j)
                nums[m - 2] *= grid[x + i][y + j];
            if (i + j == m - 1)
                nums[m - 1] *= grid[x + i][y + j];
        }
        if (hTemp > nums[m - 4])
            nums[m - 4] = hTemp;
        if (vTemp > nums[m - 3])
            nums[m - 3] = vTemp;
    }
    Log("x: " + std::to_string(x) +
        ", y: " + std::to_string(y) +
        ", row: " + std::to_string(nums[0]) +
        ", col: " + std::to_string(nums[1]) +
        ", f: " + std::to_string(nums[2]) +
        ", r: " + std::to_string(nums[3]));
    return *std::max_element(nums.begin(), nums.end());
}

uint64_t GetLargestSubsetProduct(const int& m, const int& n, const std::string& array)
{
    Grid grid = GetGrid(n, array);
    uint64_t prod(0), temp(0);
    for (int i(0); i < n - m + 1; ++i)
    {
        for (int j(0); j < n - m + 1; ++j)
        {
            if ((temp = ProcessSubGrid(grid, i, j, m)) > prod)
                prod = temp;
        }
    }
    return prod;
}

}  // namespace

Problem011::Problem011(const int& m, const int& n, const std::string& array)
    :   BaseRunnable(GetLargestSubsetProduct(m, n, array)) {}
