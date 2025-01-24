#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

class Graph {

private:

    int n;
    vector<pair<int, int>> edges;
    
public:

    Graph();
    Graph(const string&);
    void printEdges();
    Graph Durchschnitt(const Graph& graph1);
    void writeDurchschnittToFile(const std::string& filename);

//    void addEdge(int x, int y);
//
//    bool isEdge(int x, int y);
//
//    void printGraph();

};