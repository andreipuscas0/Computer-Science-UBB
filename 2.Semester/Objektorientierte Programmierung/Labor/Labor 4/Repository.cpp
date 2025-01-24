#include "repository.h"
#include <iostream>
#include <algorithm>

void FruitRepository::addProduct(const Product& product) {
    products.push_back(product);
}

void FruitRepository::removeProduct(const std::string& productName) {
    products.erase(std::remove_if(products.begin(), products.end(),
                                  [&](const Product& p) { return p.getName() == productName; }),
                   products.end());
}

std::vector<Product> FruitRepository::getAllProducts() const {
    return products;
}

void FruitRepository::listProductsByOrigin(const std::string& origin) const {
    std::cout << "Products from " << origin << ":\n";
    for (const auto& product : products) {
        if (product.getOrigin() == origin) {
            std::cout << product.getName() << " (Qty: " << product.getQuantity() << ")\n";
        }
    }
}

void FruitRepository::listAllProducts() const {
    std::cout << "All products in the repository:\n";
    for (const auto& product : products) {
        std::cout << product.getName() << " (Qty: " << product.getQuantity() << ")\n";
    }
}

void FruitRepository::listLowStockProducts() const {
    std::cout << "Low stock products:\n";
    for (const auto& product : products) {
        if (product.getQuantity() < 10) {
            std::cout << product.getName() << " (Qty: " << product.getQuantity() << ")\n";
        }
    }
}
