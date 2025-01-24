#include  "Graph.h"
#include <fstream>
#include <iostream>
#include <queue>
#include <algorithm>

Graph::Graph(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Unable to open file");
    }

    file >> n >> m;
    adjMatrix.resize(n, std::vector<int>(n, 0));

    int u, v;
    for (int i = 0; i < m; ++i) {
        file >> u >> v;
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;//pentru că graful este nedirecționat
    }
}

bool Graph::bpm(int u, std::vector<bool>& seen, std::vector<int>& match) {
    for (int v = 0; v < n; v++) {
        if (adjMatrix[u][v] && !seen[v]) {
            seen[v] = true;
            if (match[v] < 0 || bpm(match[v], seen, match)) {
                match[v] = u;
                return true;
            }
        }
    }
    return false;
}

std::vector<std::pair<int, int>> Graph::hungarianAlgorithm() {
    std::vector<int> match(n, -1);
    int result = 0;
    for (int u = 0; u < n; u++) {
        std::vector<bool> seen(n, false);
        if (bpm(u, seen, match)) {
            result++;
        }
    }

    std::vector<std::pair<int, int>> matching;
    for (int v = 0; v < n; v++) {
        if (match[v] != -1) {
            matching.emplace_back(match[v], v);
        }
    }
    return matching;
}
