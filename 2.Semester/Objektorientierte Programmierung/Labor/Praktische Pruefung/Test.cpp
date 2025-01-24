//
// Created by ANDREI on 06/06/2024.
//

#include "Test.h"
#include "Pharmacy.h"
#include "Repository.h"
#include "Controller.h"
#include <iostream>
#include <cassert>

void testMedication() {
    Medication med("Aspirin", 10, 5.99, Category::Vitamins);
    assert(med.getName() == "Aspirin");
    assert(med.getQuantity() == 10);
    assert(med.getPrice() == 5.99);
    assert(med.getCategory() == Category::Vitamins);
    std::cout << "Medication tests passed " << std::endl;
}

void testRepository() {
    MedicationRepository repo;
    Medication med("Aspirin", 10, 5.99, Category::Vitamins);
    repo.addMedication(med);
    auto allMeds = repo.getAllMedications();
    assert(allMeds.size() == 1);
    assert(allMeds[0].getName() == "Aspirin");
    assert(repo.findMedicationByName("Aspirin").getName() == "Aspirin");
    std::cout << "Repository tests passed " << std::endl;
}

void testController() {
    MedicationRepository repo;
    MedicationController controller(repo);
    Medication med1("Aspirin", 10, 5.99, Category::Vitamins);
    Medication med2("Magnesium", 5, 3.99, Category::Vitamins);
    Medication med3("Lipstick", 2, 15.99, Category::Cosmetics);
    Medication med4("Mascara", 1, 9.99, Category::Cosmetics);
    controller.addMedication(med1);
    controller.addMedication(med2);
    controller.addMedication(med3);
    controller.addMedication(med4);

    auto cheapest = controller.getTopCheapestMedications(3);
    assert(cheapest.size() == 3);
    assert(cheapest[0].getName() == "Magnesium");
    assert(cheapest[1].getName() == "Aspirin");
    assert(cheapest[2].getName() == "Mascara");

    auto lastChanceCosmetics = controller.getLastChanceCosmetics(2);
    assert(lastChanceCosmetics.size() == 2);
    assert(lastChanceCosmetics[0].getName() == "Mascara");
    assert(lastChanceCosmetics[1].getName() == "Lipstick");

    std::cout << "Controller tests passed " << std::endl;
}

void runTests() {
    testMedication();
    testRepository();
    testController();
}
