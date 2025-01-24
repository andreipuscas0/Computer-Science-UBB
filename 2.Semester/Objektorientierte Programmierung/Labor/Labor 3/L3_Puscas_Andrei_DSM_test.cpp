#include "L3_Puscas_Andrei_DSM.h"
#include <iostream>
#include <cassert>

void testDSMConstructor() {
    DSM dsm(3);
    assert(dsm.size() == 3);
    DSM dsm1(dsm);
    assert(dsm1.size() == dsm.size());
}

void testDSMElementNamesConstructor() {
    std::string elementNames[] = {"A", "B", "C"};
    DSM dsm(elementNames, 3);
    assert(dsm.getName(0) == "A");
    assert(dsm.getName(1) == "B");
    assert(dsm.getName(2) == "C");
}

void testDSMSetElementName() {
    DSM dsm(3);
    dsm.setElementName(0, "A");
    assert(dsm.getName(0) == "A");
}

void testDSMAddLink() {
    DSM dsm(3);
    dsm.setElementName(0, "A");
    dsm.setElementName(1, "B");
    dsm.addLink("A", "B", 5);
    assert(dsm.hasLink("A", "B"));
    assert(dsm.linkWeight("A", "B") == 5);
}

void testDSMDeleteLink() {
    DSM dsm(3);
    dsm.setElementName(0, "A");
    dsm.setElementName(1, "B");
    dsm.addLink("A", "B", 5);
    dsm.deleteLink("A", "B");
    assert(!dsm.hasLink("A", "B"));
}

void testDSMCountToLinks() {
    DSM dsm(3);
    dsm.setElementName(0, "A");
    dsm.setElementName(1, "B");
    dsm.setElementName(2, "C");
    dsm.addLink("A", "B", 5);
    dsm.addLink("A", "C", 10);
    assert(dsm.countToLinks("A") == 2);
}

void testDSMCountFromLinks() {
    DSM dsm(3);
    dsm.setElementName(0, "A");
    dsm.setElementName(1, "B");
    dsm.setElementName(2, "C");
    dsm.addLink("A", "B", 5);
    dsm.addLink("C", "B", 10);
    assert(dsm.countFromLinks("B") == 2);
}

void testDSMCountAllLinks() {
    DSM dsm(3);
    dsm.setElementName(0, "A");
    dsm.setElementName(1, "B");
    dsm.setElementName(2, "C");
    dsm.addLink("A", "B", 5);
    dsm.addLink("A", "C", 10);
    dsm.addLink("C", "B", 15);
    assert(dsm.countAllLinks() == 3);
}


int main() {
    testDSMConstructor();
    testDSMElementNamesConstructor();
    testDSMSetElementName();
    testDSMAddLink();
    testDSMDeleteLink();
    testDSMCountAllLinks();
    testDSMCountToLinks();
    testDSMCountFromLinks();

    std::cout << "All tests passed!" << std::endl;
    return 0;
}

