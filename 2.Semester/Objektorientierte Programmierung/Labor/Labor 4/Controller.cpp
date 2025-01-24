#include "controller.h"

void Controller::run() {

    repository.addProduct(Product("Banana", "Afrika", "2024-05-20", 200, 1.49));
    repository.addProduct(Product("Apple", "Romania", "2024-10-30", 1000, 0.99));
    repository.addProduct(Product("Cherry", "Spain", "2024-06-05", 150, 4.99));
    repository.addProduct(Product("Grapes", "Romania", "2024-05-01", 300, 2.89));
    ui.handleUserInput(repository);

}
