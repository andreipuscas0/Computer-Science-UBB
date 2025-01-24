#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <list>
#include <string>

class Graph {

private:
    int n;
    int m;
    std::vector<std::list<int>> adjList;

public:
    Graph(const std::string &filename );

    void printGraph() const;

    void graphColor();

};

#endif // GRAPH_H
