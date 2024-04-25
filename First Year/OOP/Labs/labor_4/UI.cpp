#include "ui.h"
#include <iostream>

void FruitUI::displayMenu() const {
    std::cout << "Fruit Store Management Menu:\n";
    std::cout << "1. Add Product\n";
    std::cout << "2. Remove Product\n";
    std::cout << "3. List Products by Origin\n";
    std::cout << "4. List All Products\n";
    std::cout << "5. List Low Stock Products\n";
    std::cout << "6. Exit\n";
}

void FruitUI::handleUserInput(FruitRepository& repository) {
    int choice;
    while(choice != 6) {
        displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addProduct(repository);
                break;
            case 2:
                removeProduct(repository);
                break;
            case 3:
                listProductsByOrigin(repository);
                break;
            case 4:
                listAllProducts(repository);
                break;
            case 5:
                listLowStockProducts(repository);
                break;
            case 6:
                std::cout << "Exiting the application. Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice. Try something else.\n";
        }
    }
}

void FruitUI::addProduct(FruitRepository& repository) {
    std::string name, origin, expirationDate;
    int quantity;
    double price;

    std::cout << "Enter product details:\n";
    std::cout << "Name: ";
    std::cin >> name;
    std::cout << "Origin: ";
    std::cin >> origin;
    std::cout << "Expiration Date (YYYY-MM-DD): ";
    std::cin >> expirationDate;
    std::cout << "Quantity: ";
    std::cin >> quantity;
    std::cout << "Price: ";
    std::cin >> price;

    repository.addProduct(Product(name, origin, expirationDate, quantity, price));
    std::cout << "Product added successfully!\n";
}

void FruitUI::removeProduct(FruitRepository& repository) {
    std::string productName;
    std::cout << "Enter the name of the product to remove: ";
    std::cin >> productName;

    repository.removeProduct(productName);
    std::cout << "Product removed successfully!\n";
}

void FruitUI::listProductsByOrigin(FruitRepository& repository) const {
    std::string origin;
    std::cout << "Enter the origin of the products from the list: ";
    std::cin >> origin;

    repository.listProductsByOrigin(origin);
}

void FruitUI::listAllProducts(FruitRepository& repository) const {
    repository.listAllProducts();
}

void FruitUI::listLowStockProducts(FruitRepository& repository) const {
    repository.listLowStockProducts();
}
