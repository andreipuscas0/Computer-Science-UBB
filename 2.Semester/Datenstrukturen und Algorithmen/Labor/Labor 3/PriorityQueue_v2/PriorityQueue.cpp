#include "PriorityQueue.h"
#include <iostream>
#include <stdexcept>

// Inițializăm pointerii și variabilele pe care le folosim
//BC = WC = AC = Theta(1)
PriorityQueue::PriorityQueue(Relation r) : head(nullptr), tail(nullptr), firstFree(nullptr), size(0), relation(r) {}

// Eliberăm memoria alocată
//BC = WC = AC = Theta(size)
PriorityQueue::~PriorityQueue() {
    // Parcurgem lista și ștergem fiecare nod
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next; // Salvăm adresa următorului nod pentru a nu pierde legătura
        delete current; // Ștergem nodul curent
        current = next; // Trecem la următorul nod
    }
    // Parcurgem lista nodurilor libere și le ștergem
    current = firstFree;
    while (current != nullptr) {
        Node* next = current->next; // Salvăm adresa următorului nod pentru a nu pierde legătura
        delete current; // Ștergem nodul curent
        current = next; // Trecem la următorul nod
    }
}

// Funcție pentru alocarea unui nou nod
//BC = WC = AC = Theta(1)
PriorityQueue::Node* PriorityQueue::allocateNode(const Element& data) {
    // Verificăm dacă există noduri libere disponibile
    if (firstFree != nullptr) {
        Node* node = firstFree; // Folosim un nod liber disponibil
        firstFree = firstFree->next; // Actualizăm lista nodurilor libere
        node->data = data; // Inițializăm datele nodului
        node->next = nullptr; // Noul nod nu are un nod următor în momentul inițial
        node->prev = nullptr; // Noul nod nu are un nod precedent în momentul inițial
        return node;
    } else {
        return new Node{ data, nullptr, nullptr }; // Dacă nu există noduri libere, alocăm un nod nou
    }
}

// Funcție pentru dealocarea unui nod
//BC = WC = AC = Theta(1)
void PriorityQueue::deallocateNode(Node* node) {
    node->next = firstFree; // Marcam nodul ca fiind disponibil pentru utilizare
    node->prev = nullptr; // Îl izolăm de restul listei pentru a nu strica integritatea ei
    firstFree = node; // Nodul devine primul nod liber disponibil
}

// Alocăm un nou element în coadă
//BC = Theta(1) (când coada este goală sau noul nod este primul)
//WC = Theta(size) (când noul nod are prioritate minimă și trebuie inserat la sfârșitul cozi)
//AC = O(size)
void PriorityQueue::push(TElem e, TPriority p) {
    Element newElement = std::make_pair(e, p); // Creăm un pair cu elementul și prioritatea asociată
    Node* newNode = allocateNode(newElement); // Alocăm un nou nod și îi asignăm datele

    // Verificăm dacă coada este goală
    if (head == nullptr) {
        // Dacă coada este goală, noul nod devine atât capul cât și coada
        head = tail = newNode;
    } else {
        // Altfel, parcurgem coada pentru a găsi locul potrivit pentru noul nod
        Node* current = head;
        Node* previous = nullptr;
        // Parcurgem coada până când găsim un nod cu prioritate mai mică decât a noului nod
        while (current != nullptr && relation(current->data.second, p)) {
            previous = current;
            current = current->next;
        }
        if (previous == nullptr) {
            // Dacă noul nod are cea mai mare prioritate, devine noul cap
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        } else if (current == nullptr) {
            // Dacă noul nod are cea mai mică prioritate, devine noul coada
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        } else {
            // Altfel, trebuie inserat între două noduri existente
            newNode->next = current;
            newNode->prev = previous;
            previous->next = newNode;
            current->prev = newNode;
        }
    }
    size++; // Mărim dimensiunea cozii
}

//BC = Theta(1) (când coada are un singur element)
//WC = AC = O(1) (când coada are mai multe elemente)
Element PriorityQueue::pop() {
    // Verificăm dacă coada este goală
    if (isEmpty()) {
        throw std::runtime_error("PriorityQueue is empty"); // Aruncăm o excepție dacă coada este goală
    }

    // Extragem și returnăm elementul cu cea mai mare prioritate
    Node* nodeToRemove = head;
    Element result = nodeToRemove->data;
    head = head->next; // Avansăm capul cozi spre următorul element

    // Verificăm dacă coada mai are elemente după ce eliminăm primul element
    if (head != nullptr) {
        head->prev = nullptr; // Dacă da, actualizăm nodul anterior al noului cap la nullptr
    } else {
        tail = nullptr; // Dacă nu, coada este acum goală și actualizăm și coada la nullptr
    }

    deallocateNode(nodeToRemove); // Dealocăm nodul extras
    size--; // Scădem dimensiunea cozii
    return result; // Returnăm elementul extras
}

//BC = WC = AC = Theta(1)
bool PriorityQueue::isEmpty() const {
    return size == 0; // Verificăm dacă coada este goală
}

//BC = WC = AC = Theta(1)
Element PriorityQueue::top() const {
    // Verificăm dacă coada este goală
    if (isEmpty()) {
        throw std::runtime_error("PriorityQueue is empty"); // Aruncăm o excepție dacă coada este goală
    }
    return head->data; // Returnăm elementul cu cea mai mare prioritate, fără a-l elimina din coadă
}

// Funcția pentru intercalarea a două PriorityQueue
//BC = WC = AC = Theta(size1 + size2)
//void PriorityQueue::intercalate(const PriorityQueue& q) {
//    // Creăm o coadă rezultat folosind relația de prioritate a cozi inițiale
//    PriorityQueue resultQueue(relation);
//
//    // Inițializăm indicii pentru parcurgerea ambelor cozi
//    int currentNode1 = firstEntry;
//    int currentNode2 = q.firstEntry;
//
//    // Parcurgem ambele cozi și adăugăm elementele în coada rezultat
//    while (currentNode1 != -1 || currentNode2 != -1) {
//        // Adăugăm elementul din prima coadă în coada rezultat
//        if (currentNode1 != -1) {
//            resultQueue.push(nodes[currentNode1].data.first, nodes[currentNode1].data.second);
//            currentNode1 = nodes[currentNode1].next;
//        }
//        // Adăugăm elementul din a doua coadă în coada rezultat
//        if (currentNode2 != -1) {
//            resultQueue.push(q.nodes[currentNode2].data.first, q.nodes[currentNode2].data.second);
//            currentNode2 = q.nodes[currentNode2].next;
//        }
//    }
//}

