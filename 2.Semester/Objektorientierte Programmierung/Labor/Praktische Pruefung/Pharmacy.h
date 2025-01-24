//
// Created by ANDREI on 06/06/2024.
//

#ifndef PRAKTISCHE_PRUEFUNG_PHARMACY_H
#define PRAKTISCHE_PRUEFUNG_PHARMACY_H

#include <iostream>

enum class Category {
    Cosmetics,
    Vitamins,
    Other
};

class Medication {

public:
    Medication();
    Medication(std::string name, int quantity, double price, Category category);
    std::string getName() const;
    int getQuantity() const;
    double getPrice() const;
    Category getCategory() const;

private:
    std::string name;
    int quantity;
    double price;
    Category category;
};

#endif //PRAKTISCHE_PRUEFUNG_PHARMACY_H
