//
// Created by Kathrin Bercea Engels on 30.05.2024.
//

#ifndef LAB1UITEST_AUTOUI_H
#define LAB1UITEST_AUTOUI_H
//#include "../Controllers/AutoController/AutoController.h"

class AutoUI {

private:
    AutoUI& autoUI;
//    AutoController& controller;
    static void printMenu();
    static void addAuto();
    static void removeAuto();
    static void modifyAuto();
    static void filterByBrand();
    static void filterByModel();
    static void filterByFuelType();
    static void filterByTransmission();
    static void filterByPriceRange();
    static void listCarsByPrice();
    static void getCarByLicensePlate();

public:
//    AutoUI(AutoController& controller);
    static void run();

};


#endif //LAB1UITEST_AUTOUI_H
