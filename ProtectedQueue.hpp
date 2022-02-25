#ifndef PLAYGROUND_PROTECTEDQUEUE_HPP
#define PLAYGROUND_PROTECTEDQUEUE_HPP

#include "Queue.hpp"

class ProtectedQueue : protected Queue {
public:
    ProtectedQueue() = default;
    ProtectedQueue(const ProtectedQueue &queue) = default;
    ~ProtectedQueue() = default;

    ProtectedQueue &operator=(const ProtectedQueue &queue);

    int countAboveGap() const;

    int length() const;
    void enqueue(int value);
    void dequeue();
    int front() const;
    Queue copy() const;

    Node *getHead() const;
    Node *getTail() const;
};


#endif //PLAYGROUND_PROTECTEDQUEUE_HPP
