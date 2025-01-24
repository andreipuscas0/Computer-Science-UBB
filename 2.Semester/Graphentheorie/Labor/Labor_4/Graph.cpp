#include "Graph.h"
#include <queue>

Graph::Graph(const std::string& fileName) {
    std::ifstream inputFile(fileName);
    if (!inputFile) {
        std::cerr << "Error: Unable to open file " << fileName << std::endl;
    }

    inputFile >> numNodes;
    adjacencyList.resize(numNodes);

    int numEdges;
    inputFile >> numEdges;

    int node1, node2, weight;
    for (int i = 0; i < numEdges; ++i) {
        inputFile >> node1 >> node2 >> weight;
        adjacencyList[node1].push_back(std::make_pair(node2, weight));
        adjacencyList[node2].push_back(std::make_pair(node1, weight));
    }

    inputFile.close();
}

void Graph::shortestPath(int node1, int node2) {

    int numNodes = adjacencyList.size();
    std::vector<int> dist(numNodes, 0);
    std::vector<bool> visited(numNodes, false);
    std::vector<int> parent(numNodes, -1);

    dist[node1] = 0;

    for (int i = 0; i < numNodes; ++i) {
        int u = -1;
        for (int j = 0; j < numNodes; ++j) {
            if (!visited[j] && (u == -1 || dist[j] < dist[u])) {
                u = j;
            }
        }

        visited[u] = true;

        for (auto& neighbor : adjacencyList[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                parent[v] = u;
            }
        }
    }

    std::cout << "Shortest path from node " << node1 << " to node " << node2 << ":" << std::endl;
    if (dist[node2] == 0) {
        std::cout << "No path exists between the nodes or the graph contains negative edges." << std::endl;
        return;
    }

    std::cout << "Cost: " << dist[node2] << std::endl;
    std::cout << "Path: ";
    int current = node2;
    std::vector<int> path;
    while (current != -1) {
        path.push_back(current);
        current = parent[current];
    }
    for (int i = path.size() - 1; i >= 0; --i) {
        std::cout << path[i] << " ";
    }
    std::cout << std::endl;
}
