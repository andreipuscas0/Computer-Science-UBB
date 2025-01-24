#include "ListIterator.h"
#include "IndexedList.h"
#include <exception>

//theta(1)
ListIterator::ListIterator(const IndexedList& list) : list(list) {
    //TODO - Implementation
    current = list.head;
}

//theta(1)
void ListIterator::first(){
    //TODO - Implementation
    current = list.head;
}

//theta(1)
void ListIterator::next(){
    //TODO - Implementation
    if(valid())
        current = current->next;
    else
        throw std::exception();

}

//theta(1)
bool ListIterator::valid() const{
    //TODO - Implementation
    if (current != nullptr)
        return true;
	return false;
}

//theta(1)
TElem ListIterator::getCurrent() const{
   //TODO - Implementation
   if (!valid())
       throw std::exception();
   return current->info;
}