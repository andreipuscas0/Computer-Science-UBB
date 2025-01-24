//
// Created by ANDREI on 05/06/2024.
//

#ifndef LABOR_6V2_GRAPH_H
#define LABOR_6V2_GRAPH_H

#include <vector>
#include <string>


class Graph {

public:
    Graph(const std::string& filename);

    bool isValidFlow() const;
    Graph createResidualNetwork() const;

private:
    int n; //noduri
    int m; //muchii
    int s; //quelle
    int t; //senke
    std::vector<std::vector<int>> capacity; //matrice de capacity
    std::vector<std::vector<int>> flow; //matrice de flow

    void readFromFile(const std::string& filename);
};


#endif //LABOR_6V2_GRAPH_H
