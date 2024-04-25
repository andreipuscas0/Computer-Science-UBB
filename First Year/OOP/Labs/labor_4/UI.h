#ifndef UI_H
#define UI_H

#include "repository.h"

class FruitUI {

public:
    void displayMenu() const;
    void handleUserInput(FruitRepository& repository);

private:
    void addProduct(FruitRepository& repository);
    void removeProduct(FruitRepository& repository);
    void listProductsByOrigin(FruitRepository& repository) const;
    void listAllProducts(FruitRepository& repository) const;
    void listLowStockProducts(FruitRepository& repository) const;
};

#endif // UI_H
