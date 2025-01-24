#include "Set.h"
#include "SetIterator.h"

//Complexitate: O(1)
Set::Set() {
	//TODO - Implementation
    capacity = 10;
    dinamic_array = new TElem[capacity];
    length = 0;
}

//Complexitate: theta(1) best case; theta(n) worst case
bool Set::add(TElem elem) {
	//TODO - Implementation
    if(!search(elem)) //Daca nu exista deja elementul
    {
        if(length == capacity) {
            capacity *= 2; //dubleaza
            TElem *array_nou = new TElem[capacity]; //array nou cu capacitate dubla
            for(int i = 0; i < length; ++i) {
                array_nou[i] = dinamic_array[i]; //copiaza elementele din dinamic array
            }
            delete[] dinamic_array; //goleste memoria ocupata de array-ul dinamic
            dinamic_array = array_nou; //actualizeaza pointerul
        }
        dinamic_array[length++] = elem; //adauga element nou si actualizeaza lungimea
        return true;
    }
	return false;
}


//Complexitate: theta(1) best case; theta(n) worst case
bool Set::remove(TElem elem) {
	//TODO - Implementation
    int index = -1;
    for(int i = 0; i < length; ++i) {
        if(dinamic_array[i] == elem) {
            index = i; //s-a gasit elementul cautat
            break;
        }
    }
    if(index == -1)
        return false;
    for(int i = index; i < length - 1; i++)
        dinamic_array[i] = dinamic_array[i + 1]; //muta elementele la stanga

    length--;
	return true;
}


//Complexitate: theta(1) best case; theta(n) worst case
bool Set::search(TElem elem) const {
	//TODO - Implementation
    for (int i = 0; i < length; ++i){
        if(dinamic_array[i] == elem) {
            return true;
        }
    }
	return false;
}


//Complexitate: theta(1)
int Set::size() const {
	//TODO - Implementation
    return length;
}


//Complexitate: theta(1)
bool Set::isEmpty() const {
	//TODO - Implementation
	return length == 0;
}


Set::~Set() {
	//TODO - Implementation
    delete[] dinamic_array;
}


SetIterator Set::iterator() const {
	return SetIterator(*this);
}


