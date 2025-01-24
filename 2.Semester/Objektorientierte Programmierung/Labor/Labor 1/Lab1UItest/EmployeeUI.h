//
// Created by Kathrin static Bercea Engels on 30.05.2024.
//

#ifndef LAB1UITEST_EMPLOYEEUI_H
#define LAB1UITEST_EMPLOYEEUI_H
//
// Created by Kathrin Bercea Engels on 29.05.2024.
//

#include <string>

class EmployeeUI {

public:
    EmployeeUI(EmployeeUI& employeeUI);

    static void displayMenu();
    static void handleEmployeeMenu();


private:
    EmployeeUI& employeeUi;

    static void addEmployee();
    static void modifyEmployee();
    static void searchEmployee();
    static void removeEmployee();

};



#endif //LAB1UITEST_EMPLOYEEUI_H
