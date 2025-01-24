#include "L3_Puscas_Andrei_DSM.h"
#include <stdexcept>
#include <algorithm>

// Constructor cu element count
DSM::DSM(int elementCount) {
    sizeOfMatrix = elementCount;
    elementNames = new std::string[elementCount];
    adjacencyMatrix = new int*[elementCount];
    for (int i = 0; i < elementCount; ++i) {
        adjacencyMatrix[i] = new int[elementCount];
        for (int j = 0; j < elementCount; ++j) {
            adjacencyMatrix[i][j] = 0; // Inițializăm toate elementele cu 0
        }
    }
}

// Constructor cu element names și count
DSM::DSM(std::string* elementNames, int elementCount) : DSM(elementCount) {
    for (int i = 0; i < elementCount; ++i) {
        this->elementNames[i] = elementNames[i];
    }
}

// Destructor
DSM::~DSM() {
    delete[] elementNames;
    for (int i = 0; i < sizeOfMatrix; ++i) {
        delete[] adjacencyMatrix[i];
    }
    delete[] adjacencyMatrix;
}

// Constructor copie
DSM::DSM(const DSM& other) : DSM(other.size()) {
    for (int i = 0; i < sizeOfMatrix; ++i) {
        elementNames[i] = other.elementNames[i];
        for (int j = 0; j < sizeOfMatrix; ++j) {
            adjacencyMatrix[i][j] = other.adjacencyMatrix[i][j];
        }
    }
}

// Află dimensiunea matricei
int DSM::size() const {
    return sizeOfMatrix;
}

// Află numele unui element după index
std::string DSM::getName(int index) const {
    if (index < 0 || index >= sizeOfMatrix) {
        throw std::out_of_range("Index out of range");
    }
    return elementNames[index];
}

// Setează numele unui element după index
void DSM::setElementName(int index, const std::string& elementName) {
    if (index < 0 || index >= sizeOfMatrix) {
        throw std::out_of_range("Index out of range");
    }
    elementNames[index] = elementName;
}

// Adaugă un link între elementele cu weight
void DSM::addLink(const std::string& fromElement, const std::string& toElement, int weight) {
    int fromIndex = -1;
    int toIndex = -1;
    for (int i = 0; i < sizeOfMatrix; ++i) {
        if (elementNames[i] == fromElement) {
            fromIndex = i;
        }
        if (elementNames[i] == toElement) {
            toIndex = i;
        }
    }
    adjacencyMatrix[fromIndex][toIndex] = weight;
}

// Șterge un link dintre elemente
void DSM::deleteLink(const std::string& fromElement, const std::string& toElement) {
    addLink(fromElement, toElement, 0); // Setând weight-ul la 0 șterge eficient link-ul
}

// Analizează dacă există un link între elemente
bool DSM::hasLink(const std::string& fromElement, const std::string& toElement) const {
    int fromIndex = -1;
    int toIndex = -1;
    for (int i = 0; i < sizeOfMatrix; ++i) {
        if (elementNames[i] == fromElement) {
            fromIndex = i;
        }
        if (elementNames[i] == toElement) {
            toIndex = i;
        }
    }
    return adjacencyMatrix[fromIndex][toIndex] != 0;
}

// Analizează care este weight-ul link-ului dintre elemente
int DSM::linkWeight(const std::string& fromElement, const std::string& toElement) const {
    int fromIndex = -1;
    int toIndex = -1;
    for (int i = 0; i < sizeOfMatrix; ++i) {
        if (elementNames[i] == fromElement) {
            fromIndex = i;
        }
        if (elementNames[i] == toElement) {
            toIndex = i;
        }
    }
    return adjacencyMatrix[fromIndex][toIndex];
}

// Analizează care sunt link-urile de intrare către un element
int DSM::countToLinks(const std::string& elementName) const {
    int elementIndex = -1;
    for (int i = 0; i < sizeOfMatrix; ++i) {
        if (elementNames[i] == elementName) {
            elementIndex = i;
            break;
        }
    }
    int count = 0;
    for (int i = 0; i < sizeOfMatrix; ++i) {
        if (adjacencyMatrix[elementIndex][i] != 0) {
            ++count;
        }
    }
    return count;
}

// Analizează care sunt link-urile de ieșire dinspre un element
int DSM::countFromLinks(const std::string& elementName) const {
    int elementIndex = -1;
    for (int i = 0; i < sizeOfMatrix; ++i) {
        if (elementNames[i] == elementName) {
            elementIndex = i;
            break;
        }
    }
    int count = 0;
    for (int i = 0; i < sizeOfMatrix; ++i) {
        if (adjacencyMatrix[i][elementIndex] != 0) {
            ++count;
        }
    }
    return count;
}

// Analizează care este numărul de link-uri din matrice
int DSM::countAllLinks() const {
    int count = 0;
    for (int i = 0; i < sizeOfMatrix; ++i) {
        for (int j = 0; j < sizeOfMatrix; ++j) {
            if (adjacencyMatrix[i][j] != 0) {
                ++count;
            }
        }
    }
    return count;
}
