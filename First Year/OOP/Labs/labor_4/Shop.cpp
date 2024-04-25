#include "shop.h"
#include <algorithm>
#include <iostream>

Product::Product(const std::string& name, const std::string& origin,
                 const std::string& expirationDate, int quantity, double price)
        : name(name), origin(origin), expirationDate(expirationDate), quantity(quantity), price(price) {}

std::string Product::getName() const {
    return name;
}

std::string Product::getOrigin() const {
    return origin;
}

std::string Product::getExpirationDate() const {
    return expirationDate;
}

int Product::getQuantity() const {
    return quantity;
}

double Product::getPrice() const {
    return price;
}

void Product::updateQuantity(int newQuantity) {
    quantity = newQuantity;
}

void FruitStore::addProduct(const Product& product) {
    products.push_back(product);
}

void FruitStore::removeProduct(const std::string& productName) {
    products.erase(std::remove_if(products.begin(), products.end(),
                                  [&](const Product& p) { return p.getName() == productName; }),
                   products.end());
}

void FruitStore::listProductsBySubstring(const std::string& substring) const {
    for (const auto& product : products) {
        if (substring.empty() || product.getName().find(substring) != std::string::npos) {
            std::cout << product.getName() << " (" << product.getOrigin() << ")\n";
        }
    }
}

void FruitStore::listLowStockProducts(int threshold) const {
    for (const auto& product : products) {
        if (product.getQuantity() < threshold) {
            std::cout << product.getName() << " (Qty: " << product.getQuantity() << ")\n";
        }
    }
}

void FruitStore::sortProductsByExpirationDate() {
    std::sort(products.begin(), products.end(),
              [&](const Product& a, const Product& b) { return a.getExpirationDate() < b.getExpirationDate(); });
}
