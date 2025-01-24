//
// Created by ANDREI on 06/06/2024.
//

#ifndef PRAKTISCHE_PRUEFUNG_CONTROLLER_H
#define PRAKTISCHE_PRUEFUNG_CONTROLLER_H

#include "Repository.h"
#include <vector>

class MedicationController {

public:
    MedicationController(MedicationRepository& repository);
    void addMedication(const Medication& medication);
    std::vector<Medication> getTopCheapestMedications(int topN) const;
    std::vector<Medication> getLastChanceCosmetics(int topN) const;
//    std::vector<Medication> getAllMedications() const;

private:
    MedicationRepository& repository;
};

#endif //PRAKTISCHE_PRUEFUNG_CONTROLLER_H
