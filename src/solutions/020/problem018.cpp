#include "problem018.h" 

#include <algorithm>
#include <cassert>
#include <iterator>
#include <regex>

#include "../../filelinereader.h"
#include "../../log.h" 
 
namespace 
{

std::vector<std::vector<int>> GetNumbersFromLines(const std::vector<std::string>& lines)
{
    std::vector<std::vector<int>> v(lines.size());
    std::regex ws_re(" "); // whitespace
    size_t count(0);
    for (auto& line : lines)
    {
        auto& thisV = v[count];
        for (std::sregex_token_iterator it(line.begin(), line.end(), ws_re, -1);
             it != std::sregex_token_iterator();
             ++it)
            thisV.push_back(std::stoi(std::string(*it)));

        ++count;
    }
    return v;
}

void LogTree(const std::vector<std::vector<int>>& tree)
{
    for (const auto& r : tree)
    {
        std::string s;
        for (const auto& i : r)
            s += std::to_string(i) + " ";
        Log(s);
    }
}

uint64_t ReduceTree(std::vector<std::vector<int>>& tree)
{
    for (int l(static_cast<int>(tree.size() - 2)); l >= 0; --l)
    {
        Log("l: " + std::to_string(l));
        for (int n(0); n != tree[l].size(); ++n)
        {
            Log("l: " + std::to_string(l) + ", n: " + std::to_string(n));
            tree[l][n] = tree[l][n] + std::max(tree[l + 1][n], tree[l + 1][n + 1]);
        }
        LogTree(tree);
    }
    return uint64_t(tree[0][0]);
}
 
uint64_t LargestPathSum(const std::string& path)
{ 
    auto lines = GetFileLines(path);
    auto numbers = GetNumbersFromLines(lines);
    LogTree(numbers);
    return ReduceTree(numbers);
} 
 
}  // namespace 
 
Problem018::Problem018(const std::string& path) : BaseRunnable(LargestPathSum(path)) {}
