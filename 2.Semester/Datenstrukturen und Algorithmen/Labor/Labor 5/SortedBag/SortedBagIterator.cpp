#include "SortedBagIterator.h"
#include "SortedBag.h"
#include <exception>

using namespace std;

SortedBagIterator::SortedBagIterator(const SortedBag& b) : bag(b) {
    this->first();
}

TComp SortedBagIterator::getCurrent() {
    if (!this->valid()) {
        throw exception();
    }
    return this->currentNode->value;
}

bool SortedBagIterator::valid() {
    return this->currentNode != nullptr;
}

void SortedBagIterator::next() {
    if (!this->valid()) {
        throw exception();
    }
    if (this->currentNode->right != nullptr) {
        this->currentNode = this->currentNode->right;
        while (this->currentNode->left != nullptr) {
            this->currentNode = this->currentNode->left;
        }
    } else {
        SortedBag::BSTNode* parent = nullptr;
        SortedBag::BSTNode* root = this->bag.root;
        while (root != nullptr && root != this->currentNode) {
            if (this->bag.relation(this->currentNode->value, root->value)) {
                parent = root;
                root = root->left;
            } else {
                root = root->right;
            }
        }
        this->currentNode = parent;
    }
}

void SortedBagIterator::first() {
    this->currentNode = this->bag.root;
    while (this->currentNode != nullptr && this->currentNode->left != nullptr) {
        this->currentNode = this->currentNode->left;
    }
}
