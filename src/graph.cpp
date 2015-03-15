#include "graph.h"

#include <set>

template<>
std::string ToStdString<std::string>(const std::string& v)
{
    return v;
}

const std::string kWords[] =
{
    "FOOL",
    "POOL",
    "POLL",
    "POLE",
    "PALE",
    "SALE",
    "SAGE"
};

void ConstructGraph()
{
    std::map<std::string, std::set<std::string>> map;
    for (const auto& word : kWords)
    {
        Log("Options for " + word + ": ");
        for (size_t n(0); n != word.size(); ++n)
        {
            const std::string bucket(word.substr(0, n) + "_" + word.substr(n + 1));
            Log(bucket);
            if (map.find(bucket) == map.end())
                map[bucket] = std::set<std::string>();
            map[bucket].insert(word);
        }
    }

    Graph<std::string> g;
    for (const auto& pair : map)
    {
        for (const auto& w1 : pair.second)
            for (const auto& w2 : pair.second)
                if (w1 != w2)
                    g.AddEdge(w1, w2);
    }

    g.PrintAdjacencyList();
}
