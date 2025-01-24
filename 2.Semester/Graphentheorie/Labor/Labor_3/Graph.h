#ifndef LABOR_3_GRAPH_H
#define LABOR_3_GRAPH_H

#include <vector>
#include <string>


class Graph {
private:
    int num_knoten;
    std::vector<std::pair<int, int>> kanten;
    std::vector<bool> visited; //vizitate

public:
    Graph(std::string dateiname);

    void kantenPrint(); //printeaza kanten-urile
    void BFS(int x); // cauta de la nodul x

};

#endif //LABOR_3_GRAPH_H
