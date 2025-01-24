#include "SortedBag.h"
#include "SortedBagIterator.h"

SortedBag::SortedBag(Relation r) {
    this->root = nullptr;
    this->relation = r;
    this->nrElements = 0;
}

void SortedBag::add(TComp e) {
    this->root = addRec(this->root, e);
    this->nrElements++;
}

SortedBag::BSTNode* SortedBag::addRec(BSTNode* node, TComp e) {
    if (node == nullptr) {
        node = new BSTNode{e, nullptr, nullptr, 1};
    } else if (this->relation(e, node->value)) {
        node->left = addRec(node->left, e);
    } else {
        node->right = addRec(node->right, e);
    }
    return node;
}

bool SortedBag::remove(TComp e) {
    bool removed = false;
    this->root = removeRec(this->root, e, removed);
    if (removed) {
        this->nrElements--;
    }
    return removed;
}

SortedBag::BSTNode* SortedBag::removeRec(BSTNode* node, TComp e, bool &removed) {
    if (node == nullptr) {
        return nullptr;
    }
    if (node->value == e) {
        removed = true;
        if (node->count > 1) {
            node->count--;
        } else {
            if (node->left == nullptr) {
                BSTNode* rightChild = node->right;
                delete node;
                return rightChild;
            } else if (node->right == nullptr) {
                BSTNode* leftChild = node->left;
                delete node;
                return leftChild;
            } else {
                BSTNode* minRight = findMin(node->right);
                node->value = minRight->value;
                node->count = minRight->count;
                minRight->count = 1;
                node->right = removeMin(node->right);
            }
        }
    } else if (this->relation(e, node->value)) {
        node->left = removeRec(node->left, e, removed);
    } else {
        node->right = removeRec(node->right, e, removed);
    }
    return node;
}

SortedBag::BSTNode* SortedBag::findMin(BSTNode* node) const {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

SortedBag::BSTNode* SortedBag::removeMin(BSTNode* node) {
    if (node->left == nullptr) {
        BSTNode* rightChild = node->right;
        delete node;
        return rightChild;
    }
    node->left = removeMin(node->left);
    return node;
}

bool SortedBag::search(TComp e) const {
    return searchRec(this->root, e);
}

bool SortedBag::searchRec(BSTNode* node, TComp e) const {
    if (node == nullptr) {
        return false;
    }
    if (node->value == e) {
        return true;
    } else if (this->relation(e, node->value)) {
        return searchRec(node->left, e);
    } else {
        return searchRec(node->right, e);
    }
}

int SortedBag::nrOccurrences(TComp e) const {
    return nrOccurrencesRec(this->root, e);
}

int SortedBag::nrOccurrencesRec(BSTNode* node, TComp e) const {
    if (node == nullptr) {
        return 0;
    }
    if (node->value == e) {
        return node->count;
    } else if (this->relation(e, node->value)) {
        return nrOccurrencesRec(node->left, e);
    } else {
        return nrOccurrencesRec(node->right, e);
    }
}

int SortedBag::size() const {
    return this->nrElements;
}

bool SortedBag::isEmpty() const {
    return this->nrElements == 0;
}

SortedBagIterator SortedBag::iterator() const {
    return SortedBagIterator(*this);
}

SortedBag::~SortedBag() {
    destroyTree(this->root);
}

void SortedBag::destroyTree(BSTNode* node) {
    if (node != nullptr) {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}
