//#include "L3_Puscas_Andrei_DSM.h"
//#include <iostream>
//
//using namespace std;
//
//int main() {
//    // Example DSM
//    string elementNames[] = {"A", "B", "C", "D", "E"};
//    DSM dsm(elementNames, 5);
//    dsm.addLink("A", "B", 1);
//    dsm.addLink("A", "C", 2);
//    dsm.addLink("B", "D", 3);
//    dsm.addLink("C", "E", 4);
//
//    // Display DSM
//    cout << "Original DSM:" << endl;
//    dsm.display();
//
//    // Write DSM to file
//    dsm.writeToFile("dsm.csv");
//    cout << "DSM written to file 'dsm.csv'." << endl;
//
//    // Create a new DSM and read from file
//    DSM newDsm(5);
//    newDsm.readFromFile("dsm.csv");
//    cout << "\nDSM read from file:" << endl;
//    newDsm.display();
//
//    return 0;
//}
