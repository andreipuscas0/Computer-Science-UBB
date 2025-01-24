//
// Created by ANDREI on 06/06/2024.
//

#ifndef PRAKTISCHE_PRUEFUNG_REPOSITORY_H
#define PRAKTISCHE_PRUEFUNG_REPOSITORY_H

#include "Pharmacy.h"
#include <vector>
#include <string>

class MedicationRepository {

public:
    void addMedication(const Medication& medication);
    std::vector<Medication> getAllMedications() const;
    Medication findMedicationByName(const std::string& name) const;

private:
    std::vector<Medication> medications;
};

#endif //PRAKTISCHE_PRUEFUNG_REPOSITORY_H
