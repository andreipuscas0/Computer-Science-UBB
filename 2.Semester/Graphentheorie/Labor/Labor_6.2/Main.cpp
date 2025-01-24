#include "Graph.h"
#include <iostream>
#include <vector>

int main() {
        Graph g("graph.txt");
        std::vector<std::pair<int, int>> matching = g.hungarianAlgorithm();

        std::cout << "Maximum matching:" << std::endl;
        for (const auto &match: matching) {
            std::cout << match.first << " - " << match.second << std::endl;
        }

        return 0;
}