#include "problem08.h"

#include <cassert>
#include <string>

#include "../log.h"

namespace
{

uint64_t Product(const std::string& digits)
{
    Log(digits);
    if (digits.find("0") != std::string::npos)
        return 0;

    // Maybe keep executed products to avoid repetition

    uint64_t result(1), test(0);
    for (const char& c : digits)
    {
        const int ch(std::atoi(std::string(1, c).c_str()));
        result *= ch;
        test += ch;
    }

    // Explore the possibility that addition determines prodduct size
    Log("result: " + std::to_string(result) + ", test: " + std::to_string(test));
    return result;
}

uint64_t GetGreatestProduct(const std::string& series, const int& count)
{
    size_t index(0);
    uint64_t candidate(0), temp(0);
    while (index + count < series.size())
    {
        temp = Product(series.substr(index++, count));
        if(temp > candidate)
            candidate = temp;
    }
    return candidate;
}

}  // namespace

Problem08::Problem08(const std::string& series, const int& count)
    :   BaseRunnable(GetGreatestProduct(series, count)) {}
