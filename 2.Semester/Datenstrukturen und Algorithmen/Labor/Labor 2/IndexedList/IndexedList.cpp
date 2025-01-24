#include <exception>
#include <stdexcept>
#include "IndexedList.h"
#include "ListIterator.h"

// Complexitate: theta(1) pt ca se intampla o singura data
IndexedList::IndexedList() {
	//TODO - Implementation
    head = nullptr;
    tail = nullptr;
}

// Complexitate: theta(1) pt ca se intampla o singura data
int IndexedList::size() const {
    //TODO - Implementation
    return numElem;
}

// Complexitate: theta(1) pt ca if-ul se parcurge o singura data
bool IndexedList::isEmpty() const {
    //TODO - Implementation
    if (numElem == 0)
        return true;
	return false;
}

// Complexitate: BC = theta(1), WC = O(position)
TElem IndexedList::getElement(int pos) const {
    //TODO - Implementation
    Node* current = head;
    if(pos < 0 || pos >= numElem)
        throw std::exception();
    for(int i = 0; i<pos; i++)
        current = current->next;
    return current->info;
}

// Complexitate: BC = theta(1), WC = O(position)
TElem IndexedList::setElement(int pos, TElem e) {
    //TODO - Implementation
    TElem oldpos;
    Node* current = head;
    if(pos < 0 || pos >= numElem)
        throw std::exception();
    for(int i = 0; i<pos; i++)
        current = current->next;
    oldpos = current->info;
	current->info = e;
    return oldpos;
}

// Complexitate: theta(1)
void IndexedList::addToEnd(TElem e){
    //TODO - Implementation
    Node* new_node = new Node;
    new_node->info = e;
    new_node->next = nullptr;
    new_node->previous = tail;
    if(head == nullptr) {
        head = new_node;
        tail = new_node;
    }
    else{
        tail->next = new_node;
        tail = new_node;
    }
}

// Complexitate: BC = theta(1), WC = O(position)
void IndexedList::addToPosition(int pos, TElem e) {
    //TODO - Implementation
        if (pos < 0 || pos > numElem)
            throw std::exception();
        Node* new_node = new Node{e, nullptr, nullptr};
        if (pos == 0) {
            new_node->next = head;
            if (head != nullptr)
                head->previous = new_node;
            head = new_node;
            if (tail == nullptr)
                tail = new_node;
        }
        else {
            Node* current = head;
            for (int i = 0; i < pos - 1; i++) {
                if(current == nullptr)
                    throw std::exception();
                current = current->next;
            }
            new_node->next = current->next;
            new_node->previous = current;
            if (current->next != nullptr)
                current->next->previous = new_node;
            current->next = new_node;
            if (new_node->next == nullptr)
                tail = new_node;
        }
        numElem++;
    }


TElem IndexedList::remove(int pos) {
    //TODO - Implementation
    TElem removed_element;
    if(pos < 0 || pos >= numElem)
        throw std::exception();
    if(head != nullptr){
        removed_element = head->info;
        if(head == tail){
            head = nullptr;
            tail = nullptr;
        }
        else{
            head = head->next;
            head->previous = nullptr;
        }
    }
	return NULL_TELEM;
}

// Comlexitate: BC = theta(1), WC = O(numElem)
int IndexedList::search(TElem e) const{
    //TODO - Implementation
    Node* current = head;
    for(int i = 0; i<numElem; i++){
        if(current->info == e)
            return i;
        current = current->next;
    }
	return -1;
}

ListIterator IndexedList::iterator() const {
    return ListIterator(*this);        
}

//Complexitate: = O(numElem)
IndexedList::~IndexedList() {
	//TODO - Implementation
    Node* current = head;
    while(current != nullptr){
        Node* new_node = current->next;
        delete current;
        current = new_node;
    }
}

// Complexitate: BC = theta(1), WC = O(numElem)
void IndexedList::inversList() {

    Node* current = head;
    Node* assist = nullptr;
    while(current != nullptr){
        assist = current->previous;
        current->previous = current->next;
        current->next = assist;
        current = current->previous;
    }
}