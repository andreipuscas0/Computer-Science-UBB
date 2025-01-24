//
// Created by Kathrin Bercea Engels on 30.05.2024.
//

#ifndef LAB1UITEST_CUSTOMERUI_H
#define LAB1UITEST_CUSTOMERUI_H


//#include "../Controllers/CustomerController/CustomerController.h"
#include <iostream>
#include <string>

class CustomerUI {
private:
    CustomerUI& customer;

    static void printMenu();
    static void addCustomer();
    static void deleteCustomer();
    static void updateCustomer();
    static void listCustomer();
    static void findCustomerByEmail();
    static void findCustomerByMobile();
    static void findCustomerByName();
    static void getAllCustomersSortedByName();


public:
    static void run();
//    CustomerUI(std::string fileName) : customerController(fileName) {}


};


#endif //LAB1UITEST_CUSTOMERUI_H
