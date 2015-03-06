#include "problem013.h"

#include <cassert>
#include <vector>

#include "../../log.h"
#include "../../filelinereader.h"

namespace
{

int CheckDigitsPerLine(std::vector<std::string>& lines, const size_t& limit)
{
    size_t length(0);
    for (auto& l : lines)
    {
        if (length == 0)
            length = l.size();
        else
            assert(length == l.size());
        if (l.size() < limit)
            throw std::string("Not enough digits on the line: " + l);
    }
    return length;
}

uint64_t NDigitDSum(const std::string& path, const int& limit)
{
    auto lines = GetFileLines(path);
    int length(CheckDigitsPerLine(lines, limit));
    std::string result;
    int carry(0), sum(0);
    for (int point(1); point <= length; ++point)
    {
        for (const auto& l : lines)
        {
            const char c(l.at(l.size() - point));
            const int i(std::stoi(std::string(1, c)));
            sum += i;
        }
        Log("----------- point: " + std::to_string(point));
        Log("carry: " + std::to_string(carry) + ", "
            "result: " + result + ", "
            "sum: " + std::to_string(sum));
        sum += carry;
        result.insert(result.begin(), 1, std::to_string(sum % 10).back());
        carry = sum / 10;
        sum = 0;
        Log("carry: " + std::to_string(carry) + ", "
            "result: " + result + ", "
            "sum: " + std::to_string(sum));
    }
    if (carry != 0)
    {
        const std::string sCarry(std::to_string(carry));
        result.insert(result.begin(), sCarry.begin(), sCarry.end());
    }

    return std::stoull(result.substr(0, limit));
}

}  // namespace

Problem013::Problem013(const std::string& path, const int& limit)
    :   BaseRunnable(NDigitDSum(path, limit)) {}
