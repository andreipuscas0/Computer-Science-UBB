#ifndef LABOR_4_SHOP_H
#define LABOR_4_SHOP_H

#include <string>
#include <vector>

class Product {

public:
    Product(const std::string& name, const std::string& origin,
            const std::string& expirationDate, int quantity, double price);

    std::string getName() const;
    std::string getOrigin() const;
    std::string getExpirationDate() const;
    int getQuantity() const;
    double getPrice() const;
    void updateQuantity(int newQuantity);

private:
    std::string name;
    std::string origin;
    std::string expirationDate;
    int quantity;
    double price;
};

class FruitStore {

public:
    void addProduct(const Product& product);
    void removeProduct(const std::string& productName);
    void listProductsBySubstring(const std::string& substring) const;
    void listLowStockProducts(int threshold) const;
    void sortProductsByExpirationDate();

private:
    std::vector<Product> products;
};


#endif //LABOR_4_SHOP_H
