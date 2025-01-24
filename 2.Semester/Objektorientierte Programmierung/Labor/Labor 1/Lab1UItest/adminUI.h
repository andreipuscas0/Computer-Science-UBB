//
// Created by Kathrin Bercea Engels on 06.06.2024.
//

#ifndef LAB1UITEST_ADMINUI_H
#define LAB1UITEST_ADMINUI_H

#include <string>

class adminUI {


public:
    adminUI(adminUI& adminUi);

    void displayMenu();
    void handleAdminMenu();


private:
    adminUI& adminUi;
    static void addEmployee();
    static void createAdmin();
    static void updateAdmin();
    static void deleteAdmin();
    static void activateAdmin();
    static void deactivateAdmin();
    static void resetAdminPassword();

    void listAllAdmins() const;
//    std::vector<admin> searchAdminsByName() const;
    void viewAdminSalary() const;
    void adjustAdminSalary();
    std::string generateRandomPassword() const;
    void sendPasswordResetEmail() const;
//    static admin jsonToAdmin();
};


#endif //LAB1UITEST_ADMINUI_H




