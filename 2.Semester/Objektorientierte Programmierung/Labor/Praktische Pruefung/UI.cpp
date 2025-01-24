//
// Created by ANDREI on 06/06/2024.
//

#include "UI.h"
#include <iostream>

UI::UI(MedicationController& controller) : controller(controller) {}

void UI::displayMenu() {
    int choice;
    std::string label;

    do {
        std::cout << "1. Add Medication " << std::endl;
        std::cout << "2. Display Promotions " << std::endl;
        std::cout << "3. Exit " << std::endl;
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                handleAddMedication();
                break;
            case 2:
                std::cout << "Enter promotion label (top-cheapest-products or last-chance-cosmetics): ";
                std::cin >> label;
                handleDisplayPromotions(label);
                break;
            case 3:
                std::cout << "Exiting..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice! Please try again " << std::endl;
        }
    } while (choice != 3);
}

void UI::handleAddMedication() {
    std::string name;
    int quantity;
    double price;
    std::string categoryStr;
    Category category;

    std::cout << "Enter medication name: ";
    std::cin >> name;
    std::cout << "Enter quantity: ";
    std::cin >> quantity;
    std::cout << "Enter price: ";
    std::cin >> price;
    std::cout << "Enter category (Cosmetics/Vitamins/Other): ";
    std::cin >> categoryStr;

    if (categoryStr == "Cosmetics") {
        category = Category::Cosmetics;
    } else if (categoryStr == "Vitamins") {
        category = Category::Vitamins;
    } else {
        category = Category::Other;
    }

    Medication medication(name, quantity, price, category);
    try {
        controller.addMedication(medication);
        std::cout << "Medication added successfully. " << std::endl;
    } catch (const std::runtime_error& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

void UI::handleDisplayPromotions(const std::string& label) {
    if (label == "top-cheapest-products") {
        auto medications = controller.getTopCheapestMedications(3);
        std::cout << "Top 3 cheapest medications:\n";
        for (const auto& med : medications) {
            std::cout << med.getName() << " - " << med.getPrice() << "\n";
        }
    } else if (label == "last-chance-cosmetics") {
        auto medications = controller.getLastChanceCosmetics(2);
        std::cout << "Last chance cosmetics:\n";
        for (const auto& med : medications) {
            std::cout << med.getName() << " - " << med.getQuantity() << "\n";
        }
    } else {
        std::cout << "Invalid label!\n";
    }
}
