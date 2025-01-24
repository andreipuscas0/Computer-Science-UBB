//
// Created by ANDREI on 06/06/2024.
//

#include "Pharmacy.h"
#include "Controller.h"
#include <algorithm>

MedicationController::MedicationController(MedicationRepository& repository)
        : repository(repository) {}

void MedicationController::addMedication(const Medication& medication) {
    repository.addMedication(medication);
}

std::vector<Medication> MedicationController::getTopCheapestMedications(int topN) const {
    auto medications = repository.getAllMedications();
    std::sort(medications.begin(), medications.end(), [](const Medication& a, const Medication& b) {
        return a.getPrice() < b.getPrice();
    });
    if (medications.size() > topN) {
        medications.resize(topN);
    }
    return medications;
}

std::vector<Medication> MedicationController::getLastChanceCosmetics(int topN) const {
    auto medications = repository.getAllMedications();
    std::vector<Medication> cosmetics;
    for (const auto& med : medications) {
        if (med.getCategory() == Category::Cosmetics) {
            cosmetics.push_back(med);
        }
    }
    std::sort(cosmetics.begin(), cosmetics.end(), [](const Medication& a, const Medication& b) {
        return a.getQuantity() < b.getQuantity();
    });
    if (cosmetics.size() > topN) {
        cosmetics.resize(topN);
    }
    return cosmetics;
}

//std::vector<Medication> MedicationController::getAllMedications() const {
//    return repository.getAllMedications();
//}
