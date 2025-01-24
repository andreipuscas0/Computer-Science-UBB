#include "SetIterator.h"
#include "Set.h"
#include <stdexcept>


//Complexitate: theta(1)
SetIterator::SetIterator(const Set& m) : set(m)
{
    //TODO - Implementation
    index = 0;
}


//Complexitate: theta(1)
void SetIterator::first() {
	//TODO - Implementation
    if (!set.isEmpty()) {
        index = 0;
    } else {
        throw std::logic_error("Setul este gol");
    }
}


//Complexitate: theta(1)
void SetIterator::next() {
	//TODO - Implementation
    if (valid()) {
        index++;
    } else {
        throw std::logic_error("Iteratorul nu este valid");
    }
}


 //Complexitate: theta(1)
TElem SetIterator::getCurrent() {
     //TODO - Implementation
     if (valid()) {
         return set.dinamic_array[index];
     } else {
         throw std::logic_error("Iteratorul nu este valid");
     }
}

//Complexitate: theta(1)
void SetIterator::modifyCurrent(TElem elem) {

    if(valid()) {
        set.dinamic_array[index] = elem;
    } else {
        throw std::logic_error("Iteratorul nu este valid");
    }
}


//Complexitate: theta(1)
bool SetIterator::valid() const {
	//TODO - Implementation
    return index < set.length;
}

