//
// Created by ANDREI on 06/06/2024.
//

#include "Repository.h"
#include <stdexcept>

void MedicationRepository::addMedication(const Medication& medication) {
    for (const auto& med : medications) {
        if (med.getName() == medication.getName()) {
            throw std::runtime_error("Medication with this name already exists");
        }
    }
    medications.push_back(medication);
}

std::vector<Medication> MedicationRepository::getAllMedications() const {
    return medications;
}

Medication MedicationRepository::findMedicationByName(const std::string& name) const {
    for (const auto& med : medications) {
        if (med.getName() == name) {
            return med;
        }
    }
    throw std::runtime_error("Medication not found");
}
