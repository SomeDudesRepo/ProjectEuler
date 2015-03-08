#include "problem017.h" 

#include <string>

#include "../../log.h" 
 
namespace 
{ 

const std::string kUnits[] = {"one","two","three","four","five","six","seven","eight","nine"};
const std::string kTeens[] = {"eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
const std::string kTens[] = {"ten","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
const std::string kAnd("and");
const std::string kHundred("hundred");

uint64_t GenerateNumber(int n)
{
    std::string number;
    if (n < 10)
        number = kUnits[n - 1];
    else if (n == 10)
        number = kTens[0];
    else if (n < 20)
        number = kTeens[n - 11];
    else if (n < 100)
        number = kTens[n / 10 - 1] + (n % 10 == 0 ? "" : kUnits[n % 10 - 1]);
    else if (n < 1000)
    {
        const int h(n / 100), t(n % 100 / 10), u(n % 10);
        std::string temp(kUnits[h - 1] + kHundred);
        if (t != 0 || u != 0)
        {
            temp += kAnd;
            if (t == 1 && u != 0)
            {
                temp += kTeens[u - 1];
            }
            else
            {
                if (t != 0)
                    temp += kTens[t - 1];
                if (u != 0)
                    temp += kUnits[u - 1];
            }
        }
        number = temp;
    }
    else
        number = "onethousand";
    Log(number + ": " + std::to_string(number.size()));
    return number.size();
}

uint64_t GenerateNumbers(int limit)
{
    uint64_t count(0);
    for (int n(1); n <= limit; ++n)
        count += GenerateNumber(n);
    return count;
}

uint64_t Function(const int& limit)
{ 
    return GenerateNumbers(limit);
//    return 0;
} 
 
}  // namespace 
 
Problem017::Problem017(const int& limit) : BaseRunnable(Function(limit)) {}
