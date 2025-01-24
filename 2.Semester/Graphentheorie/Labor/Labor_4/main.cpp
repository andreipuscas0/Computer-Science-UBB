#include "Graph.h"

int main() {
    // Create a graph from file
    Graph graph("graph.txt");

    // Find and print shortest path
    graph.shortestPath(0, 5);

    return 0;
}
