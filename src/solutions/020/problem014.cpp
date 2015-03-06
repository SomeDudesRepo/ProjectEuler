#include "problem014.h"

#include <algorithm>
#include <map>
#include <memory>
#include <vector>

#include "../../log.h" 
 
namespace 
{

typedef std::map<uint64_t, uint64_t> Power2Map;
typedef std::map<uint64_t, uint64_t> CollatzLengths;

Power2Map MultiplesOf2(const int& limit)
{
    Power2Map result;
    int count(0);
    while (count <= limit)
    {
        result.insert(std::make_pair(static_cast<uint64_t>(std::pow(2, count)), count));
        ++count;
    }
    return result;
}

uint64_t CollatzNext(const uint64_t& n)
{
    return n % 2 == 0 ? n / 2 : 3 * n + 1;
}

void CountCollatzLength(const uint64_t& n, CollatzLengths& lengths)
{
    if (lengths.find(n) != lengths.end())
    {
//        Log(std::to_string(n) + " already in map");
        return;
    }

    std::vector<uint64_t> v(1, n);
    uint64_t current(n);
    for(;;)
    {
        const uint64_t next(CollatzNext(current));
        if (next == 1)
        {
            lengths[n] = v.size() + 1;
//            Log("Got to 1 with " + std::to_string(n));
            return;
        }

        auto it = lengths.find(next);
        if (it == lengths.end())
        {
            v.push_back(next);
            current = next;
//            Log("Another round: " + std::to_string(current));
        }
        else
        {
            lengths[n] = v.size() + it->second;
//            Log("Found previous result for " + std::to_string(next) +
//                " when analysing " + std::to_string(n));
            return;
        }
    }
}

bool CollatzLengthsCompare(const CollatzLengths::value_type& lhs,
                           const CollatzLengths::value_type& rhs)
{
    return lhs.second < rhs.second;
}

void PrintCollatzLengths(const CollatzLengths& lengths)
{
    for (const auto& pair : lengths)
        Log(std::to_string(pair.first) + " --> " + std::to_string(pair.second));
}

uint64_t LargestCollatzSequence(const int &limit)
{ 
//    uint64_t longest(0);
    Power2Map pw2Map(MultiplesOf2(limit));
    std::unique_ptr<CollatzLengths> lengths(new CollatzLengths);
    for (int n(1); n <= limit; ++n)
    {
//        Log("Checking " + std::to_string(n));
        CountCollatzLength(n , *lengths);
    }
//    PrintCollatzLengths(*lengths);
    return std::max_element(lengths->begin(), lengths->end(), CollatzLengthsCompare)->first;
} 

uint64_t LCS(const int &limit)
{
    int longest = 0;
    int terms = 0;
    int i;
    unsigned long j;
    for (i = 1; i <= limit; i++)
    {
        j = i;
        int this_terms = 1;
        while (j != 1)
        {
            this_terms++;
            if (this_terms > terms)
            {
                terms = this_terms;
                longest = i;
            }
            if (j % 2 == 0)
            {
                j = j / 2;
            }
            else
            {
                j = 3 * j + 1;
            }
        }
    }
    return longest;
}

}  // namespace 
 
Problem014::Problem014(const int &limit) : BaseRunnable(LargestCollatzSequence(limit)) {}
