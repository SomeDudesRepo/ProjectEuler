#ifndef GRAPH_H
#define GRAPH_H

#include <map>
#include <utility>
#include <vector>

#include "log.h"

template <typename Vertex>
std::string ToStdString(const Vertex& v);

template <typename Vertex>
class Graph
{
public:
    typedef int Weight;
    typedef std::pair<Vertex, Weight> Edge;
    typedef std::vector<Edge> AdjacentList;
    typedef std::map<Vertex, AdjacentList> AdjacentLists;

    Graph() : mLists() {}

    void AddEdge(const Vertex& from, const Vertex& to)
    {
        AddEdge(from, to, Weight(0));
    }

    void AddEdge(const Vertex& from, const Vertex& to, const Weight& w)
    {
        if (mLists.find(to) == mLists.end())
            mLists[to] = AdjacentList();

        auto it = mLists.find(from);
        if (it == mLists.end())
            mLists[from] = AdjacentList(1, Edge(to, w));
        else
            mLists[from].push_back(Edge(to, w));
    }

    void PrintAdjacencyList() const
    {
        for (const auto& p : mLists)
        {
            std::string row(ToStdString<Vertex>(p.first) + ": ");
            for (const auto& e : p.second)
                row += "{" + ToStdString<Vertex>(e.first) + "," + std::to_string(e.second) + "}";
            Log(row);
        }
    }

private:
    AdjacentLists mLists;
};

void ConstructGraph();

#endif // GRAPH_H
