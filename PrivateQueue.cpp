#include "PrivateQueue.hpp"


int PrivateQueue::front() const {
    return Queue::front();
}

int PrivateQueue::length() const {
    return Queue::length();
}

void PrivateQueue::dequeue() {
    Queue::dequeue();
}

void PrivateQueue::enqueue(int value) {
    Queue::enqueue(value);
}

int PrivateQueue::countAboveGap() const {
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

Queue::Node *PrivateQueue::getHead() const {
    return Queue::getHead();
}

Queue::Node *PrivateQueue::getTail() const {
    return Queue::getTail();
}

Queue PrivateQueue::copy() const {
    return Queue::copy();
}

PrivateQueue& PrivateQueue::operator=(const PrivateQueue &queue) {
    while (amount) dequeue();
    for (Node *curr = queue.getHead(); curr != nullptr; curr = curr->next) enqueue(curr->value);
    return *this;
};