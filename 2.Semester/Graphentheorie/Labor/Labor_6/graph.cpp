//
// Created by ANDREI on 05/06/2024.
//

#include "graph.h"
#include <fstream>
#include <stdexcept>

Graph::Graph(const std::string& filename) {
    readFromFile(filename);
}

void Graph::readFromFile(const std::string &filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file");
    }

    file >> n >> m; //noduri si muchii
    file >> s >> t; //quelle si senke

    //initializam cu 0
    capacity.resize(n, std::vector<int>(n, 0));
    flow.resize(n, std::vector<int>(n, 0));

    for (int i = 0; i < m; ++i) { //citim fiecare muchie
        int u, v, cap, fl;
        file >> u >> v >> cap >> fl;
        capacity[u][v] = cap; //seteaza capacitatea pentru muchii
        flow[u][v] = fl; //seteaza flow-ul pentr muchii
    }

    file.close();
}

bool Graph::isValidFlow() const {
    for (int u = 0; u < n; ++u) { //trecem prin fiecare nod
        for (int v = 0; v < n; ++v) { //trecem prin fiecare nod, x2
            if (flow[u][v] > capacity[u][v]) { //verificam daca flow-ul depaseste capacitatea
                return false;
            }
        }
    }

    std::vector<int> netFlow(n, 0); //initializam net-flow pentru fiecare nod
    for (int u = 0; u < n; ++u) { //trecem prin fiecare nod
        for (int v = 0; v < n; ++v) { //trecem prin fiecare nod
            netFlow[u] -= flow[u][v]; //calculeaza flow-ul de iesire
            netFlow[v] += flow[u][v]; //calculeaza flow-ul de intrare
        }
    }

    return netFlow[s] == -netFlow[t] && netFlow[s] >= 0 && netFlow[t] <= 0;
}

Graph Graph::createResidualNetwork() const {
    Graph residual(*this); //cream o copie a grafului
    for (int u = 0; u < n; ++u) { //trecem prin fiecare nod
        for (int v = 0; v < n; ++v) { //trecem prin fiecare nod
            residual.capacity[u][v] = capacity[u][v] - flow[u][v]; //ajusteaza capacitatea pentru forward
            residual.capacity[v][u] = flow[u][v]; //ajusteaza capacitatea pentru reverse
        }
    }
    return residual;
}