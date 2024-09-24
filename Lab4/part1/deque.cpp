#include <iostream>
#include "deque.h"

Deque::Node::Node(int cVal) {
    val = cVal;
    nextNode = nullptr;
    previousNode = nullptr;
}

Deque::Deque() {
    topOfQueue = nullptr;
    bottomOfQueue = nullptr;
}

Deque::Node *Deque::getTopOfQueue() {
    return topOfQueue;
}

Deque::Node *Deque::getBottomOfQueue() {
    return bottomOfQueue;
}

void Deque::setTopOfQueue(Node *n) {
    topOfQueue = n;
}

void Deque::setBottomOfQueue(Node *n) {
    bottomOfQueue = n;
}

void Deque::push_front(int i) {
    Node *newNode = new Node(i);
    newNode->nextNode = topOfQueue;
    if (topOfQueue != nullptr) {
        topOfQueue->previousNode = newNode;
    }
    else {
        bottomOfQueue = newNode;
    }
    topOfQueue = newNode;
}

void Deque::push_back(int i) {
    Node *newNode = new Node(i);
    newNode->previousNode = bottomOfQueue;
    if (bottomOfQueue != nullptr) {
        bottomOfQueue->nextNode = newNode;
    }
    else {
        topOfQueue = newNode;
    }
    bottomOfQueue = newNode;
}

int Deque::pop_front() {
    if (topOfQueue == nullptr) {
            std::cout << "Error: Tried popping an empty queue\n";
            return 0;
    }

    int val = topOfQueue->val;
    Node *ptrNewTop = topOfQueue->nextNode;
    delete topOfQueue;
    topOfQueue = ptrNewTop;
    if (topOfQueue != nullptr) {
        topOfQueue->previousNode = nullptr;
    }
    else {
        bottomOfQueue = nullptr;
    }
    return val;
}

int Deque::pop_back() {
    if (bottomOfQueue == nullptr) {
        std::cout << "Error: Tried popping an empty queue\n";
            return 0;
    }

    int val = bottomOfQueue->val;
    Node *ptrNewBottom = bottomOfQueue->previousNode;
    delete bottomOfQueue;
    bottomOfQueue = ptrNewBottom;
    if (bottomOfQueue != nullptr) {
        bottomOfQueue->nextNode = nullptr;
    }
    else {
        topOfQueue = nullptr;
    }
    return val;
}

int Deque::peak_front() {
    if (topOfQueue != nullptr) {
        return topOfQueue->val;
    }
    std::cout << "Error: Queue is empty\n";
    return 0;
}

int Deque::peak_back() {
    if (bottomOfQueue != nullptr) {
        return bottomOfQueue->val;
    }
    std::cout << "Error: Queue is empty\n";
    return 0;
}

void Deque::remove_all() {
    while(getTopOfQueue() != nullptr) {
        pop_front();
    } 
}

Deque::~Deque() {
    remove_all();
}
