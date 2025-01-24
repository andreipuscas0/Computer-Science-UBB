#include "graph.h"
#include <iostream>

int main() {

    try {
        Graph g("graph.txt");

        if (g.isValidFlow()) {
            std::cout << "The flow is valid" << std::endl;
        }
        else {
            std::cout << "The flow is valid" << std::endl;
        }

        Graph residual = g.createResidualNetwork();
        std::cout << "Network created successfully" << std::endl;

    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
