#include <exception>
#include "Queue.hpp"

Queue::Queue() {
    head_ = nullptr;
    tail_ = nullptr;
    amount = 0;
}

Queue::Queue(const Queue &queue) : Queue() {
    for (Node *curr = queue.head_; curr != nullptr; curr = curr->next) {
        enqueue(curr->value);
    }
}

Queue::~Queue() {
    while (amount) dequeue();
}

Queue Queue::copy() const {
    return *this;
}

int Queue::length() const {
    return amount;
}

void Queue::enqueue(int value) {
    auto *temp = new Node{value, nullptr};
    if (head_ == nullptr) {
        head_ = temp;
    } else {
        tail_->next = temp;
    }
    tail_ = temp;

    amount++;
}

void Queue::dequeue() {
    auto removed = head_;
    head_ = head_->next;
    if (head_ == nullptr) {
        tail_ = nullptr;
    }
    delete removed;

    amount--;
}

int Queue::front() const {
    if (amount <= 0) {
        throw std::exception("Empty queue");
    }

    return head_->value;
}

Queue::Node *Queue::getHead() const {
    return head_;
}

Queue::Node *Queue::getTail() const {
    return tail_;
}
