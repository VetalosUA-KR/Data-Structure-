#ifndef Queue_H
#define Queue_H

struct Queue
{

private:

    struct Node
    {
        int value;
        Node* next;
        Node(int v, Node* n = nullptr)
        {
            value = v;
            next = n;
        }
    };

    Node* head = nullptr;
    Node* tail = nullptr;
    int counter = 0;

    //invariants:
    //if nonempty, head points to the first node (it contains the first value)
    //if nonempty, tail points to the last node (it contains the last value)
    //tail is null if and only if head is null (empty queue)
    //the next for the first node points to the second node, etc.
    //the next for the last node is null
    //counter is at least 0 (empty queue) and it is the number of nodes (size of the queue)

public:

    //constructors

    Queue() = default;
    //pre: none
    //post: the queue is empty

    Queue(const Queue&);
    //pre: none
    //post: the queue is the copy of the argument

    //destructor

    ~Queue();
    //pre: none
    //post: none

    //modifiers

    void push(int val);
    //pre: none
    //post: the argument value is the last, size is increased by 1

    int pop();
    //pre: the queue is not empty
    //post: the first value is removed, size is decreased by 1
    //return: the first value

    void clear();
    //pre: none
    //post: the queue is empty

    //selectors

    int front() const;
    //pre: the queue is not empty
    //return: the first value

    int back() const;
    //pre: the queue is not empty
    //return: the last value

    int size() const;
    //pre: none
    //return: the current size of the queue

    void print() const;
    //pre: none
    //return: none, the contents of the queue is printed, from first to last

    //queries

    bool empty() const;
    //pre: none
    //return: true if the queue is empty, false otherwise

    //operators

    Queue& operator=(const Queue&);
    //pre: none
    //post: the queue is the copy of the argument
    //return: the reference to the queue

    bool operator==(const Queue&) const;
    //pre: none
    //return: true if the contents of the queue is the same as the contents of the argument, false otherwise

};

#endif
