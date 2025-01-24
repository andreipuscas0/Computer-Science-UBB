//
// Created by Kathrin Bercea Engels on 30.05.2024.
//

#include "FinalUI.h"
#include "CustomerUI.h"
#include "AutoUI.h"
//#include "adminUI.h"
#include "OrderUI.h"
#include "EmployeeUI.h"
#include <string>
#include <iostream>


void FinalUI::startMenu() {
    std::cout << "Hello! " << std::endl;
    std::cout << "Choose an option: " << std::endl;
    std::cout << "1. Log in " << std::endl;
    std::cout << "2. Sign up " << std::endl;
    std::cout << "0. Exit " << std::endl;
}


void FinalUI::displayMenuEmployee() {
    std::cout<<"Enter your choice: "<<std::endl;
    std::cout<<"1. Car Menu"<<std::endl;
    std::cout<<"2. Customer Menu"<<std::endl;
    std::cout<<"0. Exit"<<std::endl;
}

void FinalUI::handleMenuEmployee() {
    int choice;
//    AutoUI auto(filename);
//    CustomerUI customer(filename);
    do{
        displayMenuEmployee();
        std::cin >> choice;
        switch(choice){
            case 1:
                AutoUI::run();
                break;
            case 2:
                CustomerUI::run();
                break;
            case 0:
                std::cout<<"Exiting...";
                break;
        }
    }while(choice != 0);

}


void FinalUI::logIn(){
    std::cout << "Welcome! " << std::endl;
    std::cout << "Are you a customer, an employee or an admin? " << std::endl;
    std::cout << "1. Customer " << std::endl;
    std::cout << "2. Employee " << std::endl;
    std::cout << "3. Admin " << std::endl;
    std::cout << "0. Exit " <<std::endl;
    int choice;
    std::cin >> choice;
    switch(choice) {
        case 1:
        {
            std::cout << "Enter your email: " << std::endl;
            std::string email;
            std::cin >> email;
            std::cout << "Enter your password: " << std::endl;
            std::string password;
            std::cin >> password;
            std::cout << "Welcome back! " << std::endl;
            OrderUI::handleUserInput();
        }
        break;
        case 2:
        {
            std::cout << "Enter your email: " << std::endl;
            std::string email;
            std::cin >> email;
            std::cout << "Enter your password: " << std::endl;
            std::string password;
            std::cin >> password;
            std::cout << "Welcome back! " << std::endl;
            FinalUI::handleMenuEmployee();
//            std::cout << "Enter an option: " << std::endl;
//            std::cout << "1. Manage cars " << std::endl;
//            std::cout << "2. Manage customers " << std::endl;
//            std::cout << "0. Exit " << std::endl;
            std::cin >> choice;
            switch(choice){
                case 1:
                {
                    AutoUI::run();
                }
                break;
                case 2:
                {
                    CustomerUI::run();
                }
                break;
                case 0:
                break;
            }
        }
        break;
        case 3:
        {
            std::cout << "Enter your email: " << std::endl;
            std::string email;
            std::cin >> email;
            std::cout << "Enter your password: " << std::endl;
            std::string password;
            std::cin >> password;
            std::cout << "Welcome back! " << std::endl;
            EmployeeUI::handleEmployeeMenu();
        }
        break;
    }

}


void FinalUI::signUp() {
    std::cout << "Welcome! " << std::endl;
    std::cout << "Enter your email " << std::endl;
    std::string email;
    std::cin >> email;
    std::cout << "Create a password " << std::endl;
    std::string password;
    std::cin >> password;
    logIn();
}

void FinalUI::runAll() {
    int choice;
    startMenu();
    std::cin >> choice;
    switch (choice) {
        case 1: {
            logIn();
            break;
        }
        case 2: {
            signUp();
            break;
        }
        case 0: {
            std::cout << "Exiting... " << std::endl;
            break;
        }
        default: {
            std::cout << "Invalid choice. PLease try again. " << std::endl;
        }
    }
}