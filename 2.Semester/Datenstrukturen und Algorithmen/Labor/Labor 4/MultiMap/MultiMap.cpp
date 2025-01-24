#include "MultiMap.h"
#include "MultiMapIterator.h"
#include <exception>
#include <iostream>

using namespace std;

// Constructorul clasei MultiMap
// BC = WC = AC = Theta(capacity)
MultiMap::MultiMap() {
    // Inițializarea capacității și a dimensiunii inițiale
    capacity = 4; // Capacitatea inițială a hash table
    initialCapacity = capacity; // Stocarea capacității inițiale
    sizeofarray = 0; // Numărul curent de elemente din MultiMap
    // Alocarea memoriei pentru array-ul de elemente și pentru array-ul de indici ocupați
    elements = new TElem[capacity]; // Alocare memorie pentru array-ul de elemente
    for (int i = 0; i < capacity; i++) {
        elements[i] = NULL_TELEM; // Inițializarea tuturor elementelor ca NULL_TELEM
    }
    occupiedIndices = new bool[capacity]; // Alocare memorie pentru array-ul de indici ocupați
    for (int i = 0; i < capacity; i++) {
        occupiedIndices[i] = false; // Marcarea tuturor indiciilor ca neocupați
    }
}

// Funcția de adăugare a unei perechi cheie-valoare
// BC = Theta(1) (când indexul inițial este disponibil)
// WC = AC = Theta(capacity) (când trebuie realocată și rehashuită întreaga structură)
void MultiMap::add(TKey c, TValue v) {
    // Calcularea indexului inițial și a pasului de hashing
    int initialIndex = hash1(c) % capacity; // Calcularea indexului hash inițial
    int step = hash2(c) % capacity; // Calcularea pasului pentru dublu hashing

    // Inițializarea variabilelor locale
    int currentIndex = initialIndex;
    int visitedCount = 0;
    bool repeatedInitialIndex = false;

    // Iterare pentru a găsi un index disponibil pentru adăugare
    do {
        // Verificarea dacă indexul curent este disponibil
        if (!occupiedIndices[currentIndex]) {
            // Adăugarea perechii cheie-valoare la indexul curent
            elements[currentIndex] = TElem(c, v);
            // Marcarea indexului curent ca ocupat
            occupiedIndices[currentIndex] = true;
            // Incrementarea dimensiunii MultiMap-ului
            sizeofarray++;
            // Ieșirea din buclă, adăugarea realizată cu succes
            return;
        }

        // Mutarea la următorul index utilizând dublu hashing
        currentIndex = (currentIndex + step) % capacity;

        // Verificarea dacă ne-am întors la indexul inițial
        if (currentIndex == initialIndex) {
            // Marchează faptul că ne-am întors la indexul inițial
            repeatedInitialIndex = true;
        }

        // Incrementarea contorului pentru indicii vizitați
        visitedCount++;
    } while ((visitedCount < capacity)); // Continuarea până când toți indicii sunt vizitați

    // Verificarea dacă am revenit la indexul inițial și nu am găsit un index disponibil
    if (repeatedInitialIndex) {
        // Dublarea capacității MultiMap-ului
        int newCapacity = capacity * 2;
        // Alocarea de memorie pentru noul array de elemente și pentru noul array de indici ocupați
        TElem* newElements = new TElem[newCapacity];
        bool* newOccupiedIndices = new bool[newCapacity];

        // Inițializarea array-urilor noi
        for (int i = 0; i < newCapacity; i++) {
            newElements[i] = NULL_TELEM; // Elemente noi inițializate ca NULL_TELEM
            newOccupiedIndices[i] = false; // Indici noi inițializați ca neocupați
        }

        // Rehashuirea elementelor existente în noul array
        for (int i = 0; i < capacity; i++) {
            if (occupiedIndices[i]) { // Verificarea dacă indexul este ocupat
                int newIndex = hash1(elements[i].first) % newCapacity;
                int newStep = hash2(elements[i].first) % newCapacity;

                // Găsirea unui nou index disponibil folosind dublu hashing
                while (newOccupiedIndices[newIndex]) {
                    newIndex = (newIndex + newStep) % newCapacity;
                }
                // Adăugarea elementului la noul index și marcarea ca ocupat
                newElements[newIndex] = elements[i];
                newOccupiedIndices[newIndex] = true;
            }
        }

        // Eliberarea memoriei pentru array-urile vechi
        delete[] elements;
        delete[] occupiedIndices;

        // Actualizarea array-urilor și capacității
        elements = newElements;
        occupiedIndices = newOccupiedIndices;
        capacity = newCapacity;

        // Recalcularea indexului inițial și a pasului pentru cheia dată
        initialIndex = hash1(c) % capacity;
        step = hash2(c) % capacity;
        currentIndex = initialIndex;
        visitedCount = 0;

        // Iterare pentru a găsi un index disponibil pentru adăugare
        do {
            // Verificarea dacă indexul curent este disponibil
            if (!occupiedIndices[currentIndex]) {
                // Adăugarea perechii cheie-valoare la indexul curent
                elements[currentIndex] = TElem(c, v);
                // Marcarea indexului curent ca ocupat
                occupiedIndices[currentIndex] = true;
                // Incrementarea dimensiunii MultiMap-ului
                sizeofarray++;
                // Ieșirea din buclă, adăugarea realizată cu succes
                return;
            }

            // Mutarea la următorul index utilizând dublu hashing
            currentIndex = (currentIndex + step) % capacity;

            // Verificarea dacă ne-am întors la indexul inițial
            if (currentIndex == initialIndex) {
                // Marchează faptul că ne-am întors la indexul inițial
                repeatedInitialIndex = true;
            }

            // Incrementarea contorului pentru indicii vizitați
            visitedCount++;
        } while ((visitedCount < capacity)); // Continuarea până când toți indicii sunt vizitați
    }
}

