#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <vector>
#include "shop.h"

class FruitRepository {
public:
    void addProduct(const Product& product);
    void removeProduct(const std::string& productName);
    void listProductsByOrigin(const std::string& origin) const;
    void listAllProducts() const;
    void listLowStockProducts() const;
    std::vector<Product> getAllProducts() const;

private:
    std::vector<Product> products;
};

#endif // REPOSITORY_H
