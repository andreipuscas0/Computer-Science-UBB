#include "Graph.h"

#include<iostream>
#include<fstream>

using namespace std;

int main(){

    Graph graph1("graph1.in");
    Graph graph2("graph2.in");

    Graph durchschnittGraph = graph1.Durchschnitt(graph2);
    durchschnittGraph.writeDurchschnittToFile("durchschnitt_graph.txt");
        return 0;
}
