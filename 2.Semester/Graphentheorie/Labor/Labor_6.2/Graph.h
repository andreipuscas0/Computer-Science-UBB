#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <string>

class Graph {
public:
    Graph(const std::string& filename); //Constructor
    std::vector<std::pair<int, int>> hungarianAlgorithm(); //algoritmul

private:
    int n; //noduri
    int m; //muchii
    std::vector<std::vector<int>> adjMatrix; //matricea de adiacență

    void initializeMatrix();
    bool bpm(int u, std::vector<bool>& seen, std::vector<int>& match);
};

#endif // GRAPH_H
