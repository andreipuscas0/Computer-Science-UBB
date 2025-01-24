#include "Graph.h"
#include <fstream>


Graph::Graph(const std::string &filename ) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Unable to open file";
        exit(1);
    }

    file >> n >> m;
    adjList.resize(n);

    int node1, node2;
    for (int i = 0; i < m; ++i) {
        file >> node1 >> node2;
        adjList[node1].push_back(node2);
        adjList[node2].push_back(node1);
    }

    file.close();
}

void Graph::printGraph() const {
    for (int i = 0; i < n; i++) {
        std::cout << i << ":";
        for (auto node : adjList[i])
            std::cout << " " << node;
        std::cout << std::endl;
    }
}

void Graph::graphColor() {
    std::vector<int> result(n, -1);
    result[0] = 0;

    std::vector<bool> available(n, true);

    for (int u = 1; u < n; ++u) {
        for (auto i: adjList[u]) {

        }

    }
}