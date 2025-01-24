#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <utility>

using TElem = int;
using TPriority = int;
using Element = std::pair<TElem, TPriority>;
using Relation = bool(*)(TPriority, TPriority);

class PriorityQueue {
private:
    struct Node {
        Element data;
        Node* next;
        Node* prev;
    };

    Node* head;
    Node* tail;
    Node* firstFree;
    int size;
    Relation relation;

    Node* allocateNode(const Element& data);
    void deallocateNode(Node* node);

public:
    PriorityQueue(Relation r);
    ~PriorityQueue();

    void push(TElem e, TPriority p);
    Element pop();
    bool isEmpty() const;
    Element top() const;
};

#endif // PRIORITYQUEUE_H
