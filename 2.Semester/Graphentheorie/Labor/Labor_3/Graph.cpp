#include "Graph.h"
#include <iostream>
#include <fstream>
#include <vector>


Graph::Graph( std::string dateiname) {
    std::ifstream datei(dateiname);
    if (!datei.is_open()) {
        std::cerr << "Eroare la deschiderea fisierului: " << dateiname << std::endl;
        return;
    }

    datei >> num_knoten;
    int num_kanten;
    datei >> num_kanten;

    kanten.reserve(num_kanten);

    int knoten1, knoten2;
    for (int i = 0; i < num_kanten; ++i) {
        datei >> knoten1 >> knoten2;
        kanten.emplace_back(knoten1, knoten2);
    }

    datei.close();

    // Vector pentru knoten-urile cautate
    visited.resize(num_knoten + 1, false); // +1 pentru indexarea cu 1
}

// Cautarea kanten-urilor
void Graph::kantenPrint() {
    for (const auto& kante : kanten) {
        std::cout << kante.first << " " << kante.second << std::endl;
    }
}

// BFS de la x
void Graph::BFS(int x) {
    std::vector<int> to_visit_knoten;
    to_visit_knoten.push_back(x);
    visited[x] = true;

    while (!to_visit_knoten.empty()) {
        int aktuell = to_visit_knoten[0];
        to_visit_knoten.erase(to_visit_knoten.begin());
        std::cout << aktuell << " ";

        // Vecinii kanten-ului actual
        for (const auto& kante : kanten) {
            int nachbar;
            if (kante.first == aktuell) {
                nachbar = kante.second;
            } else if (kante.second == aktuell) {
                nachbar = kante.first;
            } else {
                continue;
            }

            if (!visited[nachbar]) {
                to_visit_knoten.push_back(nachbar);
                visited[nachbar] = true;
            }
        }
    }
    std::cout << std::endl;
}
