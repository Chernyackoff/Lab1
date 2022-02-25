#include "ProtectedQueue.hpp"

int ProtectedQueue::countAboveGap() const {
    if (length() == 0) {
        return 0;
    }

    int count = 0;
    int min, max;
    min = max = front();

    for (Node *curr = getHead()->next; curr != nullptr; curr = curr->next) {
        if (curr->value > max) {
            max = curr->value;
        }
        if (curr->value < min) {
            min = curr->value;
        }
    }

    int diff = max - min;
    for (Node *curr = getHead(); curr != nullptr; curr = curr->next) {
        if (curr->value > diff) {
            count++;
        }
    }

    return count;
}

int ProtectedQueue::front() const {
    return Queue::front();
}

void ProtectedQueue::dequeue() {
    return Queue::dequeue();
}

void ProtectedQueue::enqueue(int value) {
    Queue::enqueue(value);
}

int ProtectedQueue::length() const {
    return Queue::length();
}

Queue ProtectedQueue::copy() const {
    return Queue::copy();
}

Queue::Node *ProtectedQueue::getHead() const {
    return Queue::getHead();
}

Queue::Node *ProtectedQueue::getTail() const {
    return Queue::getTail();
}

ProtectedQueue& ProtectedQueue::operator=(const ProtectedQueue &queue) {
    while (amount) dequeue();
    for (Node *curr = queue.getHead(); curr != nullptr; curr = curr->next) enqueue(curr->value);
    return *this;
};