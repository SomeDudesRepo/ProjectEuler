#include "problem022.h"

#include <algorithm>
#include <regex>
#include <string>
#include <vector>

#include "../../filelinereader.h"
#include "../../log.h"

namespace 
{ 

std::string RemoveQuotes(std::string s)
{
    size_t pos(0);
    while ((pos = s.find("\"")) != std::string::npos)
        s = s.replace(pos, 1, "");
    return s;
}

uint64_t CalculateNameValue(const std::string& name)
{
    int sum(-64 * name.size());
    for (auto c : name)
        sum += static_cast<int>(c);
    return static_cast<uint64_t>(sum);
}

uint64_t Function(const std::string& path)
{ 
    auto lines = GetFileLines(path);
    const std::string array(lines.at(0));
    lines.clear();
    std::regex ws_re(",");
    std::sregex_token_iterator it(array.begin(), array.end(), ws_re, -1);
    for (; it != std::sregex_token_iterator(); ++it)
        lines.push_back(RemoveQuotes(*it));

    std::sort(lines.begin(), lines.end());
//    Log(lines[937]);

    uint64_t count(0), temp(0);
    for (size_t n(0); n != lines.size(); ++n)
    {
        temp = CalculateNameValue(lines[n]);
        Log(lines[n] + " = " + std::to_string(temp));
        temp *= (n + 1);
        Log(lines[n] + " = " + std::to_string(temp));
        count += temp;
    }

    return count;
} 
 
}  // namespace 
 
Problem022::Problem022(const std::string& path) : BaseRunnable(Function(path)) {}
