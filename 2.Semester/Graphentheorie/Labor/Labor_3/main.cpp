#include <iostream>
#include "Graph.h"

int main() {

    Graph graph("datei_lab3.txt"); //initializam graful cu datele din fisier

    std::cout << "Kanten-urile grafului:" << std::endl;
    graph.kantenPrint();
    std::cout << std::endl;

    std::cout << "Parcurgerea grafului incepand de la Knote 1:" << std::endl;
    graph.BFS(1);

    return 0;
}
