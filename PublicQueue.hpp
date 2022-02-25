#ifndef PLAYGROUND_PUBLICQUEUE_HPP
#define PLAYGROUND_PUBLICQUEUE_HPP

#include "Queue.hpp"

class PublicQueue : public Queue {
public:
    PublicQueue() = default;

    PublicQueue(const PublicQueue &queue) = default;

    PublicQueue &operator=(const PublicQueue &queue);

    ~PublicQueue() = default;


    int countAboveGap() const;

    Queue copy() const;
};


#endif //PLAYGROUND_PUBLICQUEUE_HPP
