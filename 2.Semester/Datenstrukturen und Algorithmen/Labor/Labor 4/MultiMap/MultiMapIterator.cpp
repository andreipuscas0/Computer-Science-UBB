#include "MultiMapIterator.h"
#include "MultiMap.h"

// Constructorul clasei
//BC = Theta(1) (când primul index este ocupat)
//WC = Theta(col.capacity) (când toate indexurile sunt neocupate)
//AC = O(col.capacity) (în medie, depinde de ocuparea indexurilor)
MultiMapIterator::MultiMapIterator(const MultiMap& c) : col(c), capacity(c.capacity) {
    // Inițializarea currentIndex și căutarea primului index ocupat în col
    currentIndex = 0;
    while (currentIndex < col.capacity && !col.occupiedIndices[currentIndex]) {
        currentIndex++;
    }
}

// Funcția pentru obținerea elementului curent al iteratorului
//BC = WC = AC = Theta(1)
TElem MultiMapIterator::getCurrent() const {
    // Verificarea dacă iteratorul este valid
    if (!valid()) {
        // Aruncarea unei excepții în cazul în care iteratorul nu este valid
        throw std::exception();
    }
    // Returnarea elementului curent din MultiMap
    return col.elements[currentIndex];
}

// Funcția pentru verificarea validității iteratorului
//BC = WC = AC = Theta(1)
bool MultiMapIterator::valid() const {
    // Verificarea dacă currentIndex este valid și indexul este ocupat
    return currentIndex < col.capacity && col.occupiedIndices[currentIndex];
}

// Funcția pentru deplasarea la următorul element
//BC = Theta(1) (când următorul index este ocupat)
//WC = Theta(col.capacity) (când toate indexurile sunt ocupate)
//AC = O(col.capacity) (în medie, depinde de ocuparea indexurilor)
void MultiMapIterator::next() {
    // Verificarea validității iteratorului
    if (!valid()) {
        // Aruncarea unei excepții în cazul în care iteratorul nu este valid
        throw std::exception();
    }
    // Deplasarea currentIndex la următorul index ocupat din MultiMap
    do {
        currentIndex++;
    } while (currentIndex < col.capacity && !col.occupiedIndices[currentIndex]);
}

// Funcția pentru deplasarea la primul element
//BC = WC = AC = Theta(1)
void MultiMapIterator::first() {
    // Resetarea currentIndex și căutarea primului index ocupat în MultiMap
    currentIndex = 0;
    while (currentIndex < col.capacity && !col.occupiedIndices[currentIndex]) {
        currentIndex++;
    }
}

// Funcția pentru obținerea elementului anterior
//BC = Theta(1) (când există un element anterior)
//WC = Theta(col.capacity) (când nu există niciun element anterior)
//AC = O(col.capacity) (în medie, depinde de ocuparea indexurilor)
TElem MultiMapIterator::getPrevious() const {
    // Verificarea validității iteratorului
    if (!valid()) {
        // Aruncarea unei excepții în cazul în care iteratorul nu este valid
        throw std::exception();
    }
    // Deplasarea la indexul anterior ocupat din MultiMap și returnarea elementului corespunzător
    int prevIndex = currentIndex - 1;
    while (prevIndex >= 0 && !col.occupiedIndices[prevIndex]) {
        prevIndex--;
    }
    if (prevIndex >= 0) {
        return col.elements[prevIndex];
    } else {
        // Aruncarea unei excepții în cazul în care nu s-a găsit un element anterior
        throw std::exception();
    }
}

