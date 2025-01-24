//
// Created by Kathrin Bercea Engels on 30.05.2024.
//

#ifndef LAB1UITEST_ORDERUI_H
#define LAB1UITEST_ORDERUI_H


#include <iostream>
//#include "../Repositories/OrderRepo/OrderRepo.h"
//#include "../Controllers/OrderController/OrderController.h"
class OrderUI {

private:
    OrderUI& orderUI;
    //void validateOrder;

public:
    static void displayMenu();
    static void handleUserInput();
    static void createOrder();
    static void modifyOrder();
    static void removeOrder();
    static void listOrders();
    static void searchOrder();

};


#endif //LAB1UITEST_ORDERUI_H