// Funcția de eliminare a unei perechi cheie-valoare
// BC = Theta(1) (când perechea este găsită la indexul inițial)
// WC = Theta(capacity) (când trebuie parcurs întregul MultiMap)
// AC = O(capacity)
bool MultiMap::remove(TKey c, TValue v) {
    // Calcularea indexului și a pasului de hashing pentru cheia dată
    int index = hash1(c) % capacity;
    int step = hash2(c) % capacity;
    int visitedIndices = 0;

    // Iterare pentru a găsi perechea cheie-valoare și a o elimina
    do {
        // Verificarea dacă perechea cheie-valoare este găsită la indexul curent
        if (elements[index].first == c && elements[index].second == v) {
            // Eliminarea perechii cheie-valoare la indexul curent
            elements[index] = NULL_TELEM;
            // Marcarea indexului curent ca neocupat
            occupiedIndices[index] = false;
            // Scăderea dimensiunii MultiMap-ului
            sizeofarray--;
            // Returnarea succesului eliminării
            return true;
        }

        // Mutarea la următorul index utilizând dublu hashing
        index = (index + step) % capacity;

        // Incrementarea contorului pentru indicii vizitați
        visitedIndices++;

    } while (visitedIndices < capacity); // Continuarea până când toți indicii sunt vizitați

    // Returnarea eșecului eliminării, perechea cheie-valoare nu a fost găsită
    return false;
}

// Funcția de eliminare a tuturor perechilor asociate unei chei
// Eliminarea tuturor perechilor asociate unei chei din MultiMap și returnarea valorilor eliminate
// BC = WC = AC = Theta(capacity) (în cazul în care toate perechile sunt asociate cheii date)
std::vector<TValue> MultiMap::removeKey(TKey key) {
    // Inițializarea vectorului de valori eliminate
    std::vector<TValue> result;

    // Calcularea indexului și a pasului de hashing pentru cheia dată
    int index = hash1(key) % capacity;
    int step = hash2(key) % capacity;
    int visitedIndices = 0;
    bool repeated = false;

    // Iterare pentru a găsi toate perechile asociate cheii și a le elimina
    do {
        // Verificarea dacă perechea cheie-valoare este găsită la indexul curent
        if (elements[index].first == key) {
            // Adăugarea valorii corespunzătoare în vectorul de rezultate
            result.push_back(elements[index].second);
            // Eliminarea perechii cheie-valoare la indexul curent
            elements[index] = NULL_TELEM;
            // Marcarea indexului curent ca neocupat
            occupiedIndices[index] = false;
            // Scăderea dimensiunii MultiMap-ului
            sizeofarray--;
        }
        // Mutarea la următorul index utilizând dublu hashing
        index = (index + step) % capacity;

        // Verificarea dacă ne-am întors la indexul inițial
        if (index == hash1(key) % capacity) {
            repeated = true;
        }

        // Incrementarea contorului pentru indicii vizitați
        visitedIndices++;
    } while (visitedIndices < capacity && !repeated); // Continuarea până când toți indicii sunt vizitați sau ne întoarcem la indexul inițial

    // Returnarea vectorului de valori eliminate
    return result;
}

// Funcția de căutare a tuturor valorilor asociate unei chei
// Căutarea tuturor valorilor asociate unei chei în MultiMap și returnarea acestora
// BC = WC = AC = Theta(capacity) (în cazul în care toate valorile sunt asociate cheii date)
std::vector<TValue> MultiMap::search(TKey c) const {
    // Inițializarea vectorului de rezultate
    std::vector<TValue> result;

    // Calcularea indexului și a pasului de hashing pentru cheia dată
    int index = hash1(c) % capacity;
    int step = hash2(c) % capacity;
    int visitedIndices = 0;
    bool repeatedInitialIndex = false;

    // Iterare pentru a găsi toate perechile asociate cheii și a le adăuga în vectorul de rezultate
    do {
        // Verificarea dacă perechea cheie-valoare este găsită la indexul curent
        if (elements[index].first == c) {
            // Adăugarea valorii corespunzătoare în vectorul de rezultate
            result.push_back(elements[index].second);
        }
        // Mutarea la următorul index utilizând dublu hashing
        index = (index + step) % capacity;

        // Verificarea dacă ne-am întors la indexul inițial
        if (index == hash1(c) % capacity) {
            repeatedInitialIndex = true;
        }
        // Incrementarea contorului pentru indicii vizitați
        visitedIndices++;
    } while (visitedIndices < capacity && !repeatedInitialIndex); // Continuarea până când toți indicii sunt vizitați sau ne întoarcem la indexul inițial

    // Returnarea vectorului de rezultate
    return result;
}

// Funcția de obținere a dimensiunii
// BC = WC = AC = Theta(1)
int MultiMap::size() const {
    // Returnarea dimensiunii actuale a MultiMap-ului
    return sizeofarray;
}

// Funcția de verificare a faptului este gol
// BC = WC = AC = Theta(1)
bool MultiMap::isEmpty() const {
    // Verificarea dacă dimensiunea MultiMap-ului este 0
    return sizeofarray == 0;
}

// Funcția de obținere a unui iterator
// BC = WC = AC = Theta(1)
MultiMapIterator MultiMap::iterator() const {
    // Returnarea unui iterator pentru MultiMap-ul curent
    return MultiMapIterator(*this);
}

// Destructorul clasei MultiMap
// BC = WC = AC = Theta(1)
MultiMap::~MultiMap() {
    // Eliberarea memoriei pentru array-ul de elemente
    delete[] elements;
}
