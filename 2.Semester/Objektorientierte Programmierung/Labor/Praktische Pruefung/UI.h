//
// Created by ANDREI on 06/06/2024.
//

#ifndef PRAKTISCHE_PRUEFUNG_UI_H
#define PRAKTISCHE_PRUEFUNG_UI_H

#include "Controller.h"

class UI {

public:
    UI(MedicationController& controller);
    void displayMenu();
    void handleAddMedication();
    void handleDisplayPromotions(const std::string& label);
//    void handleDisplayAllMedications();

private:
    MedicationController& controller;
};

#endif //PRAKTISCHE_PRUEFUNG_UI_H
