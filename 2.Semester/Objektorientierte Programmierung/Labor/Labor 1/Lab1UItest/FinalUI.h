//
// Created by Kathrin Bercea Engels on 30.05.2024.
//

#ifndef LAB1UITEST_FINALUI_H
#define LAB1UITEST_FINALUI_H


//#include "../Controllers/AdminController/AdminController.h"
#include "AutoUI.h"
#include "EmployeeUI.h"
#include "CustomerUI.h"
#include "OrderUI.h"
#include "adminUI.h"

class FinalUI {

private:
    static void startMenu();
    static void displayMenuEmployee();
    static void handleMenuEmployee();
    static void logIn();
    static void signUp();

public:
    static void runAll();

};



#endif //LAB1UITEST_FINALUI_H
