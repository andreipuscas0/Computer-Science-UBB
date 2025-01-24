//
// Created by ANDREI on 06/06/2024.
//

#include "Pharmacy.h"

Medication::Medication()
        : name(""), quantity(0), price(0.0), category(Category::Other) {}

Medication::Medication(std::string name, int quantity, double price, Category category)
        : name(name), quantity(quantity), price(price), category(category) {}

std::string Medication::getName() const {
    return name;
}

double Medication::getPrice() const {
    return price;
}

int Medication::getQuantity() const {
    return quantity;
}

Category Medication::getCategory() const {
    return category;
}