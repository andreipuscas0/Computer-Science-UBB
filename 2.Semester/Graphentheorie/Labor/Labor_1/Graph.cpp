#include "Graph.h"
#include <fstream>
#include <iostream>

using namespace std;

Graph::Graph(const string& file) {
    ifstream inputFile(file);


    inputFile >> n;
    int m;
    inputFile >> m;

    for (int i = 0; i < m; ++i) {
        int u, v;
        inputFile >> u >> v;
        edges.push_back(make_pair(u, v));
    }

    inputFile.close();
}

void Graph::printEdges() {
    for (const auto &edge: edges) {
        cout << edge.first << " " << edge.second << endl;
    }
}

Graph Graph::Durchschnitt(const Graph& graph1) {
    Graph durchschnittGraph;

    durchschnittGraph.edges = edges;
    durchschnittGraph.n = n;

    for (const auto &edge: graph1.edges) {
        if (find(durchschnittGraph.edges.begin(), durchschnittGraph.edges.end(), edge) ==
            durchschnittGraph.edges.end()) {
            durchschnittGraph.edges.push_back(edge);
            durchschnittGraph.n = max(durchschnittGraph.n, max(edge.first, edge.second));
        }
    }
    return durchschnittGraph;
}

void Graph::writeDurchschnittToFile(const std::string& filename) {
    std::ofstream outputFile(filename);

    // Scriem nodurile comune pe prima linie
    outputFile << "Nodurile comune:\n";
    for (int i = 1; i <= n; ++i) {
        outputFile << i << " ";
    }
    outputFile << "\n";

    // Scriem toate marginile
    outputFile << "Marginile:\n";
    for (const auto &edge: edges) {
        outputFile << edge.first << " " << edge.second << "\n";
    }

    outputFile.close();
}