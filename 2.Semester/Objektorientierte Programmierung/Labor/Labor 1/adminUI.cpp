//
// Created by Kathrin Bercea Engels on 06.06.2024.
//
#include <iostream>
#include "adminUI.h"
void adminUI::displayMenu() {
    std::cout << "Admin Management System" << std::endl;
    std::cout << "1. Create Admin" << std::endl;
    std::cout << "2. Update Admin" << std::endl;
    std::cout << "3. Delete Admin" << std::endl;
    std::cout << "4. Activate Admin" << std::endl;
    std::cout << "5. Deactivate Admin" << std::endl;
    std::cout << "6. Reset Admin" << std::endl;
    std::cout << "7. List all Admins" << std::endl;
    std::cout << "8. Search Admin by Name" << std::endl;
    std::cout << "9. View Admin Salary" << std::endl;
    std::cout << "10. Adjust Admin Salary" << std::endl;
    std::cout << "11. Generate Random Passwort" << std::endl;
    std::cout << "12. Send Passwort Reset Email" << std::endl;
    std::cout << "0. Exit" << std::endl;


}

void adminUI::handleAdminMenu() {
    int choice;
    do {
        std::cout << "Hello! What would you like to do today? " << std::endl;
        displayMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                createAdmin();
                break;
            case 2:
                updateAdmin();
                break;
            case 3:
                deleteAdmin();
                break;
            case 4:
                activateAdmin();
                break;
            case 5:
                deactivateAdmin();
                break;
            case 6:
                resetAdminPassword();
                break;
            case 7:
                listAllAdmins();
                break;
//            case 8:
//                searchAdminsByName();
//                break;
            case 9:
                viewAdminSalary();
                break;
            case 10:
                adjustAdminSalary();
                break;
            case 11:
                generateRandomPassword();
                break;
            case 12:
                sendPasswordResetEmail();
                break;
            case 0:
                std::cout << "Exiting" << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 0);
}

void adminUI::createAdmin() {
    std::string lastName, firstName, email, position, password, birthdate, initials;
    int salary;
    bool isActive;

    std::cout << "Enter last name: ";
    std::getline(std::cin, lastName);
    std::cout << "Enter fisrt name: ";
    std::getline(std::cin, firstName);
    std::cout << "Enter email: ";
    std::getline(std::cin, email);
    std::cout << "Enter password: ";
    std::getline(std::cin, password);
    std::cout << "Enter position: ";
    std::getline(std::cin, position);
    std::cout << "Enter birthdate: ";
    std::getline(std::cin, birthdate);
    std::cout << "Enter initials: ";
    std::getline(std::cin, initials);
    std::cout << "Enter salary: ";
    std::cin >> salary;
    std::cin.ignore();

//    AdminController.createAdmin(const std::string& lastName, const std::string& firstName, const std::string& email, const std::string& position, const std::string& abbreviation, const Date& birthDate, double salary, const std::string& remarks, bool isActive, const std::string& password);

}

void adminUI::updateAdmin() {
    std::string lastName, firstName, email, position, password, birthday, initials;
    int salary;
    bool isActive;

    std::cout << "Enter last name: ";
    std::getline(std::cin, lastName);
    std::cout << "Enter fisrt name: ";
    std::getline(std::cin, firstName);
    std::cout << "Enter email: ";
    std::getline(std::cin, email);
    std::cout << "Enter position: ";
    std::getline(std::cin, position);
    std::cout << "Enter initials: ";
    std::getline(std::cin, initials);
    std::cout << "Enter birthday: ";
    std::getline(std::cin, birthday);
    std::cout << "Enter salary: ";
    std::cin >> salary;
    std::cin.ignore();

//    AdminController.updateAdmin()
//    const std::string &identifier;
//    const std::string &attribute;
//    const std::string &value);
}
    void adminUI::deleteAdmin() {
        std::string lastName, firstName, email, position, password, birthday, initials;
        int salary;
        bool isActive;
        std::cout << "Enter Email of the admin to delete: ";
        std::cin >> email;
//        AdminController.deleteAdmin(email);
        std::cout << "Admin deleted successfully!" << std::endl;

//        AdminController.deleteAdmin()
//        const std::string &identifier;

    }

    void adminUI::activateAdmin() {
        std::string lastName, firstName, email, position, password, birthday, initials;
        int salary;
        bool isActive;
        std::cout << "Enter Email of the admin to activate: ";
        std::cin >> email;
        std::cout << "Admin activated successfully!" << std::endl;
//        AdminController.activateAdmin(const std::string& identifier);
    }

void adminUI::deactivateAdmin() {
    std::string lastName, firstName, email, position, password, birthday, initials;
    int salary;
    bool isActive;
    std::cout << "Enter Email of the admin to deactivate: ";
    std::cin >> email;
    std::cout << "Admin deactivated successfully!" << std::endl;
//    AdminController::deactivateAdmin(const std::string& identifier);
}

void adminUI::resetAdminPassword(){
    std::string lastName, firstName, email, position, password, newPassword, birthday, initials;
    int salary;
    bool isActive;
    std::cout <<"Enter your Email:" << std::endl;
    std::cin>>email;
    std::cout <<"Enter your new Password:" << std::endl;
    std::cin>>newPassword;
    std::cout <<"Password reset complete" << std::endl;


//    AdminController.resetAdminPassword(const std::string& identifier);
}

void adminUI::listAllAdmins() const{
//    AdminController.listAllAdmins();
}

//void adminUI::searchAdminsByName() const {
//    std::string lastName, firstName;
//    std::cout <<"Enter admin first name:" << std::endl;
//    std::cin >> firstName;
//    std::cout <<"Enter admin last name:" << std::endl;
//    std::cin >> lastName;

//    AdminController.searchAdminsByName(const std::string& name);
//
//}

void adminUI::viewAdminSalary() const {
    std::string email;
    std::cout << "Enter admin Email:" <<std::endl;
    std::cin >> email;

//    AdminController.viewAdminSalary(const std::string& identifier) const
}

void adminUI::adjustAdminSalary() {
    std::string email;
    std::cout << "Enter admin Email:" <<std::endl;
    std::cin >> email;
//    AdminController.adjustAdminSalary(const std::string& identifier, double newSalary);
    }

std::string adminUI::generateRandomPassword() const {
    std::string email, password;
    std::cout << "Enter admin Email:" <<std::endl;
    std::cin >> email;

//    AdminController.generateRandomPassword() const;
}

void adminUI::sendPasswordResetEmail() const {
    std::string email, password;
    std::cout << "Enter admin Email:" <<std::endl;
    std::cin >> email;
//    AdminController.sendPasswordResetEmail(const std::string& email, const std::string& newPassword) const;

    }

