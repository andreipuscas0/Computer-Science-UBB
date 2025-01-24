#pragma once
#include "SortedBag.h"

class SortedBag;

class SortedBagIterator {
    friend class SortedBag;

private:
    const SortedBag& bag;
    SortedBagIterator(const SortedBag& b);

    //TODO - Representation
    SortedBag::BSTNode* currentNode;
    SortedBag::BSTNode* firstNode;
    SortedBag::BSTNode* lastNode;

public:
    TComp getCurrent();
    bool valid();
    void next();
    void first();
};
