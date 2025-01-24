#ifndef L3_Puscas_Andrei_DSM_H
#define L3_Puscas_Andrei_DSM_H

#include <string>

class DSM {
private:
    int sizeOfMatrix;
    std::string* elementNames;
    int** adjacencyMatrix;

public:
    // Constructori
    DSM(int elementCount);
    DSM(std::string* elementNames, int elementCount);

    // Destructor
    ~DSM();

    // Constructor copie
    DSM(const DSM& other);

    // Afla dimensiunea matricei
    int size() const;

    // Afla numele unui element după index
    std::string getName(int index) const;

    // Setează numele unui element după index
    void setElementName(int index, const std::string& elementName);

    // Adaugă un link între elementele cu weight
    void addLink(const std::string& fromElement, const std::string& toElement, int weight);

    // Șterge un link dintre elemente
    void deleteLink(const std::string& fromElement, const std::string& toElement);

    // Metodele de analiză
    bool hasLink(const std::string& fromElement, const std::string& toElement) const;
    int linkWeight(const std::string& fromElement, const std::string& toElement) const;
    int countToLinks(const std::string& elementName) const;
    int countFromLinks(const std::string& elementName) const;
    int countAllLinks() const;
};

#endif // L3_Puscas_Andrei_DSM_H
