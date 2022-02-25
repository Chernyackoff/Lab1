#include "PublicQueue.hpp"

int PublicQueue::countAboveGap() const {
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

Queue PublicQueue::copy() const {
    return Queue::copy();
}

PublicQueue& PublicQueue::operator=(const PublicQueue &queue) {
    while (amount) dequeue();
    for (Node *curr = queue.getHead(); curr != nullptr; curr = curr->next) enqueue(curr->value);
    return *this;
};