#include "problem013.h"

#include <vector>

#include "../../log.h"
#include "../../filelinereader.h"

namespace
{

void CheckDigitsPerLine(const std::vector<std::string>& lines, const size_t& limit)
{
    for (const auto& l : lines)
    {
        if (l.size() < limit)
            throw std::string("Not enough digits on the line: " + l);
    }
}

uint64_t NDigitDSum(const std::string& path, const int& limit)
{
    auto lines = GetFileLines(path);
    CheckDigitsPerLine(lines, limit);
    std::string result(limit, 'a');
    int carry(0), sum(0);
    for (int point(1); point <= limit; ++point)
    {
        for (const auto& l : lines)
        {
            const char c(l.at(l.size() - point));
            const int i(std::stoi(std::string(1, c)));
            sum += i;
            Log("point: " + std::to_string(point) + ", "
                "line: " + l + ", "
                "i:" + std::to_string(i) + ", "
                "sum: " + std::to_string(sum));
        }
        Log("carry: " + std::to_string(carry) + ", "
            "result: " + result + ", "
            "sum: " + std::to_string(sum));
        sum += carry;
        result.at(limit - point) = std::to_string(sum % 10).back();
        carry = sum / 10;
        sum = 0;
        Log("carry: " + std::to_string(carry) + ", "
            "result: " + result + ", "
            "sum: " + std::to_string(sum));
    }
    if (result.at(0) == '0')
    {
        if (carry == 0)
            result.insert(result.begin(), 1, '1');
        else
            result.insert(result.begin(), 1, std::to_string(carry % 10).back());
    }
    return std::stoull(result);
}

}  // namespace

Problem013::Problem013(const std::string& path, const int& limit)
    :   BaseRunnable(NDigitDSum(path, limit)) {}
