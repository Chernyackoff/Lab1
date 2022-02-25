#ifndef PLAYGROUND_PRIVATEQUEUE_HPP
#define PLAYGROUND_PRIVATEQUEUE_HPP

#include "Queue.hpp"

class PrivateQueue : private Queue {
public:
    PrivateQueue() = default;
    PrivateQueue(const PrivateQueue &queue) = default;
    ~PrivateQueue() = default;

    PrivateQueue &operator=(const PrivateQueue &queue);

    void enqueue(int value);
    void dequeue();
    int length() const;
    int front() const;
    Queue copy() const;

    Node *getHead() const;
    Node *getTail() const;

    int countAboveGap() const;
};


#endif //PLAYGROUND_PRIVATEQUEUE_HPP
