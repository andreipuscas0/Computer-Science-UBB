#pragma once
#include "MultiMap.h"

class MultiMap;

class MultiMapIterator
{
    friend class MultiMap;

private:
    const MultiMap& col;
    const int &capacity;
    int currentIndex;

    //DO NOT CHANGE THIS PART
    MultiMapIterator(const MultiMap& c);

public:
    TElem getCurrent()const;
    TElem getPrevious()const;
    bool valid() const;
    void next();
    void first();
    int getCurrentIndex() const { return currentIndex; }
    int getCapacity() const { return capacity; }
};

