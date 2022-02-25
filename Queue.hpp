#ifndef PLAYGROUND_QUEUE_HPP
#define PLAYGROUND_QUEUE_HPP


class Queue {
public:
    Queue();
    Queue(const Queue &queue);  // implicit copy constructor
    ~Queue();

    void enqueue(int value);
    void dequeue();

    int front() const;
    int length() const;

    Queue copy() const;

    template <typename T>
    friend T merge(const T &a, const T &b);

    struct Node {
        int value;
        Node* next;
    };

    Node* getHead() const;
    Node* getTail() const;

protected:
    int amount;

private:
    Node *head_, *tail_;
};


#endif //PLAYGROUND_QUEUE_HPP
