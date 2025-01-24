#include "PriorityQueue.h"
#include <exception>
#include <stdexcept>
using namespace std;


//Complexitate: theta(1)
PriorityQueue::PriorityQueue(Relation r) {
	//TODO - Implementation
    //inițializăm pointerii head și tail cu -1
    head = -1;
    tail = -1;
    //setăm firstEntry = -1
    firstEntry = -1;
    //inițializăm size cu 0 și capacity cu 10
    size = 0;
    capacity = 10;
    //alocăm memorie pentru array-ul de noduri
    nodes = new DLLANode[capacity];
    relation = r;
}


//Complexitate: WC = O(n), BC = O(1)
void PriorityQueue::push(TElem e, TPriority p) {
	//TODO - Implementation
    //verifică dacă array-ul are nevoie de resize, O(n)
    if (size == capacity) {
        resize();
    }

    //caută poziția corectă pentru a insera un element nou, O(n)
    int currentNode = firstEntry;
    int previousNode  = -1;
    while (currentNode != -1 && relation(nodes[currentNode].data.second, p)) {
        previousNode = currentNode;
        currentNode = nodes[currentNode].next;
    }

    //creează un nod nou, O(1)
    int newNodeIndex = size;
    nodes[newNodeIndex].data = make_pair(e, p);

    //actualizăm pointerii, O(1)
    if (currentNode == -1) {
        //inserăm la final
        if (previousNode == -1) {
            //lista e goală
            firstEntry = newNodeIndex;
            tail = newNodeIndex;
        } else {
            nodes[previousNode].next = newNodeIndex;
            nodes[newNodeIndex].previous = previousNode;
            tail = newNodeIndex;
        }
    } else {
        //inserează la mijloc sau la început
        if (previousNode == -1) {
            //inserează la început
            nodes[newNodeIndex].next = firstEntry;
            nodes[firstEntry].previous = newNodeIndex;
            firstEntry = newNodeIndex;
        } else {
            nodes[previousNode].next = newNodeIndex;
            nodes[newNodeIndex].previous = previousNode;
            nodes[newNodeIndex].next = currentNode;
            nodes[currentNode].previous = newNodeIndex;
        }
    }
    size++;
}


//Complexitate: O(1)
Element PriorityQueue::top() const {
	//TODO - Implementation
	if (isEmpty()) {
        throw std::runtime_error("Queue is empty");
    }
    return nodes[firstEntry].data;
}


//Complexitate: O(1)
Element PriorityQueue::pop() {
	//TODO - Implementation
    //O(1)
	if (isEmpty()) {
        throw std::runtime_error("Queue is empty");
    }

    Element element = nodes[firstEntry].data;
    int nextNode = nodes[firstEntry].next;

    //golește memoria nodului, O(1)
    if (nextNode != -1) {
        nodes[nextNode].previous = -1;
    }

    //mută primul entry pointer, O(1)
    firstEntry = nextNode;
    size--;

    if (isEmpty()) {
        tail = -1;
    }

    return element;
}


//Complexitate: O(1)
bool PriorityQueue::isEmpty() const {
	//TODO - Implementation
	return size == 0;
}


//Complexitate: O(n), n = size
void PriorityQueue::resize() {
    //dublăm capacitatea
    capacity *= 2;
    //alocăm memorie pentru array-ul resized
    DLLANode* resizeNodes = new DLLANode[capacity];
    //copiem elementele din array-ul vechi în cel nou
    for (int i = 0; i < size; i++) {
        resizeNodes[i] = nodes[i];
    }
    //golim memoria array-ului vechi
    delete[] nodes;
    //actualizăm pointerul să "pointeze" către array-ul resized
    nodes = resizeNodes;
}


//void PriorityQueue::intercalate(const PriorityQueue& q) {
//    PriorityQueue resultQueue(relation);
//
//    int currentNode1 = firstEntry;
//    int currentNode2 = q.firstEntry;
//
//    while (currentNode1 != -1 || currentNode2 != -1) {
//        if (currentNode1 != -1) {
//            resultQueue.push(nodes[currentNode1].data.first, nodes[currentNode1].data.second);
//            currentNode1 = nodes[currentNode1].next;
//        }
//        if (currentNode2 != -1) {
//            resultQueue.push(q.nodes[currentNode2].data.first, q.nodes[currentNode2].data.second);
//            currentNode2 = q.nodes[currentNode2].next;
//        }
//    }
//}


//Complexitate: O(1)
PriorityQueue::~PriorityQueue() {
	//TODO - Implementation
    //golim memoria alocată
    delete[] nodes;
}
