#ifndef ATTEMPTS_GRAPH_H
#define ATTEMPTS_GRAPH_H

#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <limits>

class Graph {
private:
    int numNodes;
    std::vector<std::list<std::pair<int, int>>> adjacencyList;

public:

    Graph(const std::string& fileName);

    void shortestPath(int node1, int node2);
};

#endif //ATTEMPTS_GRAPH_H
